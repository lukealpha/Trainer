#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
ll d[10010];
ll a[10010];
ll dp[2][6000010];
ll pred[10010];
int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n;
    scanf("%d",&n);
    ll maxx = 0;
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
        maxx = max(maxx,a[i]);
        d[i] = a[i] - a[i - 1];
    }
    sort(d+2,d+n+1);
    ll Smax = 0;
    for (int i = 1; i <= n; i ++){
        pred[i] = pred[i-1]+d[i];
        Smax+=d[i]*(long long)i;
    }

    memset(dp,0x3f,sizeof dp);
    ll inf = dp[0][0];
    int now = 0;
    int cnt = 0, ssum = 0;
    for (int i = 2; i <= n; i ++){
        if(d[i] == 0){
            cnt ++;
            ssum += a[1]*a[1];
        }
    }
    dp[now][a[1]+a[1]*cnt] = a[1]*a[1]+ssum;
    
    for (int i = cnt+1; i < n; i ++){
        for (ll j = 0; j <= maxx*n; j ++){
            if(dp[now][j]==inf) continue;
            dp[now^1][j+pred[i+1]] = min(dp[now^1][j+pred[i+1]],dp[now][j]+pred[i+1]*pred[i+1]);
            dp[now^1][j+(i-1)*d[i+1]+a[1]+d[i+1]] = min(dp[now^1][j+(i-1)*d[i+1]+a[1]+d[i+1]],dp[now][j]+(a[1]+d[i+1])*(a[1]+d[i+1])+(j-a[1])*d[i+1]*2+(i-1)*d[i+1]*d[i+1]);
            dp[now][j]=inf;
        }
        now^=1;
    }
    ll ans = inf;
    for (ll i = 0; i <= maxx*n; i ++){
        if(dp[now][i]!=inf){
            ans=min(ans,(long long)n*dp[now][i]-i*i);
        }
    }
    printf("%lld",ans);
    return 0;
}