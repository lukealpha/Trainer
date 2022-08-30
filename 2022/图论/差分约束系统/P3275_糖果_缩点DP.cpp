
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 200010, maxm = 400010;
int n,m,fst[maxn],to[maxm],nxt[maxm],tot=1;
int dfn[maxn],low[maxn],s[maxn],col[maxn],sz[maxn],cnt,scc,top;
int deg[maxn],ind[maxn],idx,op_cnt;
ll val[maxn],dp[maxn];
bool instack[maxn];
struct op{
    int a,b,c;
}opts[maxm];
void add_edge(int x, int y,ll v){
    to[++tot] = y;
    nxt[tot] = fst[x];
    val[tot] = v;
    fst[x] = tot;
    return ;
}
void Tarjan(int x){
    dfn[x] = low[x] = ++ cnt;
    s[++top] = x;
    instack[x] = true;
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(!dfn[v]){
            Tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(instack[v]){
            low[x] = min(low[x],dfn[v]);
        }
    }
    if(dfn[x] == low[x]){
        scc++;
        while(s[top] != x){
            int z = s[top --];
            instack[z] = false;
            col[z] = scc;
            sz[col[z]] ++;
        }
        top --;
        col[x] = scc;
        instack[x] = false;
        sz[col[x]] ++;
    }
}
void topo(){
    queue<int> q; 
    for (int i = n + 1; i <= scc; i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        ind[++idx] = now;
        for (int i = fst[now]; i != -1; i = nxt[i]){
            int v = to[i];
            if(deg[v]){
                deg[v] --;
                if(deg[v] == 0) q.push(v);
            }
        }
    }
    return ;
}
int main(){
    //freopen("candy6.in","r",stdin);
    memset(fst,-1,sizeof fst);
    scanf("%d%d",&n,&m);scc = n;
    for (int i = 1; i <= m; i ++){
        int opt,a,b;
        scanf("%d%d%d",&opt,&a,&b);
        if(opt == 1){
            add_edge(a,b,0);
            add_edge(b,a,0);
        }
        if(opt == 2){
            opts[++op_cnt] = op{a,b,1};
        }
        if(opt == 3){
            add_edge(b,a,0);
        }
        if(opt == 4){
            opts[++op_cnt] = op{b,a,1};
        }
        if(opt == 5){
            add_edge(a,b,0);
        }
    }
    for (int i = 1; i <= n; i ++){
        if(!dfn[i]){
            Tarjan(i);
        }
    }
    for (int i = 1;i <= n; i ++){
        for (int j = fst[i]; j != -1; j = nxt[j]){
            int v = to[j];
            if(col[i] != col[v]){
                add_edge(col[i], col[v],val[j]);deg[col[v]] ++;
            }
        }
    }
    for (int i = 1; i <= op_cnt; i ++){
        if(col[opts[i].a] == col[opts[i].b]){
            printf("-1");
            return 0;
        }
        else{
            add_edge(col[opts[i].a],col[opts[i].b],opts[i].c);
            deg[col[opts[i].b]] ++;
        }
    }
    ++scc;
    for (int i = n + 1; i < scc; i ++){
        add_edge(scc,i,0);deg[i] ++;
    }
    topo();
    /*
    for (int i = n + 1; i <= scc; i ++){
        for (int j = fst[i]; j != -1; j = nxt[j]){
            printf("%d -> %d = %lld\n",i,to[j],val[j]);
        }
    }
    */
    for (int i = 1; i <= idx; i ++){
        for (int j = fst[ind[i]]; j != -1; j = nxt[j]){
            int v = to[j];
            dp[v] = max(dp[v],dp[ind[i]] + val[j]);
        }
    }
    if(idx == scc - n){
        ll ans = 0;
        for (int i = 1; i <= idx; i ++){
            ans += dp[ind[i]] * sz[ind[i]];
        }
        printf("%lld",ans + n);
    }
    else printf("-1");
    
    return 0;
}