#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 10007;

int n,m;
int sum[100010][2],nt[100010][2];
int color[100010],number[100010];
long long ans = 0;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        scanf("%d",&number[i]);
        number[i] %= MOD;
    }
    for (int i = 1; i <= n; i ++){
        scanf("%d",&color[i]);
        sum[color[i]][i % 2] += number[i];
        nt[color[i]][i % 2] ++;
        sum[color[i]][i % 2] %= MOD;
    }
    for (int i = 1; i <= n; i ++){
        ans += i % MOD * (sum[color[i]][i % 2] + (nt[color[i]][i % 2] - 2) * number[i] % MOD + MOD) % MOD;
        ans %= MOD;
    }
    printf("%d",ans);
    return 0;
}