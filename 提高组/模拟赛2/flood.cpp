//改范围

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 400010;
const int maxm = 200010;
struct node{
    int from, to;
}connection[maxm];
int n, m, k, mcnt, fa[maxn], comp[maxm], totcomp, knode[maxn];
bool invalid_node[maxn];
vector<node> g[maxn];
void init(){
    for (int i = 0; i <= n - 1; i ++){
        fa[i] = i;
    }
    totcomp = n - k;
}
int find(int x){
    if(fa[x] == x){
        return x;
    }
    else{
        return fa[x] = find(fa[x]);
    }
}
void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        fa[fx] = fy;
    }
}
int main(){
    freopen("flood.in","r",stdin);
    freopen("flood.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        connection[++mcnt].from = x;
        connection[mcnt].to = y;
        g[x].push_back(node{x,y});
        g[y].push_back(node{y,x});
    }
    scanf("%d",&k);
    for (int i = 1; i <= k; i ++){
        int x;
        scanf("%d",&x);
        invalid_node[x] = 1;
        knode[i] = x;
    }
    init();
    for (int i = 1; i <= m; i ++){
        if((!invalid_node[connection[i].from]) && (!invalid_node[connection[i].to])){
            if(find(connection[i].from) != find(connection[i].to)){
                merge(connection[i].from, connection[i].to);
                totcomp --;
            }
            
        }
    }
    comp[k + 1] = totcomp;
    for (int i = k; i >= 1; i --){
        invalid_node[knode[i]] = 0;
        totcomp ++;
        for (int j = 0; j < g[knode[i]].size(); j ++){
            if(find(g[knode[i]][j].to) != find(g[knode[i]][j].from) && (!invalid_node[g[knode[i]][j].to]) &&(!invalid_node[g[knode[i]][j].from])){
                merge(g[knode[i]][j].to,g[knode[i]][j].from);
                totcomp --;
            }
        }
        comp[i] = totcomp;
    }
    for (int i = 1; i <= k + 1; i ++){
        printf("%d\n",comp[i]);
    }
    return 0;
}