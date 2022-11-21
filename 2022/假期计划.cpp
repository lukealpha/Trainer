#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 2600, maxm = 20010;
int fst[maxn],nxt[maxm],to[maxm],tot=1,dis[maxn][maxn];
ll s[maxn];
vector<int> f[maxn];
bool vis[maxn];
void add_edge(int u, int v){
    to[++tot] = v;
    nxt[tot] = fst[u];
    fst[u] = tot;
    return ;
}
bool cmp(int a, int b){
    return s[a] > s[b];
}
int n,m,k;
void bfs(int x){
    memset(vis,0,sizeof vis);
    dis[x][x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(vis[now]) continue;
        vis[now] = true;
        if(x != 1 && now != x && now != 1&& dis[x][now] <= k + 1 && dis[1][now] <= k + 1){
            f[x].push_back(now);
            sort(f[x].begin(),f[x].end(),cmp);
            if(f[x].size() > 3) f[x].pop_back();
        }
        if(dis[x][now] > k) continue;
        for (int i = fst[now]; i != -1; i = nxt[i]){
            int v = to[i];
            if(!vis[v] && dis[x][now] + 1 < dis[x][v]){
                dis[x][v] = dis[x][now] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    memset(dis,0x3f,sizeof dis);
    memset(fst,-1,sizeof fst);
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 2; i <= n; i ++){
        scanf("%lld",&s[i]);
    }
    for (int i = 1; i <= m; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for (int i = 1; i <= n; i ++){
        bfs(i);
    }
    ll ans = 0;
    for (int i = 2; i <= n; i ++){
        for (int j = 2; j <= n; j ++){
            if(dis[i][j] > k + 1) continue;
            for (int a:f[i]){
                for (int b:f[j]){
                    if(i != j && i != b && j != a && a != b){
                        ans = max(ans,s[i] + s[j] + s[a] + s[b]);
                    }
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}