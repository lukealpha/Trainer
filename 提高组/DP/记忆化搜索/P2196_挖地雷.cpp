#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 25;
int n;
int e[maxn][maxn], dp[maxn],g[maxn],l[maxn],op[maxn],cnt = 0;
bool vis[maxn];
void dfs(int x){
    if(dp[x]){
        return ;
    }
    dp[x] = g[x];
    for (int i = 1; i <= n; i ++){
        if(e[i][x] == 1){
            if(dp[i] + g[x] > dp[x]){
                dp[x] = dp[i] + g[x];
                l[x] = i;
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&g[i]);
    }
    for (int i = 1; i <= n - 1; i ++){
        for (int j = i + 1; j <= n; j ++){
            scanf("%d",&e[i][j]);
            e[j][i] = e[i][j];
        }
    }
    for (int i = 1; i <= n; i ++){
        if(!vis[i]){
            dfs(i);
        }
    }
    int ans = 0, ansi;
    for (int i = 1; i <= n; i ++){
        if(dp[i] > ans){
            ans = dp[i];
            ansi = i;
        }
    }
    while(ansi){
        op[++cnt] = ansi;
        ansi = l[ansi];
    }
    for (int i = cnt; i >= 1; i --){
        printf("%d ",op[i]);
    }
    printf("\n");
    printf("%d",ans);
    return 0;
}