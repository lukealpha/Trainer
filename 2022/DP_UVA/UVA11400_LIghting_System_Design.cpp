#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Lamps{
    int v,k,c,l;
}lamp[1010];
bool cmp(Lamps a, Lamps b){
    return a.v < b.v;
}
int s[1010], dp[1010], n;
int main(){
    while(scanf("%d",&n)&&n!=0){
        for (int i = 1; i <= n; i ++){
            scanf("%d%d%d%d",&lamp[i].v, &lamp[i].k, &lamp[i].c, &lamp[i].l);
        }
        sort(lamp + 1, lamp + n + 1, cmp);
        for (int i = 1; i <= n; i ++){
            s[i] = s[i - 1] + lamp[i].l;
        }
        memset(dp,0x3f,sizeof dp);
        dp[0] = 0;
        for (int i = 1; i <= n; i ++){
            for (int j = 0; j < i; j ++){
                dp[i] = min(dp[i],dp[j] + (s[i] - s[j])*lamp[i].c + lamp[i].k);
            }
        }
        printf("%d\n",dp[n]);
    }    
    return 0;
}