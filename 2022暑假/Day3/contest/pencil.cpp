#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1010;
const int maxm = 2020;
int n,m;
struct edge{
    int x, y;
    ll val;
}e[maxm];
ll dp[maxn][maxn];
int main(){
    //freopen("pencil.in","r",stdin);
    //freopen("pencil.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if(i == j){
                dp[i][j] = 0;
            }
            else dp[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i ++){
        int x, y;ll val;
        scanf("%d%d%lld",&x,&y,&val);
        e[i].x = x, e[i].y = y, e[i].val = val;
        dp[x][y] = min(dp[x][y],val), dp[y][x] = min(dp[y][x],val);
    }
    for (int k = 1; k <= n; k ++){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                if(i != k && j != k && i != j){
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++){
        printf("%lld\n",dp[1][i]+dp[i][n]);
    }
    for (int i = 1; i <= m; i ++){
        printf("%lld\n",min(dp[1][e[i].x] + dp[e[i].y][n] + e[i].val, dp[1][e[i].y] + dp[e[i].x][n] + e[i].val));
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}