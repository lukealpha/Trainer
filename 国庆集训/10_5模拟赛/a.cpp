#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll check(ll x, ll y, ll z, ll n){
    ll res = 0;
    res = (x + y) + (x + y) + (n - 1) * z;
    res *= n;
    res = res / 2;
    return res;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n;ll t;
    scanf("%d%lld",&n,&t);
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        long long x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        ll l = 0, r = t/(x + y),res = 0;
        while (l <= r){
            ll mid = (l + r) >> 1;
            ll chk = check(x,y,z,mid);
            if(check(x,y,z,mid) <= t){
                l = mid + 1;
                res = chk;
                res -= mid*x;
                res += max(0ll,(t - chk - x));
            }
            else{
                r = mid - 1;
            }
        }
        ans += res;
    }
    printf("%lld",ans);
    return 0;
}