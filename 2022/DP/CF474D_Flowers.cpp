#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;
const int maxn = 100010;
const ll MOD = 1e9 + 7;
int t,k;
ll dp[maxn],pre[maxn];
int main(){
    scanf("%d%d",&t,&k);
    dp[0] = 1;
    for (int i = 1; i <= 100001; i ++){
        if(i - k >= 0){
            dp[i] = dp[i - 1] + dp[i - k];
            dp[i] %= MOD;
        }
        else dp[i] = dp[i - 1], dp[i] %= MOD;
    }
    for (int i = 1; i <= 100001; i ++){
        pre[i] = pre[i - 1] + dp[i];
        pre[i] %= MOD;
    }
    while(t --){
        int l, r;
        scanf("%d%d",&l,&r);
        printf("%lld\n",(pre[r] - pre[l - 1] + MOD) % MOD);
    }

    return 0;
}