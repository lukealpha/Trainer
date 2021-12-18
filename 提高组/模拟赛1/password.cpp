#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
char input[100010];
const int MOD = 1e9 + 7;
long long ans = 0, power[100010];
int cnt;
int pm[100010][2];
int se[100010][2];
void init(){
    int base = 1;
    for (int i = 1; i <= 100000; i ++){
        power[i] = base;
        base *= 2;
        base %= MOD;
    }
}
int check(int x){
    int i;
    int res = 0,res0 = 0;
    for (i = x + 1;input[i] == '1'; i ++){
         ++ res;
    }
    se[++cnt][1] = i - 1;
    for (i = x;input[i] == '0'; i --) ++ res0;
    se[cnt][0] = i;
    pm[cnt][0] = res0;
    pm[cnt][1] = res;
    long long ksum = 0;
    for (int i = 1; i <= res0; i ++){
        ksum += power[i];
        ksum %= MOD;
    }
    ans += ksum * res;
    pm[cnt][1] += ksum * res;
    pm[cnt][1] %= MOD;
    
    ans %= MOD;
    return res + 1;
}
int main(){
    //freopen("password.in","r",stdin);
    //freopen("password.out","w",stdout);
    cnt = 0;
    init();
    scanf("%s",input + 1);
    int len = strlen(input + 1);
    int next_s = 1;
    for (int i = 1; i <= len; i += next_s){
        
        if(input[i] == '0' && input[i + 1] == '1'){
            next_s = check(i);
        }
        else{
            next_s = 1;
        }
    }
    for (int i = 2; i <= cnt; i ++){
        if(se[i - 1][1] == se[i][0]){
            long long ksum = 0;
            for (int j = 1; j <= pm[i-1][0]; j ++){
                ksum += power[j];
                ksum %= MOD;
            }
            ksum = ksum * pm[i][1];
            ksum %= MOD;
            ans += ksum;
            ans %= MOD;
            pm[i][0] += pm[i - 1][0];

        }
    }
    printf("%lld",ans);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}