#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
#include <cstring>

using namespace std;
const int maxn = 5050;
int n,s,t[maxn],f[maxn];
ll pref[maxn],pret[maxn];
ll dp[maxn];

int main(){
    scanf("%d%d",&n,&s);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d",&t[i],&f[i]);
        pref[i] = pref[i - 1] + f[i];
        pret[i] = pret[i - 1] + t[i];
    }
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i ++){
        for (int k = 1; k <= i; k ++){
            dp[i] = min(dp[i], dp[k - 1] + (pref[n] - pref[k - 1])*s + pret[i] * (pref[i] - pref[k - 1]));
        }
    }
    printf("%lld",dp[n]);
    return 0;
}