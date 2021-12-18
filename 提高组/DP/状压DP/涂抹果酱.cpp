#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const long long MOD = 1000000;
int n,m,k,scnt;
struct typ{
    int col[6];
}st[300];
int rowk[6], row_current[7], k_st;
long long dp[10010][300];
void def_gen(int column){
    if(column == 0){
        ++scnt;
        bool flag = true;
        for (int i = 1; i <= m; i ++){
            st[scnt].col[i] = row_current[i];
            if(row_current[i] != rowk[i]){
                flag = false;
            }
        }
        if(flag){
            k_st = scnt;
        }
        return ;
    }
    for (int i = 1; i <= 3; i ++){
        if(row_current[column + 1] != i){
            row_current[column] = i;
            def_gen(column - 1);
        }
    }
}
bool valid_crs_row(int n1, int n2){
    typ s1 = st[n1];
    typ s2 = st[n2];
    bool flag = true;
    for (int i = 1; i <= m; i ++){
        if(s1.col[i] == s2.col[i]){
            flag = false;
        }
    }
    return flag;
}
void init(){
    def_gen(m);
    dp[k][k_st] = 1;
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    bool rowk_flag = false;
    for (int i = 1; i <= m; i ++){
        scanf("%d", &rowk[i]);
        if(rowk[i - 1] == rowk[i]){
            rowk_flag = true;
        }
    }
    if(rowk_flag){
        printf("0");
        return 0;
    }
    init();
    for (int i = k - 1; i >= 1; i --){
        for (int j = 1; j <= scnt; j ++){
            for (int l = 1; l <= scnt; l ++){
                if(valid_crs_row(j,l)){
                    dp[i][j] += dp[i + 1][l];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    for (int i = k + 1; i <= n; i ++){
        for (int j = 1; j <= scnt; j ++){
            for (int l = 1; l <= scnt; l ++){
                if(valid_crs_row(j,l)){
                    dp[i][j] += dp[i - 1][l];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    long long ans1, ans2;
    ans1 = ans2 = 0;
    for (int i = 1; i <= scnt; i ++){
        ans1 += dp[1][i];
        ans1 %= MOD;
    }
    for (int i = 1; i <= scnt;i ++){
        ans2 += dp[n][i];
        ans2 %= MOD;
    }
    printf("%lld",(ans1*ans2)%MOD);
    return 0;
}