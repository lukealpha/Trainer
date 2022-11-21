#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t[55], d[55], e[55], f[255][55];
bool has_train[255][55][2]; // 0: left; 1: right
const int INF = 0x3f3f3f3f;
int n, T, m1, m2;
int dp(int i, int j)
{
    if (f[i][j] != -1)
        return f[i][j];
    int &ans = f[i][j];
    ans = dp(i + 1, j) + 1;
    if (j > 1 && has_train[i][j][0] && i + t[j - 1] <= T)
    {
        ans = min(ans, dp(i + t[j - 1], j - 1));
    }
    if (j < n && has_train[i][j][1] && i + t[j] <= T)
    {
        ans = min(ans, dp(i + t[j], j + 1));
    }
    return ans;
}
int main()
{
    int kase = 0;
    while (scanf("%d", &n) && n != 0)
    {
        memset(f, -1, sizeof f);
        memset(has_train, 0, sizeof has_train);
        scanf("%d", &T);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &t[i]);
        }
        int m1,m2;
        scanf("%d",&m1);
        for (int k = 1; k <= m1; k ++){
            int a;
            scanf("%d",&a);
            for (int i = a,j = 1; j <= n && i <= T; j ++){
                has_train[i][j][1] = true;
                i += t[j];
            }
        }
        scanf("%d",&m2);
        for (int k = 1; k <= m2; k ++){
            int a;
            scanf("%d",&a);
            for (int i = a, j = n; j >= 1 && i <= T; j --){
                has_train[i][j][0] = true;
                i += t[j-1];
            }
        }
        f[T][n] = 0;
        for (int i = 1; i < n; i++)
        {
            f[T][i] = INF;
        }
        int ans = dp(0, 1);
        printf("Case Number %d: ", ++kase);
        if (ans >= INF)
        {
            printf("impossible\n");
        }
        else
            printf("%d\n", ans);
    }
    return 0;
}