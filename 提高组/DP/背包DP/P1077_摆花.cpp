#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 105;
const int Mod = 1e6 + 7;
int n,m;
int dp[maxn][maxn][maxn];
int a[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    for (int i = 0; i <= n; i ++){
        dp[1][i][1] = 1;
    }
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++){
            for (int k = 0; k <= min(a[j - 1],i); k ++){
                dp[i][j][0] += dp[i][j - 1][k];
            }
            for (int k = 1; k <= min(a[j],i); k ++){
                dp[i][j][k] += dp[i - 1][j][k - 1];
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=min(m,a[n]);i++)
	    ans+=dp[m][n][i],ans%=1000007;        //找到最后一朵花种都种掉了时，ans的最大值，不要忘了“0” “0” “0” （种0朵的情况）！！！！ 
    printf("%d",ans); 
    //printf("%d",ans);
    return 0;
}