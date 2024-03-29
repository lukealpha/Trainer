/* 
Tarjan强连通分量算法和Tarjan割边割点算法有一定的不同，不要混淆。
Tarjan栈中的都是还未确定缩成点的元素，一旦缩成点出栈，就不可能再对其它节点的low值有贡献
这就是为什么Tarjan强连通分量算法需要动态维护栈，dfn不能代替stack状态
换句话说，没有stack维护，那么简单通过dfn判断返祖，可能返回的不是自己的祖先

至于求割边割点算法，由于是无向图，所以只要能返回祖先即可更新
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 20010, maxm = 200020;
int n,m,fst[maxn],to[maxm],nxt[maxm],tot=1;
int dfn[maxn],low[maxn],s[maxn],col[maxn],cnt,scc,top;
int deg[maxn],ind[maxn],idx;
ll dp[maxn],a[maxn];
bool instack[maxn];
map<pair<int,int>,bool> E;
void add_edge(int x, int y){
    to[++tot] = y;
    nxt[tot] = fst[x];
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
            a[col[z]] += a[z];
        }
        top --;
        col[x] = scc;
        a[col[x]] += a[x];
        instack[x] = false;
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
    memset(fst,-1,sizeof fst);
    scanf("%d%d",&n,&m);scc = n;
    for (int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    for (int i = 1; i <= m; i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    for (int i = 1; i <= n; i ++){
        if(!dfn[i]){
            Tarjan(i);
        }
    }
    for (int i = 1;i <= n; i ++){
        for (int j = fst[i]; j != -1; j = nxt[j]){
            int v = to[j];
            if(col[i] != col[v] && E[make_pair(col[i],col[v])] != true){
                E[make_pair(col[i],col[v])] = true;
                add_edge(col[i], col[v]);deg[col[v]] ++;
            }
        }
    }
    topo();
    ll ans = 0;
    for (int i = 1; i <= idx; i ++){
        dp[ind[i]] += a[ind[i]];
        ans = max(ans,dp[ind[i]]);
        for (int j = fst[ind[i]]; j != -1; j = nxt[j]){
            dp[to[j]] = max(dp[to[j]],dp[ind[i]]);
        }
    }
    printf("%lld",ans);
    return 0;
}