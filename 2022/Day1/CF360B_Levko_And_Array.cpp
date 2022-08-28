#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define inf 2e9+5
using namespace std;
const int maxn = 2020;

ll a[maxn],f[maxn];
int n,k;
bool judge(ll md){
    memset(f,0,sizeof f);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j < i; j ++){
            if(a[i] + (i - j)*md >= a[j]){
                f[i] = min(f[i],f[j] + (i - j - 1));
            }
        }
    }
    for (int i = 1; i <= n; i ++){
        if(f[i] + (n - i) <= k)
            return true;
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
    }
    ll l = 0,r = 2e9 + 5,ans = -1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if (judge(mid)){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    printf("%lld",ans);
    return 0;
}