#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 220;
ll w[maxn],sz[maxn];
int fst[maxn],to[maxn],nxt[maxn],tot=1,n;
void add_edge(int u, int v){
    to[++tot] = v;
    nxt[tot] = fst[u];
    fst[u] = tot;
}
int med; ll minw = 0x3f3f3f3f, sum = 0;
void dfs(int x,int fa){
    sz[x] = w[x];
    ll tmp = -1, up_sz = sum - w[x];
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        dfs(v,x);
        sz[x] += sz[v];
        tmp = max(tmp,sz[v]);
        up_sz -= sz[v];
    }
    tmp = max(tmp,up_sz);
    if(tmp < minw){
        minw = tmp;
        med = x;
    }
}
ll ans = 0;
void dfs2(int x, int step, int fa){
    ans += w[x]*step;
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        dfs2(v,step + 1,x);
    }
}
int main(){
    memset(fst, -1,sizeof fst);

    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        int a,b;
        scanf("%lld%d%d",&w[i],&a,&b);
        sum += w[i];
        if(a != 0){
            add_edge(i,a);
            add_edge(a,i);
        }
        if(b != 0){
            add_edge(i,b);
            add_edge(b,i);
        }
    }
    dfs(1,0);
    dfs2(med,0,0);
    printf("%lld",ans);
    return 0;
}