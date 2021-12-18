#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k;
long long p;
long long a[100010], rec[100010];
long long mx = 0, mi = 0x3f3f3f3f;
long long ans = 0;
void dfs(int dig, int last,int k){
    if(dig == k + 1){
        ans += mx - mi;
        return ;
    }
    for (int i = last + 1; i <= n; i ++){
        //rec[dig] = a[i];
        int lmx = mx, lmi = mi;
        mx = max(mx,a[i]);
        mi = min(mi,a[i]);
        dfs(dig + 1, i, k);
        rec[dig] = 0;
        mx = lmx;
        mi = lmi;
    }
}
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d%lld",&n,&k,&p);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
    }
    dfs(1,0,k);
    printf("%lld",ans);
    return 0;
}