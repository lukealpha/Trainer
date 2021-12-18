#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 110;
int k,t,s,e,n,comp[1010],num[1010],connection[110][3];
bool used_node[maxn];                    
struct Matrix{
    int a[maxn][maxn];
};
Matrix calc(Matrix x, Matrix y){
    Matrix c;
    memset(c.a,0x3f,sizeof c.a);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            for (int k = 1; k <= n; k ++){
                c.a[i][j] = min(c.a[i][j],x.a[i][k] + y.a[k][j]);
            }
        }
    }
    return c;
}
Matrix g;
Matrix mul(Matrix x, int ti){
    Matrix ans = x;
    ti --;
    while(ti){
        if(ti & 1){
            ans = calc(ans,x);
        }
        x = calc(x, x);
        ti >>= 1;
    }
    return ans;
}
int main(){
    memset(g.a,0x3f,sizeof g.a);
    scanf("%d%d%d%d",&k,&t,&s,&e);
    for (int i = 1; i <= t; i ++){
        int w,u,v;
        scanf("%d%d%d",&w,&u,&v);
        comp[++ n] = u;
        comp[++ n] = v;
        connection[i][0] = u;
        connection[i][1] = v;    
        connection[i][2] = w;
    }
    sort(comp + 1, comp +n + 1);
    n = unique(comp + 1, comp + n + 1) - comp - 1;
    for (int i = 1; i <= n; i ++){
        num[comp[i]] = i;
    }
    for (int i = 1; i <= t; i ++){
        int u,v,w;;
        u = connection[i][0];
        v = connection[i][1];
        w = connection[i][2];
        g.a[num[u]][num[v]] = w;
        g.a[num[v]][num[u]] = w;
    }
    printf("%d",mul(g,k).a[num[s]][num[e]]);
    return 0;
}