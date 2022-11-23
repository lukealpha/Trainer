#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int L, n;
int d[55], dp[55][55];
int main()
{
    while (scanf("%d", &L) && L != 0)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &d[i]);
        }
        d[n + 1] = L;
        for (int i = 1; i <= n; i++)
        {
            dp[i][i + 1] = d[i + 1] - d[i - 1];
        }
        for (int len = 3; len <= n + 1; len++)
        {
            for (int i = 1; i + len - 1 <= n + 1; i++)
            {
                int j = i + len - 1;
                dp[i][j] = 0x3f3f3f3f;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[j] - d[i - 1]);
                }
            }
        }
        printf("The minimum cutting is %d.\n", dp[1][n + 1]);
    }
    return 0;
}