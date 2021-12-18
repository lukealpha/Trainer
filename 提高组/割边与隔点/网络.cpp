// #10100. 「一本通 3.6 练习 1」网络 (割点模板)
// https://loj.ac/p/10100

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int N = 20010;
const int M = 200020;
int n, edge_cnt, cut_cnt, head[N], idx, fa;
int dfn[N], low[N];
bool cut[N];
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
bool input_edge(){
    char buffer[10000];
    char *pbuff;
    int value;
    int from;
    cin >> from;
    if(from == 0){
        return 0;
    }
    fgets(buffer, sizeof buffer, stdin);
    pbuff = buffer;
    while (1){
        if (*pbuff == '\n')
            break;
        value = strtol(pbuff, &pbuff, 10);
        addedge(from, value);
        addedge(value, from);
    }
    return 1;
}

void init(){
    memset(head, -1, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(cut, 0, sizeof cut);
    idx = cut_cnt = edge_cnt = 0;
}

int main(){

    int n;
    while(cin >> n && n != 0){
        init();
        while(input_edge());
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
    }
    
    
    return 0;
}