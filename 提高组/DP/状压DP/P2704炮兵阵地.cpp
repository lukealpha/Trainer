#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
int n,m;
int g[110];
int dp[110][1 << 10][1 << 10], st[1 << 11], gs[1 << 11], scnt = 0;
bool valid_current_line(int x, int line){
    int n1 = g[x] << 2;
    int n2 = g[x] << 1;
    int n3 = g[x] >> 1;
    int n4 = g[x] >> 2;
    if((n1 & g[x]) == 0 && (n2 & g[x]) == 0 && (n3 & g[x]) == 0 && (n4 & g[x]) == 0){
        return true;
    }
    return false;
}
bool valid_crs_line(int n1, int n2){
    
}
void init(){
    for (int i = 0; i <= 1 << m; i ++){
        int n1 = i << 2;
        int n2 = i << 1;
        int n3 = i >> 1;
        int n4 = i >> 2;
        if((n1 & i) == 0 && (n2 & i) == 0 && (n3 & i) == 0 && (n4 & i) == 0){
            st[++scnt] = i;
            int digit = i;
            while(digit != 0){
                if((digit & 1) == 1){
                    gs[scnt] ++;
                }
                digit = digit >> 1;
            }
        }
    }
    for (int i = 1; i <= scnt; i ++){
        //dp[1][i] = gs[i];
    }
}
int main(){
    scanf("%d%d",&n,&m);
    getchar();
    for (int i = 1; i <= n; i ++){
        int cur_line = 0;
        for (int j = 1; j <= m; j ++){
            char c;
            int p;
            scanf("%c",&c);
            if(c == 'P'){
                p = 1;
            }
            else{
                p = 0;
            }
            cur_line += p * pow(2,(m - j));
        }
        getchar();
        g[i] = cur_line;
    }
    for (int i = 2; i <= n; i ++){
        for (int j = 1; j <= scnt; i ++){
            for (int l = 1; l <= scnt; l ++){
                
            }
        }
    }
    return 0;
}

/*
5 4
PHPP
PPHH
PPPP
PHPP
PHHP


5 4
1011
1100
1111
1011
1001
*/