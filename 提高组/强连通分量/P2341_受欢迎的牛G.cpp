//P2341 [USACO03FALL][HAOI2006]受欢迎的牛 G
//https://www.luogu.com.cn/problem/P2341
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 10010;
const int M = 50010;

int n, m, cnt, edge_cnt, group_cnt, head[N], idx;
int dfn[N], low[N];
bool instack[N];
stack<int> g;

struct group{
    int cnt = 0;
    int p[N];
}ingroup[N];

int mygroup[N];

struct edge{
    int to, nxt;
} e[M];

void addedge(int from, int to){
    e[++edge_cnt] = edge{to, head[from]};
    head[from] = edge_cnt;
}

void init(){
    memset(head, -1, sizeof head);
}

void tarjan(int u){
    int v;
    dfn[u] = low[u] = ++ idx;
    g.push(u);
    instack[u] = 1;
    for (int i = head[u]; i != -1; i = e[i].nxt){
        v = e[i].to;
        if(instack[v]){
            low[u] = min(low[u], dfn[v]);
        }
        else if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(dfn[u] == low[u]){
        group_cnt ++;
        do{
            v = g.top();
            g.pop();
            instack[v] = 0;
            ingroup[group_cnt].p[++ingroup[group_cnt].cnt] = v;
        }while(u != v);
    }

}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int from ,to;
        scanf("%d%d",&from,&to);
        addedge(from,to);
    }
    for (int i = 1; i <= n; i ++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    int ex0_cnt = 0;
    for(int i = 1; i <= group_cnt; i ++){
        for (int j = 1; j <= ingroup[group_cnt].cnt; i ++){
            for (int k = head[ingroup[group_cnt].p[j]]; k != -1; k = e[k].nxt){
                
            }
            
        }
    }
    return 0;
}