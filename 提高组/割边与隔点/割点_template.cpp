//P3388 【模板】割点（割顶）
//https://www.luogu.com.cn/problem/P3388

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int N = 20010;
const int M = 200020;
int n, m, cnt, edge_cnt, cut_cnt, head[N], ingroup[N], idx, fa;
int dfn[N], low[N];
bool instack[N],cut[N];
stack<int> g;

struct edge{
    int to, nxt;
} e[M];

void addedge(int from, int to){
    e[++edge_cnt] = edge{to, head[from]};
    head[from] = edge_cnt;
}

void tarjan(int u){
    int v;
    dfn[u] = low[u] = ++ idx;
    int col = 0;
    for (int i = head[u]; i != -1; i = e[i].nxt){
        v = e[i].to;
        if(!dfn[v]){
            col ++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if((u == fa && col > 1) || (u != fa&&dfn[u] <= low[v])){
                cut[u] = 1;
            }
        }
        else{
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main(){
    memset(head,-1,sizeof head);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int from, to ;
        scanf("%d%d",&from,&to);
        addedge(from, to);
        addedge(to, from);
    }
    for (int i = 1; i <= n; i ++){
        if(!dfn[i]){
            fa = i;
            tarjan(i);
        }
    }
    for (int i = 1; i <= n;i ++){
        if(cut[i]){
            cut_cnt ++;
        }
    }
    printf("%d\n",cut_cnt);
    for (int i = 1; i <= n;i ++){
        if(cut[i]){
            printf("%d ",i);
        }
    }
    
    return 0;
}