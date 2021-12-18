#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1000010;
struct debt{
    long long loan, inv;
}d[maxn];
int main(){
    freopen("debt.in","r",stdin);
    freopen("debt.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        d[x].loan += (long long)c;
        d[y].inv += (long long)c;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i ++){
        ans += max(0ll,d[i].loan - d[i].inv);
    }
    printf("%lld",ans);
    return 0;
}