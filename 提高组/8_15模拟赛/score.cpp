#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 1010;

long long dp[maxn];
struct problem{
    long long a,b,c;
}p[maxn];
bool cmp(problem x, problem y){
    return x.c < y.c;
}
int main(){
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n,t;
        scanf("%d%d",&n,&t);
        for (int i = 1; i <= n; i ++){
            scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
        }
        sort(p, p + n + 1, cmp);
        for(int i = 1; i <= n; i++){
            for(int j = t; j >= p[i].c; j --){
                dp[j] = max(dp[j-p[i].c]+p[i].a,dp[j]);
            }
        }
        printf("%d\n",dp[t]);
    }
    return 0;
}
