#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 205;
const ll inf = 1e9;
ll f[maxn][maxn];
int rec[maxn];
int n,m;
void update(int k){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
        }
    }
    return ;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++)
        if(i != j)  f[i][j] = inf;

    for (int i = 0; i < n; i ++){
        scanf("%d",&rec[i]);
    }
    for (int i = 1; i <= m; i ++){
        int x,y;ll z;
        scanf("%d%d%lld",&x,&y,&z);
        f[x][y] = f[y][x] = z;
    }
    int Q;
    scanf("%d",&Q);
    int now = 0;
    while(Q--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        while(rec[now] <= z && now < n){
            update(now);
            now ++;
        }
        if(rec[x] > z || rec[y] > z) printf("%d\n",-1);
        else if(f[x][y] == inf) printf("%d\n",-1);
        else printf("%lld\n",f[x][y]);
    }
    return 0;
}