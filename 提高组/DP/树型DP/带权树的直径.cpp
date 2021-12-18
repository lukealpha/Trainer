#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 500010;
struct node{
    int to, val;
};
vector<node> e[N];
long long dp[N][2];
void add_edge(int x, int y, int val){
    e[x].push_back(node{y,val});
    e[y].push_back(node{x,val});
    return ;
}

void dfs(int x,int fa){
    if(e[x].size() == 0){
        return ;
    }
    for (int i = 0; i < e[x].size(); i ++){
        if(fa == e[x][i].to){continue; }
        dfs(e[x][i].to,x);
        int st = dp[e[x][i].to][0] + e[x][i].val;
        if(st > dp[x][0]){ dp[x][1] = dp[x][0]; dp[x][0] = st;}
        else if(st > dp[x][1]){dp[x][1] = st;}
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n - 1; i ++){
        int x, y, val;
        scanf("%d%d%d",&x,&y,&val);
        add_edge(x,y,val);
    }
    dfs(1,-1);
    long long ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max(ans, dp[i][1] + dp[i][0]);
    }
    printf("%lld",ans);
    return 0;
}