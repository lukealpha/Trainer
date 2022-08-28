#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 55;
const int INF = 0x3f3f3f3f;
int n,m,a[maxn][maxn],dp[maxn][maxn][2]; // dp[i][j][0/1] 表示第i个格子最多能引水覆盖的城市l, r
int vis[maxn][maxn];
int tg[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int lmax, rmax;
void dfs(int nx,int ny){
    if(dp[nx][ny][0] != INF && dp[nx][ny][1] != -1){
        lmax = min(lmax,dp[nx][ny][0]);
        rmax = max(rmax,dp[nx][ny][1]);
        return ;
    }
    vis[nx][ny] = true;
    if(nx == n)
        lmax = min(lmax,ny), rmax = max(rmax,ny);
    for (int i = 0; i < 4; i ++){
        int tx = nx + tg[i][0], ty = ny + tg[i][1];
        if (a[tx][ty] <= a[nx][ny] && tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty]){
            dfs(tx,ty);
        }
    }
    return ;
}
void init(){

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if(vis[i][j]) dp[i][j][0] = lmax, dp[i][j][1] = rmax;

            vis[i][j] = 0;
        }
    }
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
        
        lmax= INF, rmax = -1;
        dfs(1,i);
        init();
        printf("%d %d\n",lmax,rmax);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            printf("[%d, %d] ",dp[i][j][0], dp[i][j][1]);
        }
        puts("");
    }
    return 0;
}