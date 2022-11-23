#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll n;
ll f[1010];
ll g[1010];
ll dp(ll m){
    if(m==1)return 1ll;
    if(f[m] != -1) return f[m];
    ll& ans = f[m];
    ans = m;
    g[m] = m;
    for (ll i = (m/2ll)+1ll; i <= m; i ++){
        //ans = max(ans,i*dp(m-i));
        if(i*dp(m-i)>ans){
            ans = i*dp(m-i);
            g[m] = i;
        }
    }
    return ans;
}
int main(){
    memset(f,-1,sizeof f);
    scanf("%lld",&n);
    printf("%lld\n",dp(n));
    while(n){
        printf("%lld ",g[n]);
        n = n-g[n]; 
    }
    
}