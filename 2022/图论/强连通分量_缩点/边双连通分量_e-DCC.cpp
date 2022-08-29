/*
算法重现:
通过Tarjan算法找出所有的割边，删除割边，然后扫描连通块，每个连通块都是一个边双联通分量。

注意！！有重边
用异或法找判断反向边下表应从2开始，即初始化tot为0
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 5e5 + 7, maxm = 2e6 + 7;
int n,m,bcc;
int fst[maxn],to[2*maxm],nxt[2*maxm],tot = 1;
bool bridge[2*maxm],vis[maxn];
void add_edge(int v, int u){
    to[++tot] = u;
    nxt[tot] = fst[v];
    fst[v] = tot;
    return ;
}
int cnt = 0,dfn[maxn],low[maxn];
vector<int> ans[maxn];
void Tarjan(int x,int in_e){
    dfn[x] = low[x] = ++cnt;
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(i == (in_e^1)) continue;
        if(!dfn[v]){
            Tarjan(v,i);
            low[x] = min(low[x],low[v]);
            if(low[v] > dfn[x]){
                bridge[i] = bridge[i ^ 1] = true;
            }
        }
        else {
            low[x] = min(low[x],dfn[v]);
        }
    }
}
void dfs(int x){
    if(vis[x]) return ;
    vis[x] = true;
    ans[bcc].push_back(x);
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(bridge[i]) continue;
        dfs(v);
    }
    return ;
}
int main(){
    memset(fst, -1, sizeof fst);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v); add_edge(v,u);
    }
    for (int i = 1; i <= n; i ++){
        if(!dfn[i]){
            Tarjan(i,0);
        }
    }
    for (int i = 1; i <= n; i ++){
        if(!vis[i]){
            bcc++;
            dfs(i);
        }
    }
    printf("%d\n",bcc);
    for (int i = 1; i <= bcc; i ++){
        printf("%d ", int(ans[i].size()));
        for (int j = 0; j < ans[i].size(); j ++){
            printf("%d ",ans[i][j]);
        }
        puts("");
    }

    return 0;
}