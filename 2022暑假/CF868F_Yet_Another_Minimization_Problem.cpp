#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 10;
ll dp[22][MAXN], ans; int cur,L,R;
int n,k,a[MAXN], st[MAXN];
void modify(int val, int f){
    ans += (1ll)*f*st[val]*(st[val] - 1)/2;
    return ;
}
ll calc(int l,int r){

    while(L < l) {modify(a[L],-1); st[a[L]] --; modify(a[L++],1);}
    while(L > l) {modify(a[--L],-1); st[a[L]] ++ ; modify(a[L],1);}
    while(R < r) {modify(a[++R],-1); st[a[R]] ++ ; modify(a[R],1);}
    while(R > r) {modify(a[R],-1),st[a[R]] --; modify(a[R--],1);}
    return ans; 
}

void dac(int lb, int rb, int l, int r){
    if(l > r || lb > rb) return ;
    int mid = (l + r) >> 1, d = 0; ll res = 1e18;
    for (int i = lb; i <= rb; i ++){
        ll tmp = calc(i + 1, mid);
        if(res > dp[cur - 1][i] + tmp) res = dp[cur - 1][i] + tmp, d = i;
    }
    dp[cur][mid] = res;
    dac(lb, d, l, mid - 1);dac(d, rb, mid + 1, r);
    return ;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0; L = R = 1, st[a[1]] = 1;
    for (cur = 1; cur <= k; cur ++){
        dac(0,n - 1,1,n);
    }
    printf("%lld",dp[k][n]);
    return 0;
}