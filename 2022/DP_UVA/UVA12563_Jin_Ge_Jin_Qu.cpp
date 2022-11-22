#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[55][10100];
int g[55][10100];
int v[55];
int n,t;
int main(){
    auto kase = 0;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&t);
        for (int i = 1; i <= n; i ++){
            scanf("%d",&v[i]);
        }
        memset(dp,0,sizeof dp);
        for (int i = 1; i <= n; i ++){
            for (int j = 0; j < t; j ++){
                if(dp[i-1][j]>dp[i-1][j-v[i]]+1 || j < v[i]){
                    dp[i][j] = dp[i-1][j];
                    g[i][j] = g[i-1][j];
                }
                else if(dp[i-1][j-v[i]] + 1 > dp[i-1][j]){
                    dp[i][j] = dp[i-1][j-v[i]] + 1;
                    g[i][j] = g[i-1][j-v[i]] + v[i];
                }
                else if(g[i-1][j-v[i]] + v[i] > g[i-1][j]){
                    dp[i][j] = dp[i-1][j-v[i]] + 1;
                    g[i][j] = g[i-1][j-v[i]] + v[i];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    g[i][j] = g[i-1][j];
                }
            }
        }
        printf("Case %d: %d %d\n",++kase,dp[n][t-1]+1,g[n][t-1]+678);
    }
    

}