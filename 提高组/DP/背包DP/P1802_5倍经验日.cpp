#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1010;
int n,X;
int lose[maxn],win[maxn],use[maxn];
long long dp[maxn]; // 0:没有打死 1: 打死了
int main(){
    scanf("%d%d",&n,&X);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d%d",&lose[i],&win[i],&use[i]);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = X; j >= 0; j --){
            if(j >= use[i]){
                dp[j] = max(dp[j] + lose[i],dp[j - use[i]] + win[i]);
            }
            else{
                dp[j] = dp[j] + lose[i];
            }
        }
    }
    printf("%lld",5ll*dp[X]);
    return 0;
}