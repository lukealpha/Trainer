#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 2e5 + 7;
ll a[maxn];
ll solve(ll h, ll x1, ll x2, ll x3, ll p, ll n){
    ll ans = 0;
    h *= x1;
    for (;p <= n; p ++){
        if(a[p] < h){
            h += a[p]/2;
            ans ++;
        }
        else break;
    }
    h *= x2;
    for (;p <= n; p ++){
        if(a[p] < h){
            h += a[p]/2;
            ans ++;
        }
        else break;
    }
    h *= x3;
    for (; p <= n; p ++){
        if(a[p] < h){
            h += a[p]/2;
            ans ++;
        }
        else break;
    }
    return ans;
}
int main(){
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,h;
        scanf("%lld%lld",&n,&h);
        for (int i = 1; i <= n; i ++){
            scanf("%lld",&a[i]);
        }
        sort(a + 1, a + n + 1);
        int p;
        ll ans = 0;
        for (p = 1; p <= n; p ++){
            if(a[p] < h){
                h += a[p]/2;
                ans ++;
            }
            else break;
        }
        ll ans1 = ans, ans2 = ans, ans3 = ans;
        ans1 += solve(h,2,2,3,p,n);
        ans2 += solve(h,2,3,2,p,n);
        ans3 += solve(h,3,2,2,p,n);
        printf("%lld\n",max(ans1,max(ans2,ans3)));
    }
    return 0;
}