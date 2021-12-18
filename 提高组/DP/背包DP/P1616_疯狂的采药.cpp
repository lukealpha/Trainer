#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxm = 1e4;
const int maxt = 1e7;
int T,m;
int w[maxm],v[maxm];
long long dp[maxt];
int main(){
    scanf("%d%d",&T,&m);
    for (int i = 1; i <= m; i ++){
        scanf("%d%d",&v[i],&w[i]);
    }
    for (int i = 1; i <= m; i ++){
        for (int j = v[i]; j <= T; j ++){
            dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        }
    }
    printf("%lld",dp[T]);
    return 0;
}