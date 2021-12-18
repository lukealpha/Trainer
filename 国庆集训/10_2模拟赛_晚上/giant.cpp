#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2020;
const int mod = 1e9 + 7;

long long f[maxn][maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        f[1][i] = 1;
    }
    for(int i=2;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n/j;k++)
				f[i][j*k]=(f[i][j*k]+f[i-1][j])%mod;
    long long ans = 0;
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++){
            ans += f[i][j];
            ans %= mod;
        }
    }
    cout << ans;

    return 0;
}