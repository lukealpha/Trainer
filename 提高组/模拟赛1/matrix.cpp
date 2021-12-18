#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long pre[1010][1010];
int input[1010][1010];
int main(){
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i<= n; i++){
        for (int j = 1; j <= m; j ++){
            scanf("%d",&input[i][j]);
        }
    }
    for  (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + input[i][j];
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = i; j <= n;  j ++){
            for (int k = 1; k <= m; k ++){
                double div = pre[k][j] + pre[k - 1][i - 1] - pre[k][i - 1] - pre[k - 1][i];
                double num = pre[k][j] - pre[k][i - 1];
                double res = num/div;
                ans = max(ans,res);
            }
        }
    }
    printf("%.8lf",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}