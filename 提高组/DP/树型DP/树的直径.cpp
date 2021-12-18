#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 10010;
vector<int> e[N];
int dp[N][2];
void add_edge(int x, int y){
    e[x].push_back(y);
    e[y].push_back(x);
    return ;
}

void dfs(int x,int fa){
    if(e[x].size() == 0){
        return ;
    }
    for (int i = 0; i < e[x].size(); i ++){
        if(fa == e[x][i]){continue; }
        dfs(e[x][i],x);
        int st = dp[e[x][i]][0] + 1;
        if(st > dp[x][0]){ dp[x][1] = dp[x][0]; dp[x][0] = st;}
        else if(st > dp[x][1]){dp[x][1] = st;}
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n - 1; i ++){
        int x, y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    dfs(1,-1);
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max(ans, dp[i][1] + dp[i][0]);
    }
    printf("%d",ans);
    return 0;
}