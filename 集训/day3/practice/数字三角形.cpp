#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#define MAXN 21
using namespace std;
int n,sum;
int yh[MAXN][MAXN];
int a[MAXN],vis[MAXN];
bool flag;
void dfs(int step, int cnt){
    if(flag){
        return;
    }
    if(cnt > sum){
        return ;
    }
    if(step == n + 1 && cnt == sum){
        flag = true;
        for (int i = 1; i <= n; i ++){
            printf("%d ",a[i]);
        }
    }
    for (int i = 1; i <= n; i ++){
        if(!vis[i]){
            a[step] = i;
            vis[i] = 1;
            cnt += yh[n][step] * a[step];
            dfs(step + 1, cnt);
            cnt -= yh[n][step] * a[step];
            vis[i] = 0;
        }
    }

}
int main(){
    cin >> n >> sum;
    yh[1][1] = 1;
    for (int i = 2; i <= n; i ++){
        for (int j = 1; j <= i; j ++){
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
        }
    }
    dfs(1,0);
    return 0;
}

//Luogu P1118 预处理 杨辉三角形