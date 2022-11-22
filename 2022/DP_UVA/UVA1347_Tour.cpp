#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct Points{
    double x, y;
} point[1010];
double dist[1010][1010];
double dp[1010][1010];
int n;
int main(){
    while (scanf("%d", &n) != EOF){
        for (int i = 1; i <= n; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            point[i].x = x;
            point[i].y = y;
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                dist[i][j] = dist[j][i] = sqrt(pow((point[i].x - point[j].x), 2) + pow((point[i].y - point[j].y), 2));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = int(0x3f3f3f3f);
        dp[2][1] = dist[1][2];
        for (int i = 2; i <= n - 1; i++)
            for (int j = 1; j < i; j++){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist[i][i + 1]);
                dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + dist[j][i + 1]);
            }
        double ans = int(0x3f3f3f3f);
        for (int i = 1; i < n; i++) ans = min(ans, dp[n][i] + dist[n][i]);
        printf("%.2lf\n", ans);
    }
    return 0;
}