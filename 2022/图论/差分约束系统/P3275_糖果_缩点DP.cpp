#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define inf 0x7fffffff
#define ll long long
using namespace std;
const int maxn = 100010, maxm = 400010;
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
    return 0;
}