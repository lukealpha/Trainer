#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1e5+7;
int n;ll k;
ll a[maxn];
ll qpow(ll p, ll q){
    ll ans = 1, base = p;
    while(q){
        if(q&1){
            ans *= base;
            ans %= k;
        }
        q >>= 1;
        base = base*base;
        base %= k;
    }
    return ans;
}
ll f[maxn],g[maxn];
int main(){
    scanf("%d%lld",&n,&k);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
    }
    for (int i = 1; i <= n; i ++){
        f[i] = qpow(i,a[i]);
        g[i] = qpow(a[i],i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            if(f[i]>g[j]) ans ++;
        }
    }
    printf("%lld",ans);
    return 0;
}