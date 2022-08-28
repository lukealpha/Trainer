#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 550;
const int INF = 0x3f3f3f3f;
int n,m,a[maxn][maxn],dp[maxn][maxn][2]; // dp[i][j][0/1] 表示第i个格子最多能引水覆盖的城市l, r
int vis[maxn][maxn],eli[maxn];
int tg[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
struct section{
    int l, r;
}sec[maxn];
bool cmp(section a, section b){
    return a.r > b.r;
}
void init(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            vis[i][j] =0;
        }
    }
}
void dfs(int nx,int ny){
    if(nx == n){
        eli[ny] = 1;
    }
    if(dp[nx][ny][0] != INF && dp[nx][ny][1]!= -1){
        return ;
    }
    vis[nx][ny] = true;
    for (int i = 0; i < 4; i ++){
        int tx = nx + tg[i][0], ty = ny + tg[i][1];
        if (a[tx][ty] < a[nx][ny] && tx >= 1 && tx <= n + 1&& ty >= 1 && ty <= m && !vis[tx][ty]){
            dfs(tx,ty);
            dp[nx][ny][0] = min(dp[nx][ny][0],dp[tx][ty][0]);
            dp[nx][ny][1] = max(dp[nx][ny][1],dp[tx][ty][1]);
        }
    }
    return ;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            scanf("%d",&a[i][j]);
            dp[i][j][1] = -1;
            dp[i][j][0] = INF;
        }
    }
    for (int i = 1; i <= m; i ++){
        dp[n+1][i][0] = i, dp[n+1][i][1] = i;
    }
    for (int i = 1; i <= m; i ++){
        init();
        dfs(1,i);
    }
    for (int i = 1; i <= m; i ++){
        sec[i].l = dp[1][i][0];
        sec[i].r = dp[1][i][1];
    }
    sort(sec + 1, sec + m + 1, cmp);
    int cnt = 0;
    for (int i = 1; i <= m; i ++){
        if(!eli[i]) cnt ++;
    }
    if(cnt){
        printf("%d\n%d",0,cnt);
        return 0;
    }
    else printf("1\n");
    int i = 1;
    while(i <= m){
        int j;
        for (j = 1; j <= m; j ++){
            if(sec[j].l <= i){
                i = sec[j].r + 1;
                cnt ++;
                break;
            }
        }
        if(j == m + 1){
            printf("-1");
            break;
        }
    }
    printf("%d",cnt);
    return 0;
}