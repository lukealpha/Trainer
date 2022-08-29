#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define inf 0x7fffffff
#define ll long long
using namespace std;
const int maxn = 100010, maxm = 200010;
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
    memset(dis,-1,sizeof dis);
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
            if(dis[now] + val[i] > dis[v]){
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
        int opt,a,b;
        scanf("%d%d%d",&opt,&a,&b);
        if(opt == 1){
            add_edge(a,b,0);
            add_edge(b,a,0);
        }
        if(opt == 2){
            add_edge(a,b,1);
        }
        if(opt == 3){
            add_edge(b,a,0);
        }
        if(opt == 4){
            add_edge(b,a,1);
        }
        if(opt == 5){
            add_edge(a,b,0);
        }
    }
    for (int i = 1; i <= n; i ++){
        add_edge(n+1,i,0);
    }
    if(SPFA(n+1)){
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            ans += dis[i];
        }
        printf("%lld",ans);
    }
    else printf("No");
    return 0;
}