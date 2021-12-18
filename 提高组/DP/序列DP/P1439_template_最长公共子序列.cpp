#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100010;
int p1[maxn],p2[maxn],b[maxn];
int k[maxn],dp[maxn];
int main(){
    memset(b,0x3f,sizeof b);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&p1[i]);
    }
    for (int i = 1; i <= n; i ++){
        scanf("%d",&p2[i]);
    }
    for (int i = 1; i <= n; i ++){
        k[p1[i]] = i;
    }
    for (int i = 1; i <= n; i ++){
        p2[i] = k[p2[i]];
    }
    for (int i = 1; i <= n; i ++){
        *lower_bound(b + 1, b + n + 1, p2[i]) = p2[i];
    }
    printf("%d",(int)(lower_bound(b + 1, b + n + 1, b[0]) - b - 1));
    return 0;
}