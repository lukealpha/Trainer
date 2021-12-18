#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 110;
const long long mod = 1e9 + 7;
long long dp[maxn][1 << 16];
int state[1 << 16];
int cnt, n, m, scnt;
void init(){
	for (int i = 0; i <(1 << m); i ++){
		if(!((i << 2) & i)&&!((i >> 2) & i)){
			for (int j = 0; j <(1 << m); j ++){
				if(!((j << 2) & j)&&!((j >> 2) & j)){
					state[++cnt] = j<<m + i;
					if(i == 0){
						scnt ++;
					}
				}
			}
		}
	}
	for (int i = 1; i <= cnt; i ++){
		dp[1][i] = 1;
	}
}
bool valid_crs_line(int s1,int s2){
	int s11,s12,s21,s22;
	s11 = state[s1] >> m;
	s21 = state[s2] >> m;
	s12 = state[s1] % (1 << m);
	s22 = state[s2] % (1 << m);
	if(!((s11 << 2) & s21)&&!((s11 >> 2) & s21)){
		if(!((s12 << 2) & s22)&&!((s12 >> 2) & s22)){
			return true;
		}
	}
	return false;
	
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	init();
	bool flag = 0;
	if(n%2 != 0) {
		n ++;
		flag = 1;
	}
	n = n / 2;
	for (int i = 2; i <= n; i ++){
		if(i == n && flag){
			for (int j = 1; j <= scnt; j ++){
				for (int k = 1; k <= cnt; k ++){
					if(valid_crs_line(j,k)){
						dp[i][j] += dp[i - 1][k];
						dp[i][j] %= mod;
					}
				}
			}
		}
		else
		{
			for (int j = 1; j <= cnt; j ++){
				for (int k = 1; k <= cnt; k ++){
					if(valid_crs_line(j,k)){
						dp[i][j] += dp[i - 1][k];
						dp[i][j] %= mod;
					}
				}
			}
		}
		
	}
	long long ans = 0;
	if(n == 1 && flag){
		cnt = scnt;
		//ans ++;
	}
	for (int i = 1; i <= cnt; i ++){
		ans += dp[n][i];
		ans %= mod;
	}
	ans --;
	ans %= mod;
	printf("%lld",ans);
	return 0;
}
