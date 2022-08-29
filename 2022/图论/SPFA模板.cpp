#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#define ll long long
#define inf 0x7fffffff
using namespace std;
const int maxn = 10010, maxm = 5e5 + 7;
int n,m,fst[maxn],to[maxm],nxt[maxm],tot,vis[maxn],cnt[maxn];
ll val[maxm],dis[maxn];
void add_egde(int x, int y, ll v){
    to[++tot] = y;
    val[tot] = v;
    nxt[tot] = fst[x];
    fst[x] = tot;
    return ;
}
void SPFA(int s){
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
                    vis[v] = 1;
                    cnt[v] ++;
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    memset(fst,-1,sizeof fst);
    int s;
    scanf("%d%d%d",&n,&m,&s);
    for (int i = 1; i <= m; i ++){
        int x, y;ll v;
        scanf("%d%d%lld",&x,&y,&v);
        add_egde(x,y,v);
    }
    SPFA(s);
    for (int i = 1; i <= n; i ++){
        printf("%lld ",dis[i]);
    }
    return 0;
}