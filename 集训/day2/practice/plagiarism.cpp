#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100010];
long long ans;
int main(){
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i= 1; i <= n; i ++){
        int l = 1,r = i;
        while(l < r){
            int mid = (l + r) / 2;
            if(a[mid] * 10 >= a[i] * 9){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        ans += i - l;
    }
    printf("%lld",ans);
    return 0;
}