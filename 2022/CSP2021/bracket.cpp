#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int n,k;
const int maxn = 550;
const int mod = 1e9+7;
char str[maxn];
ll dp[maxn][maxn],dp2[maxn][maxn],dp3[maxn][maxn];
bool check(int x, int y){
    if((str[x]=='?'&&str[y]=='?')||(str[x]=='('&&str[y]==')')||(str[x]=='('&&str[y]=='?')||(str[x]=='?'&&str[y]==')')){
        return true;
    }
    else return false;
}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    //memset(dp,0x3f,sizeof dp);
    for (int i = 1; i <= n; i ++){
        dp[i][i] = 0;
        if(check(i,i+1))dp[i][i+1] = dp2[i][i+1] = dp3[i][i+1] = 1;
    }
    for (int len = 3; len <= n; len ++){
        for (int i = 1; i + len - 1 <= n; i ++){
            int j = i + len - 1;
            if(check(i,j)){
                int t;
                for (t = i + 1; t <= j - 1; t ++){
                    if(str[t]!='*'&&str[t]!='?') break;
                    if(t-i<=k) dp[i][j] += dp[t+1][j-1];
                }
                if(t==j&&len-2<=k){
                    dp[i][j] ++;
                }
                for (t = j-1; t >= i+1; t --){
                    if(str[t]!='*'&&str[t]!='?') break;
                    if(j-t<=k){
                        dp[i][j] += dp[i+1][t-1];
                    }
                }
                dp[i][j]%=mod;
                dp[i][j] += dp[i+1][j-1];
                dp[i][j]%=mod;
                dp2[i][j] = dp[i][j];
            }
            for (int t = i; t < j; t ++){
                dp[i][j] += dp2[i][t]*dp3[t+1][j];
                dp[i][j]%=mod;
            }
            dp3[i][j] = dp[i][j];
            for (int t = i; t < j; t ++){
                if(str[t]!='*'&&str[t]!='?') break;
                if(t-i+1<=k){
                    dp3[i][j] += dp[t+1][j];
                    dp3[i][j]%=mod;
                }
            }
        }
    }
    printf("%lld",dp[1][n]%mod);
    return 0;
}