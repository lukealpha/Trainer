#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 4e5 + 7;
int n,k;
int fst[maxn],to[maxn*2],nxt[maxn*2],deg[maxn],seq[maxn],tot=1;
bool vis[maxn];
void add_egde(int u,int v){
    to[++tot] = v;
    nxt[tot] = fst[u];
    fst[u] = tot;
}
void topo(){
    queue<int> q;
    for (int i = 1; i <= n; i ++){
        if(deg[i] == 1){
            q.push(i);
            seq[i] = 1;
            vis[i] = true;
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = fst[now]; i != -1; i = nxt[i]){
            int v = to[i];
            if(vis[v]) continue;
            if(deg[v] > 1) deg[v] --;
            if(deg[v] == 1){
                q.push(v);
                seq[v] = seq[now] + 1;
                vis[v] = true;
            }
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(fst,-1,sizeof fst);
        memset(deg,0,sizeof deg);
        memset(vis,0,sizeof vis);
        memset(seq,0,sizeof seq);
        tot = 1;
        scanf("%d%d",&n,&k);
        for (int i = 1; i <= n - 1; i ++){
            int u,v;
            scanf("%d%d",&u,&v);
            add_egde(u,v);
            add_egde(v,u);
            deg[u] ++, deg[v] ++;
        }
        topo();
        int ans = 0;
        for (int i = 1; i <= n; i ++){
            if(seq[i] > k){
                ans ++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}