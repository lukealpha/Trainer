#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n;
long long s,range[200010][2];
long long lr[200010],rr[200010];
bool check(long long x){
    int left= 0, right= 0, mid= 0;
    long long ans = 0;
    for (int i = 1; i <= n; i ++){
        if(range[i][1] < x){
            left ++;
            ans += range[i][0];
        }
        if(range[i][0] > x){
            right ++;
            ans += range[i][0];
        }
        if(ans > s){
            return false;
        }
    }
    for (int i = 1; i <= n; i ++){
        if(x <= range[i][1] && x >= range[i][0]){
            if(left < right && range[i][0] < x){
                left ++;
                ans += range[i][0];
            }
            if(right < left && range[i][1] > x){
                right ++;
                ans += x;
            }
            if(ans > s){
                return false;
            }
        }
    }
    if(ans <= s){
        return true;
    }
    else return false;
}

int main(){
    freopen("salary.in","r",stdin);
    freopen("salary.out","w",stdout);
    scanf("%d%lld",&n,&s);
    for (int i = 1; i <= n; i ++){
        scanf("%lld%lld",&range[i][0],&range[i][1]);
        lr[i] = range[i][0];
        rr[i] = range[i][1];
    }
    sort(lr + 1, lr + n + 1);
    sort(rr + 1, rr + n + 1);
    long long L = lr[(n + 1)/ 2], R = min(s,rr[(n + 1)/ 2]), ans = 0;
    bool flag = 0;
    while(L <= R){
        long long mid = (L + R) / 2;
        if(check(mid)){
            flag = true;
            L = mid + 1;
            ans = mid;
        }
        else{
            R = mid - 1;
        }
    }
    printf("%lld",ans);
    return 0;
}