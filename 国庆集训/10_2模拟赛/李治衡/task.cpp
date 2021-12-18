#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

const int maxn = 500010;

ll t[maxn];
int main(){
    freopen("task.in","r",stdin);
    freopen("task.out","w",stdout);
    int n;
    ll x;
    scanf("%d%lld",&n,&x);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&t[i]);
    }
    sort(t + 1, t + n + 1);
    ll cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        cnt += t[i];
        if(cnt > x){
            ans += cnt - x;
        }
    }
    printf("%lld",ans);
    return 0;
}