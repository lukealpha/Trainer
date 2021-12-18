#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 10005;
int n, m, cnt, edge_cnt, group_cnt, head[N], ingroup[N], idx;
int dfn[N], low[N];
bool instack[N];
stack<int> g;

struct edge{
    int to, nxt;
} e[N];

void addedge(int from, int to){
    e[++edge_cnt] = edge{to, head[from]};
    head[from] = edge_cnt;
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
            ingroup[v] = group_cnt;
        }while(u != v);
    }

}

int main(){
    memset(head,-1,sizeof head);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int from, to ;
        scanf("%d%d",&from,&to);
        addedge(from, to);
    }
    for (int i = 1; i <= n; i ++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    cout<<endl<<endl;
    for (int i = 1; i <= n; i ++){
        cout<<dfn[i] <<' '<<low[i] << endl;
    }
    cout << "total : " << group_cnt << endl;
    for (int i = 1; i <= group_cnt; i ++){
        for (int j = 1; j <= n; j ++){
            if(ingroup[j] == i){
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

/*
Sample:

6 8
1 2
1 3
2 4
3 4
3 5
4 1
4 6
5 6
*/