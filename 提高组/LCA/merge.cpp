#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxm = 310;
int a[maxm], b[maxm],k;
long long dp[maxm][maxm][620];
int main(){
	char s1[maxm],s2[maxm];
	scanf("%s",s1 + 1);
	scanf("%s",s2 + 1);
	scanf("%d",&k);
	int lena = strlen(s1 + 1);
	int lenb = strlen(s2 + 1);
	if(k == lena + lenb){
		getans();		
	} 
	for (int i = 1; i <= lena; i ++){
		a[i] = s1[i] - '0';
	}
	puts("");
	for (int i = 1; i <= lenb; i ++){
		b[i] = s2[i] - '0';
	}
	for (int i = 1; i <= lena; i ++){
		for (int l = 1; l <= k; l ++){
			dp[i][0][l] = max(dp[i - 1][0][l], dp[i - 1][0][l - 1] * 10 + a[i]);
		}
	}
	for (int i = 1; i <= lenb; i ++){
		for (int l = 1; l <= k; l ++){
			dp[0][i][l] = max(dp[0][i - 1][l], dp[0][i - 1][l - 1] * 10 + b[i]);
		}
	}
	for (int i = 1; i <= lena; i ++){
		for (int j = 1; j <= lenb; j ++){
			for(int l = 1; l <= k; l ++){
				long long m1 = dp[i][j - 1][l];
				long long m2 = dp[i - 1][j][l];
				long long m3 = dp[i][j - 1][l - 1] * 10 + b[j];
				long long m4 = dp[i - 1][j][l - 1] * 10 + a[i];
				dp[i][j][l] = max(max(m1,m2),max(m3,m4));
			}
		}
	}
	printf("%lld",dp[lena][lenb][k]);
	return 0;
}
