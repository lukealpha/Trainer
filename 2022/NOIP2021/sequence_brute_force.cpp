#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int mod = 998244353;
ll v[20];
int n,m,k;
ll f[33][130010];
bool check(ll m){
    ll nm = m, cnt = 0;
    while(nm){
        if(nm&1)cnt++;
        nm>>=1;
    }
    return cnt<=k?true:false;
}
ll dp(int x, ll b){
    if(f[x][b]!=-1) return f[x][b];
    ll& ans = f[x][b];
    if(x == n + 1){
        if(check(b)){
            return ans = 1;
        }
        else return ans = 0;
    }
    ans = 0;
    for (int i = 0; i <= m; i ++){
        ll nb = b;
        nb += 1<<i;
        ans += v[i]*dp(x+1,nb);
        ans %= mod;
    }
    return ans;
}
int main(){
    memset(f,-1,sizeof f);
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i <= m; i ++){
        scanf("%lld",&v[i]);
    }
    cout << dp(1,0);
    return 0;
}
/*
dp(int n,bin[0,2^m-1])



*/