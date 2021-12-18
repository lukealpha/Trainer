#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const long long mod = 998244353;
long long dp[100][3];
int main(){
    int L,h;
    scanf("%d%d",&L,&h);
    dp[0][2] = 1;
    for (int i = 1; i <= L; i ++){
        if(i >= h){
            dp[i][0] += dp[i - h][2];
            dp[i][0] %= mod;
        }
        dp[i][1] += dp[i - 1][2];
        dp[i][1] %= mod;
        dp[i][2] += dp[i - 1][0] + dp[i - 1][1];
        dp[i][2] %= mod;

    }
    long long ans = 0;
    for (int i = 1; i <= L; i ++){
        ans += dp[i][0] + dp[i][1];
        ans %= mod;
    }
    cout << ans;
    return 0;
}