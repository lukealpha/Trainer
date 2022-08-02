#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 35, maxk = 35, maxm = 110, mod = 998244353;
ll dp[maxm][maxn][maxn][maxn]; // 填 第i个数 对应2^(i - 1)次方
//填到第i个数，用了j个1，到当前位共k个1，共要往后进l个1
ll C[maxn][maxn];
ll v[maxm];

void init(){
    for (int i = 0; i < maxn; i ++){
        C[i][0] = 1;
    }
    for (int i = 1; i < maxn; i ++){
        for (int j = 1; j <maxn; j ++ ){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%mod;
        }
    }
}
ll qpow(ll base, int exp){
    ll ans = 1;
    while(exp){
        if(exp & 1){
            ans  = (ans * base)%mod;
        }
        base = (base * base) %mod;
        exp >>= 1;
    }
    return ans;
}
int popcnt(int x){
    int cnt = 0;
    while(x){
        if(x&1) cnt ++;
        x >>= 1;
    }
    return cnt;
}
int main(){
    //记得取模
    init();
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    for (int i = 0; i <= m; i ++){
        scanf("%lld",&v[i]);
    }
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= m ; i++){ 
        for (int j = 0; j <= n; j ++){
            for (int k = 0; k <= K; k ++){
                for (int l = 0; l <= n; l ++){
                    for (int t = 0; t <= n - j; t ++){
                        dp[i+1][j+t][k+(t+l)%2][(t+l)/2] = (dp[i+1][j+t][k+(t+l)%2][(t+l)/2] + dp[i][j][k][l] * qpow(v[i],t) % mod *C[n-j][t]%mod)%mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k <= K; k ++){
        for (int l = 0; l <= n >> 1; l ++){
            if(k + popcnt(l) <= K){
                ans = (ans + dp[m + 1][n][k][l])%mod;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}