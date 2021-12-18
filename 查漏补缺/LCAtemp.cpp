#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 500010;

vector<int> e[maxn];
int f[maxn][25], dep[maxn];
void add_edge(int x, int y){
    e[x].push_back(y);
    e[y].push_back(x);
    return ;
}
void init(int u, int fat){
    dep[u] = dep[fat] + 1;
    for (int i = 1; i <= 20; i ++){
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = 0; i < e[u].size(); i ++){
        int y = e[u][i];
        if(y == fat){
            continue;
        }
        f[y][0] = u;
        init(y,u);
    }
    return ;
}
int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x,y);
    for (int i = 20; i >= 0; i --){
        if(dep[f[x][i]] >= dep[y]){
            x = f[x][i];
        }
        if(x == y){
            return x;
        }
    }
    for (int i = 20; i >= 0; i --){
        if(f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int main(){
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    for (int i = 1; i <= n - 1; i ++){
        int x, y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    init(s,0);
    for (int i = 1; i <= m; i ++){
        int x, y;
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}