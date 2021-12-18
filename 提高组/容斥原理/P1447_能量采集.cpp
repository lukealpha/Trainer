#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll f[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n > m){
        swap(n,m);
    }
    long long ans = 0;
    for (int i = n; i >= 1; i --){
        f[i] = (long long)(n / i) * (m / i);
        for (int j = i * 2; j <= n; j += i){
            f[i] -= f[j];
        }
        ans += f[i]*(long long)(2 * i - 1);
    }
    printf("%lld",ans);
    return 0;
}