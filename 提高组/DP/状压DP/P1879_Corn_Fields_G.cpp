#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;
int g[15];
int st[1 << 13], gs[1 << 13], scnt = 0;
long long dp[15][1 << 13];
const long long MOD = 100000000;
int n,m;

bool valid_cross_row(int s1, int s2){
    int b1 = st[s1];
    int b2 = st[s2];
    if((b1 & b2) == 0){
        return true;
    }
    return false;
}
bool valid_gr_sit(int s,int row){
    int b = st[s];
    if((b | g[row]) == g[row]){
        return true;
    }
    return false;
}

void init(){
    for (int i = 0; i <= (1 << m); i ++){
        if(((i << 1) & i)  == 0){
            st[++ scnt] = i;
        }
        gs[scnt] = i;
    }
    for (int i  = 1; i <= scnt; i ++){
        if(valid_gr_sit(i,1))
            dp[1][i] = 1;
    }
}

int main(){
    scanf("%d%d",&n,&m);

    for (int i = 1; i <= n; i ++){
        int cur_g = 0; 
        for (int j = 1; j <= m; j ++){
            int input;
            scanf("%d",&input);
            cur_g += int(pow(2,(m - j))) * input;
        }
        g[i] = cur_g;
    }
    init();
    for (int i = 2; i <= n; i ++){
        for (int j = 1; j <= scnt; j ++){
            for (int k = 1; k <= scnt; k ++){
                if(valid_cross_row(j,k) && valid_gr_sit(j,i)){
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= scnt; i ++){
        ans += dp[n][i];
        ans %= MOD;
    }
    printf("%lld",ans);
    return 0;
}