#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 2020;
const int maxc = 2e5 + 7;
const int MOD = 1e9+7;
ll h,w,fac[maxc],inv[maxc],f[maxn];int n;
struct cells{
    int x, y;
}cel[maxn];
bool cmp(cells a,cells b){ return a.x<b.x||(a.x==b.x&&a.y<b.y); }
ll C(ll n, ll m){
    if(n < m) return 0;
    return ((fac[n]*inv[n - m]%MOD)*inv[m])%MOD;
}
ll qpow(ll x, ll exp){
    ll base = x,ans = 1;
    while(exp){
        if(exp & 1){
            ans *= base;
            ans %= MOD;
        }
        base = (base*base)%MOD;
        exp >>= 1;
    }
    return ans % MOD;
}
void init_inv(){
    fac[0] = 1;inv[0] = 1; 
    for (int i = 1; i <= 2e5 + 3; i ++){
        fac[i] = fac[i - 1] * (long long)i;
        fac[i] %= MOD;
        inv[i] = qpow(fac[i],MOD - 2);
    }
    return ;
}
int main(){
    scanf("%lld%lld%d",&h,&w,&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d",&cel[i].x,&cel[i].y);
    }
    cel[n + 1].x = h, cel[n + 1].y = w;
    sort(cel + 1, cel + n + 2,cmp);
    init_inv();
    for (int i = 1; i <= n + 1; i ++){
        ll ans = C(cel[i].x + cel[i].y - 2, cel[i].x - 1);
        for (int j = 1; j < i ; j ++){
            if(cel[j].y > cel[i].y || cel[i].x < cel[j].x) continue;
            if(cel[j].x <= cel[i].x && cel[j].y <= cel[i].y){
                ans -= (f[j]*C(cel[i].x - cel[j].x + cel[i].y - cel[j].y,cel[i].x - cel[j].x)) % MOD;
                ans = (ans + MOD) % MOD;
            }
        }
        f[i] = ans;
    }
    printf("%lld",f[n + 1]% MOD);
    return 0;
}