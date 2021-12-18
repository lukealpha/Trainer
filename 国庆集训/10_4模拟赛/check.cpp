#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 500010;
int a[maxn];
int b[maxn];
int f[maxn];
int n;long long k;
bool check(int i){
    if(a[i] == 0 && b[i] == 1){
        return true;
    }
    else if(a[i] == 1 && b[i] == 2){
        return true;
    }
    else if(a[i] == 2 && b[i] == 0){
        return true;
    }
    else if(a[i] != b[i]){
        return false;
    }
    else{
        return false;
    }
}
int main(){
    freopen("check.in","r",stdin);
    freopen("check.out","w",stdout);

    scanf("%d%lld",&n,&k);
    int m = k % (long long)n;
    k = k / (long long)n;
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n; i ++){
        scanf("%d",&b[i]);
    }
    long long ans_a = 0, ans_b = 0,ans_ak = 0, ans_bk = 0;
    for (int i = 1; i <= n; i ++){
        
            if(a[i] == b[i]){
                continue;
            }
            if(check(i)){
                ans_a ++;
                if(i <= m){
                    ans_ak ++;
                }
            }
            else{
                ans_b ++;
                if(i <= m){
                    ans_bk ++;
                }
            }
    }
    ans_a *= (long long)k;
    ans_b *= (long long)k;
    ans_a += ans_ak;
    ans_b += ans_bk;
    printf("%lld %lld",ans_a,ans_b);
    return 0;
}