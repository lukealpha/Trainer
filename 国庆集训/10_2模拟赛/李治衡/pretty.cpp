#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1010;

ll f[maxn][10][128],P;
int n;
int md(int x, int digit){
    int modifier = 1 << digit;
    x = x | modifier;
    return x;
}
long long calc(long long rev){
    int pow = n;
    long long ans = 1;
    long long base = 10;
    while(pow){
        if(pow & 1){
            ans *= base;
            ans %= P;
        }
        base = ((base%P) * (base%P))%P;
        pow >>= 1;
    }
    return ((ans + P) - rev % P) % P;
}
int main(){
    freopen("pretty.in","r",stdin);
    freopen("pretty.out","w",stdout);
    scanf("%d%lld",&n,&P);
    for (int i = 0; i <= 6; i ++){
        f[1][i][i] = 1;
    }
    f[1][0][0] ++;
    f[1][1][1] ++;
    f[1][2][2] ++;
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= 6; j ++){
            for (int k = 0; k <= 127; k ++){
                for (int l = 0; l <= 6; l ++){
                    int x = md(k,l);
                    if(x != 127){
                        int cnt = 0;
                        for (int m = 0; m <= 9; m ++){
                            if((j + m) % 7 == l){
                                cnt ++;
                            }
                        }
                        f[i + 1][l][x] += ((f[i][j][k])%P * cnt)%P;
                        f[i + 1][l][x] %= P;
                    }
                }
            }
        }
    }
    long long rev = 0;
    for (int i = 0; i <= 6; i ++){
        for (int j = 0; j <= 127; j ++){
            rev += f[n][i][j];
            rev %= P;
        }
    }
    long long ans = calc(rev);
    printf("%lld",ans);
    return 0;
}


