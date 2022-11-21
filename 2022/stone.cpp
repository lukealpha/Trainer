#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll a[1010],pref[1010];
ll dp[1010][1010];
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++){
		scanf("%lld",&a[i]);
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2*n; i ++){
		pref[i] = pref[i - 1] + a[i];
	}
	for (int b = 0; b < n; b ++){
		for (int len = 3; len <= n; len ++){
			if(len%2==0){
				for (int j = 1+b; j <= n+b-len+1; j ++){
					int k = j + len - 1;
					dp[j][k] = 1e11 + 7;
					for (int m = j; m < k; m += 2){
						dp[j][k] = min(dp[j][k],dp[j][m]+dp[m+1][k]);
					}
				}
				continue;
			}
			for (int j = 1+b; j <= n+b-len+1; j ++){
				int k = j + len - 1;
				dp[j][k] = 1e11 + 7;
				for (int m = j; m < k; m ++){
					dp[j][k] = min(dp[j][k],dp[j][m]+dp[m+1][k]+pref[k]-pref[j-1]);
				}
			}
		}
	}
	ll ans = 1e11 + 7;
	for (int i = 1; i <= n; i ++){
		ans = min(ans,dp[i][i+n-1]);
	}
	printf("%lld",ans);
	return 0;
}
