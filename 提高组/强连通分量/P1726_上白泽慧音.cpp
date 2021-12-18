#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 5010;
const int M = 50100;

int n, m, cnt, edge_cnt, group_cnt, head[N],idx;
int dfn[N], low[N];
bool instack[N];
stack<int> g;

struct group{
    int cnt = 0;
    int p[N];
}ingroup[N];

struct edge{
    int to, nxt;
} e[M];

void addedge(int from, int to){
    e[++edge_cnt] = edge{to, head[from]};
    head[from] = edge_cnt;
}
bool cmp_cap(group a, group b){
    return a.cnt > b.cnt;
}
bool cmp_dict(group a, group b){
    return a.p[1] < b.p[1];
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
            sort(ingroup[group_cnt].p + 1, ingroup[group_cnt].p + ingroup[group_cnt].cnt + 1);
        }while(u != v);
    }

}

void init(){
    memset(head, -1, sizeof head);
}

int main(){
    init();
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int from, to, type;
        scanf("%d%d%d",&from, &to, &type);
        addedge(from, to);
        if(type == 2){
            addedge(to, from);
        }
    }
    for (int i = 1; i <= n; i ++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    sort(ingroup + 1, ingroup + group_cnt + 1,cmp_cap);
    int max_cnt = 1;
    for (int i = 2; i <= group_cnt; i ++){
        if(ingroup[i].cnt == ingroup[1].cnt){
            max_cnt ++;
        }
        else{
            break;
        }
    }
    sort(ingroup + 1,ingroup + max_cnt + 1, cmp_dict);
    printf("%d\n",ingroup[1].cnt);
    for (int i = 1; i <= ingroup[1].cnt; i ++){
        printf("%d ",ingroup[1].p[i]);
    }

}