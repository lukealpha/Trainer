#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1010;
const int INF =  2 * 1e9;
long long g[1010][1010];
struct edge{
    int u,v,val;
}e[2020];
int main(){
    freopen("pencil.in","r",stdin);
    freopen("pencil.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n;j ++){
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i ++){
        int u,v,val;
        scanf("%d%d%d",&u,&v,&val);
        g[u][v] = val;
        g[v][u] = val;
        e[i] = edge{u,v,val};
    }
    for (int k = 1; k <= n; k ++){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                if(g[i][k] + g[j][k] < g[i][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++){
        printf("%lld\n",g[1][i] +g[i][n]);
    }
    for (int i = 1; i <= m; i ++){
        printf("%lld\n",g[1][e[i].u] + g[e[i].v][n] + (long long)e[i].val);
    }
    return 0;
}
