#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1010, maxm = 2020;
int n,m;
int a[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= m; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        ans += min(a[x],a[y]);
    }
    printf("%lld",ans);
    return 0;
}