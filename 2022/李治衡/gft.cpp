#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 110;
int f1[maxn][maxn],f2[maxn][maxn];
int main(){
    freopen("gft.in","r",stdin);
    freopen("gft.out","w",stdout);
    f1[0][0] = 1;
    f2[0][0] = 1;
    int a,b,n;
    scanf("%d%d%d",&n,&a,&b);
    for (int i = 1; i <= a; i ++){
        f1[i][0] = 1;
        f1[i][1] = f1[i - 1][0];
        f1[i][2] = f1[i - 1][1];
        for (int j = 3; j <= n; j ++){
            f1[i][j] = f1[i][j - 2] + f1[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= b; i ++){
        f2[i][0] = 1;
        f2[i][2] = f2[i - 1][0];
        for (int j = 3; j <= n; j ++){
            f2[i][j] = f2[i][j - 2] + f2[i - 1][j - 0];
        }
    }
    for (int i = 0; i <= n; i ++){
        printf("%d %d\n",f1[a][i],f2[b][n - i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}