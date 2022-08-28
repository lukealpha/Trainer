#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,k;
const int maxn = 10010, maxm = 1010;
int up[maxn], dn[maxn],h[maxn],l[maxn];
int dp[maxn][maxm],pas[maxn];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        up[i] = x, dn[i] = y;
        h[i] = m + 1;
    }
    for (int i = 1; i <= k; i ++){
        int p, lx, hx;
        scanf("%d%d%d",&p,&lx,&hx);
        l[p] = lx,h[p] = hx;
    }
    memset(dp,0x3f,sizeof dp);
    for (int i = 0; i <= m; i ++) dp[0][i] = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = up[i]; j < h[i]; j ++){
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j - up[i]] + 1,dp[i][j - up[i]] + 1));
        }

        for (int j = 1; j + dn[i] <= m; j ++){
            dp[i][j] = min(dp[i][j], dp[i - 1][j + dn[i]]);
        }
        if(h[i] == m + 1){
            for (int j = 0; j <= m; j ++){
                if(j == m){
                    dp[i][m] = min(dp[i][m], dp[i - 1][m] + 1);
                }
                else{
                    int tap = int(ceil((double)(m - j) / (double)up[i]));
                    dp[i][m] = min(dp[i][m], dp[i - 1][j] + tap);
                }
            }
        }
        for (int j = 0 ; j <= l[i]; j ++){
            dp[i][j] = 0x3f3f3f3f;
        }
        for (int j = h[i]; j <= m; j ++){
            dp[i][j] = 0x3f3f3f3f;
        }
        for (int j = 1; j <= m; j ++){
            if(dp[i][j] != 0x3f3f3f3f){
                pas[i] = true;
                break;
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++){
        ans = min(ans,dp[n][i]);
    }
    if(ans == 0x3f3f3f3f){
        int cnt = 0;
        for (int i = 1; i <= n - 1; i ++){
            if((l[i] != 0 || h[i] != m + 1) && pas[i]){
                cnt ++;
            }
        }
        printf("0\n%d",cnt);
    }
    else
        printf("1\n%d",ans);
    return 0;
}