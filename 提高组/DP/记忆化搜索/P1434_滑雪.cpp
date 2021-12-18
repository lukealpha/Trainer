#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int g[110][110],gt[4][2] = {{0,1},{1,0},{-1,0},{0,-1}},dp[110][110];
bool vis[110][110];
int n,m;
void dfs(int x,int y){
    if(dp[x][y] != 0){
        return ;
    }
    vis[x][y] = 1, dp[x][y] = 1;
    for (int i = 0; i < 4; i ++){
        int tx,ty;
        tx = x + gt[i][0];
        ty = y + gt[i][1];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && g[tx][ty] > g[x][y]){
            dfs(tx,ty);
            dp[x][y] = max(dp[x][y],dp[tx][ty] + 1);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            scanf("%d",&g[i][j]);
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if(!vis[i][j]){
                dfs(i,j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            //printf("%d ",dp[i][j]);
            ans = max(ans,dp[i][j]);
        }
        //printf("\n");
    }
    printf("%d",ans);
    return 0;
}