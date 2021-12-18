#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int g[11][11],f[11][11][11][11];
int main(){
    scanf("%d",&n);
    while(1){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x == 0 && y == 0 && z == 0){
            break;
        }
        g[x][y] = z;
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            for (int k = 1; k <= n; k ++){
                for (int l = 1; l <= n; l ++){
                    f[i][j][k][l] = max(max(f[i - 1][j][k][l - 1],f[i][j - 1][k][l - 1]),max(f[i - 1][j][k - 1][l],f[i][j - 1][k - 1][l]));
                    if(i == k && j == l){
                        f[i][j][k][l] += g[i][j];
                    }
                    else{
                        f[i][j][k][l] += g[i][j] + g[k][l];
                    }
                }
            }
        }
    }
    printf("%d",f[n][n][n][n]);
    return 0;
}