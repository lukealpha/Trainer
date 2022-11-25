#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
ll d[10010];
ll a[10010];
ll dp[2][136000];
ll pred[10010];
int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
        d[i] = a[i] - a[i - 1];
    }
    sort(d+2,d+n+1);
    ll Smax = 0;
    for (int i = 1; i <= n; i ++){
        pred[i] = pred[i-1]+d[i];
        Smax+=pred[i]*(long long)i;
    }

    memset(dp,0x3f,sizeof dp);
    ll inf = dp[0][0];
    int now = 0;
    dp[now][a[1]+a[1]+d[2]] = a[1]*a[1]+(a[1]+d[2])*(a[1]+d[2]);
    for (int i = 2; i < n; i ++){
        for (int j = 0; j <= Smax; j ++){
            if(dp[i][j]==inf) continue;
            dp[now^1][j+pred[i+1]] = min(dp[now^1][j+pred[i+1]],dp[now][j]+pred[i+1]*pred[i+1]);
            dp[now^1][j+(i-1)*d[i+1]+a[1]+d[i+1]] = min(dp[now^1][j+(i-1)*d[i+1]+a[1]+d[i+1]],dp[now][j]+(a[1]+d[i+1])*(a[1]+d[i+1])+(j-a[1])*d[i+1]*2+(i-1)*d[i+1]*d[i+1]);
            dp[now][j]=inf;
        }
        now^=1;
    }
    ll ans = inf;
    for (int i = 0; i <= Smax; i ++){
        if(dp[now][i]!=inf){
            ans=min(ans,(long long)n*dp[now][i]-i*i);
        }
    }
    printf("%lld",ans);
    return 0;
}