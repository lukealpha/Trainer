#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1010;
long long dp[maxn][maxn];
long long pre[maxn];
long long input[maxn];
int main(){
    freopen("sculpture.in","r",stdin);
    freopen("sculpture.out","w",stdout);
    int n,A,B;
    scanf("%d%d%d",&n,&A,&B);
    memset(dp,0x3f,sizeof dp);
    for (int i = 0; i < maxn; i ++){
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&input[i]);
    }
    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + input[i];
    }
    for (int i = 1; i <= n; i ++){
        for (int k = A; k <= B; k ++){
            for (int j = 0; j < i; j ++){
                dp[i][k] = min(dp[i][k], dp[j][k - 1] | (pre[i] - pre[j]));
            }
        }
    }
    long long ans = 1000000000010;
    for (int i = A; i <= B; i ++){
        ans = min(ans, dp[n][i]);
    }
    cout <<ans;
    return 0;
}