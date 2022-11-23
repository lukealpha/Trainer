/*
状态的设计: 仍然需要保证无后效性,在i和j确定时，已经开始的字母和已经结束的字母就是确定的，无论做出什么决策，都不会改变这一现状。
搞清楚概念，宁可多写，不要写错，该用的标记数组不要省。
多组数据时，memset要小心。
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[5050], b[5050];
int dp[5050][5050];
int g[5050][5050];
int cnt[30],vis[30];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--){
        memset(vis,0,sizeof vis);
        memset(cnt,0,sizeof cnt);
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        int n = strlen(a + 1);
        int m = strlen(b + 1);
        for (int i = 1; i <= n; i++) cnt[a[i] - 'A']++;
        for (int j = 1; j <= m; j++) cnt[b[j] - 'A']++;
        for (int j = 1; j <= m; j++)
        {
            if (!vis[b[j] - 'A']) g[0][j]++;
            vis[b[j] - 'A']++;
            if (vis[b[j] - 'A'] == cnt[b[j] - 'A']) g[0][j]--;
            g[0][j] = g[0][j - 1] + g[0][j];
        }
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++){
            if (!vis[a[i] - 'A']) g[i][0]++;
            vis[a[i] - 'A']++;
            if (vis[a[i] - 'A'] == cnt[a[i] - 'A']) g[i][0]--;
            g[i][0] = g[i - 1][0] + g[i][0];
            for (int j = 1; j <= m; j++){
                if (!vis[b[j] - 'A']) g[i][j]++;
                vis[b[j] - 'A']++;
                if (vis[b[j] - 'A'] == cnt[b[j] - 'A']) g[i][j]--;
                g[i][j] = g[i][j - 1] + g[i][j];
            }
            for (int j = 1; j <= m; j++) vis[b[j] - 'A']--;
        }
        for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + g[i][0];
        for (int j = 1; j <= m; j++) dp[0][j] = dp[0][j - 1] + g[0][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
        for (int i = 0; i <= n; i ++)
            for (int j = 0; j <= m; j ++)
                g[i][j] = 0;
        printf("%d\n", dp[n][m]);
    }
    return 0;
}