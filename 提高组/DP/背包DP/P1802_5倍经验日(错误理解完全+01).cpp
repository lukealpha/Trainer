#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1010;
int n,X;
int lose[maxn],win[maxn],use[maxn];
long long dp[maxn][2]; // 0:没有打死 1: 打死了
int main(){
    scanf("%d%d",&n,&X);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d%d",&lose[i],&win[i],&use[i]);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= X; j ++){
            dp[j][0] = max(dp[j][0],dp[j][1]);
            dp[j][1] = 0;
        }
        for (int j = 1; j <= X; j ++){
            dp[j][0] = max(dp[j][0],dp[j - 1][0] + lose[i]);
            if(j >= use[i]){
                dp[j][1] = dp[j - use[i]][0] + win[i];
            }
        }
    }
    printf("%lld",max(dp[X][0],dp[X][1]));
    return 0;
}