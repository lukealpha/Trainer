#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
const int maxn = 1010;
int arr[maxn];
char str[maxn];
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",str);
    for (int i = 0; i < n; i ++){
        arr[i + 1] = str[i] - '0';
    }
    if(k == 0){
        ll ans = 0;
        for (int i = 1; i <= n; i ++){
            ans += i;
        }
        printf("%lld",ans);
        return 0;
    }
    k = pow(2,k);
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        long long cur = 0;
        if(arr[i] == 0){ans ++;}
        else{
            for (int j = i; j <= n; j ++){
                cur = cur * 10ll;
                cur += arr[j];
                cur = cur % k;
                if(cur == 0){
                    ans ++;
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}