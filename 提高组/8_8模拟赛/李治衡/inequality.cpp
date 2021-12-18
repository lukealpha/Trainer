#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

bool powi[45],cnt;
long long f[1000002];
ll n,x,y;
int main(){
    freopen("inequality.in","r",stdin);
    freopen("inequality.out","w",stdout);
    for (long long i = 1; i <= 1000100; i ++){
        f[i] = i * i;
    }
    scanf("%lld%lld%lld",&n,&x,&y);
    if(n > y){
        printf("-1");
        return 0;
    }
    long long div = y - (n - 1);
    if((n - 1ll) * f[1] + f[div] >= x){
        printf("%lld\n",div);
        for (int i = 1; i <= n - 1; i ++){
            printf("1\n");
        }
        return 0;
    }
    printf("-1"); 
}