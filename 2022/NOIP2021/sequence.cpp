#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int mod = 998244353;
int n,m,k;
ll f[33][110][110][110];
ll pw[110][33];
ll C[33][33];
int pop_cnt(ll x){
    ll nm = x, cnt = 0;
    while(nm){
        if(nm&1)cnt++;
        nm>>=1;
    }
    return cnt;
}
void init(){
    for (int i = 0; i <= n; i ++){
        C[i][0] = 1;
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
            C[i][j] %= mod;
        }
    }
    for (int i = 0; i <= m; i ++){
        for (int j = 2; j <= n; j ++){
            pw[i][j] = pw[i][j-1]*pw[i][1];
            pw[i][j] %= mod;
        }
    }
}
ll dp(int x, int y, int cnt, int p){
    if(x > n) return 0;
    if(f[x][y][cnt][p] != -1) return f[x][y][cnt][p];
    ll& ans = f[x][y][cnt][p];
    if(y == m + 1){
        if(x != n) return 0;
        if(cnt+pop_cnt(p) <= k){
            return ans = 1;
        }
        else return ans = 0;
    }
    ans = 0;
    for (int i = 0; i <= n-x; i ++){
        ans += ((pw[y][i]*dp(x+i,y+1,cnt+(p+i)%2,(p+i)/2))%mod)*C[n-x][i]%mod;
        ans %= mod;
    }
    return ans;
}
int main(){
    memset(f,-1,sizeof f);
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i <= m; i ++){
        pw[i][0] = 1;
        scanf("%lld",&pw[i][1]);
    }
    init();
    printf("%lld",dp(0,0,0,0));
    return 0;
}
/*
dp(int n,bin[0,2^m-1])

10 6 5
1 2 93 8 7 9 6


*/