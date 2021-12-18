#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int MAXN = 200010;
int n,m;
int ls[MAXN],rs[MAXN];
int w[MAXN], v[MAXN];
ll nq[MAXN],vq[MAXN],s;
ll check(int W){
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        if(w[i] >= W ){
            nq[i] = nq[i - 1] + 1;
            vq[i] = vq[i - 1] + v[i];
        }
        else{
            nq[i] = nq[i - 1];
            vq[i] = vq[i - 1];
        }
    }
    for (int i = 1; i <= m; i ++){
        ans += (nq[rs[i]] - nq[ls[i] - 1]) * (vq[rs[i]] - vq[ls[i] - 1]);
    }
    return ans;
}
int main(){
    scanf("%d%d%lld",&n,&m,&s);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d",&w[i],&v[i]);
    }
    for (int i =1; i <= m; i ++){
        scanf("%d%d",&ls[i],&rs[i]);
    }
    ll L = 0, R = 1000000, ans;
    while(L <= R){
        int mid = (L + R) / 2;
        if(check(mid) - s >= 0){
            L = mid + 1;
            ans = mid;
        }
        else{
            R = mid - 1;
        }
    }
    ll mi = min(abs(check(ans) - s), min(abs(check(ans + 1) - s), abs(check(ans - 1) - s)));
    printf("%lld",mi);
    return 0;
}