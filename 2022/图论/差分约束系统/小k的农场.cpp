#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define inf 0x7fffffff
#define ll long long
using namespace std;
const int maxn = 5050, maxm = 10010;
int n,m;
int fst[maxn],to[maxm],nxt[maxm],tot,vis[maxn],cnt[maxn];
ll val[maxm],dis[maxn];
void add_edge(int x, int y, ll v){
    to[++tot] = y;
    val[tot] = v;
    nxt[tot] = fst[x];
    fst[x] = tot;
    return ;
}
bool SPFA(int s){
    for(int i=1; i<=n; i++) dis[i] = inf;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        int now = q.front();
        
        q.pop();
        vis[now] = 0;
        for (int i = fst[now]; i != -1; i = nxt[i]){
            int v = to[i];
            if(dis[now] + val[i] < dis[v]){
                dis[v] = dis[now] + val[i];
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                    cnt[v] ++;
                    if(cnt[now] >= n + 1){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    memset(fst,-1,sizeof fst);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int opt,a,b;ll c;
        scanf("%d",&opt);
        if(opt == 1){
            scanf("%d%d%lld",&a,&b,&c);
            add_edge(a,b,-c);
        }
        if(opt == 2){
            scanf("%d%d%lld",&a,&b,&c);
            add_edge(b,a,c);
        }
        if(opt == 3){
            scanf("%d%d",&a,&b);
            add_edge(a,b,0);
            add_edge(a,b,0);
        }
    }
    for (int i = 1; i <= n; i ++){
        add_edge(n+1,i,0);
    }
    if(SPFA(n+1)) printf("Yes");
    else printf("No");
    return 0;
}