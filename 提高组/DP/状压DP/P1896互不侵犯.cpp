#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
long long f[12][1 << 10][90], st[1 << 10], gs[1 << 10], scnt = 0;
int n, k;
void init(){
    for (int i = 0; i <= (1 << n) - 1; i ++){
        if((i & (i << 1)) == 0){
            st[++ scnt] = i;
        }
        else{
            continue;
        }
        int now = i;
        while (now != 0){
            if(now & 1){
                gs[i] ++;
            }
            now = now >> 1;
        }
    }
    for (int i = 1; i <= scnt; i ++){
            f[1][st[i]][gs[st[i]]] = 1;
    }
}

bool valid(int f1, int f2){
    int x1 = ((f1 << 1) & f2);
    int x2 = (f1&f2);
    int x3 = (f1 & (f2 << 1));
    if(x1 == 0 && x2 == 0 && x3 == 0){
        return true;
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&k);
    init();
    valid(1,4);
    for (int i = 2; i <= n ; i ++){
        for (int j = 1; j <= scnt; j ++){
            for (int l = 1; l <= scnt; l ++){
                if(valid(st[j],st[l])){
                    for (int m = gs[st[j]]; m <= k; m ++){
                        f[i][st[j]][m] += f[i - 1][st[l]][m - gs[st[j]]];
                    }
                }
            }
        }
    }
    long long ans = 0;
    /* for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= scnt; j ++){
            for (int m = 0; m <= k; m ++){
                printf("%d ",f[i][st[j]][m]);
            }
            printf("\n");
        }
        printf("---------------------------------------\n");
    } */
    for (int i = 1; i <= scnt; i ++){
        ans += f[n][st[i]][k];
    }
    printf("%lld",ans);
    return 0;
}