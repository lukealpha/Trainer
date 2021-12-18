#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

const int maxt = 4000010;
ll cnt[maxt], sum[maxt], f[maxt];
int main(){
    int n, m, t = 0;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        int ti;
        scanf("%d",&ti);
        t = max(t,ti);
        cnt[ti] ++;
        sum[ti] += ti;
    }
    for (int i = 1; i < t + m; i ++){
        cnt[i] = cnt[i] + cnt[i - 1];
        sum[i] = sum[i] + sum[i - 1];
    }
    for (int i = 0; i < t + m; i ++){
        if(i >= m && cnt[i - m] == cnt[i]){
            f[i] = f[i - m];
        }
        f[i] = cnt[i] * i  - sum[i];
        for (int j = max(0,i - m - m + 1); j <= i - m; j ++){
            f[i] = min(f[i], f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]));
        }
    }
    ll ans = 1e9;
    for (int i = t; i < t + m; i++){ 
        ans = min(ans, f[i]);
    }
    printf("%lld\n", ans);
    return 0;
}