#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll n;
ll f[1010][1010];
ll g[1010];
ll dp(ll m, ll q){
    if(m==1)return 1ll;
    if(f[m][q] != -1) return f[m][q];
    ll& ans = f[m][q];
    ans = q;
    for (ll i = q - 1; i >= 1; i --){
        ans = max(ans,i*dp(m-i,min(m-i,i-1)));
    }
    return ans;
}
int main(){
    memset(f,-1,sizeof f);
    scanf("%lld",&n);
    printf("%lld\n",dp(n,n));
    
}