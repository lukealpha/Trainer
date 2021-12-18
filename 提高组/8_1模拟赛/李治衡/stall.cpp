#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1000010;
int n,q;
ll a[maxn];
int calc(ll b){
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++){
        int cnt = 0;
        ll ksum = 0;
        for (int j = i; j <= n + i - 1; j ++){
            if(ksum + a[j] <= b){
                ksum += a[j];
            }
            else{
                cnt ++;
                ksum = a[j];
            }
        }
        cnt ++;
        ans = min(cnt,ans);
        if(ans == 1){
            return ans;
        }
    }
    return ans;
}
int main(){
    freopen("stall.in","r",stdin);
    freopen("stall.out","w",stdout);
    scanf("%d%d",&n,&q);
    ll maxa = 0;
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
        maxa = max(maxa,a[i]);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= q; i ++){
        ll b;
        scanf("%lld",&b);
        printf("%d\n",calc(b));
    }
    return 0;
}