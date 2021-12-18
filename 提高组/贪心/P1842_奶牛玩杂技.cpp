#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
struct cow_info{
    int w, s, ws_sum;
}c[50010];
bool cmp(cow_info a, cow_info b){
    return a.ws_sum > b.ws_sum;
}
long long sum[50010];
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d",&c[i].w,&c[i].s);
        c[i].ws_sum = c[i].w + c[i].s;
    }
    sort(c + 1, c + n + 1, cmp);
    long long ans = -0x3f3f3f3f;
    for (int i = n; i >= 1; i --){
        sum[i] = sum[i + 1] + c[i].w;
    }
    for (int i = 1; i <= n; i ++){
        ans = max(ans, sum[i + 1] - (long long)c[i].s);
    }
    printf("%lld",ans);
    return 0;
}