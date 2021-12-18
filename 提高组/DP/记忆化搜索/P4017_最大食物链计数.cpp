#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 500010;
const int Mod = 80112002;
vector<int> e[maxn];
int n,m;
int indeg[maxn],t[maxn],tcnt = 0;
long long dp[maxn];
bool st[maxn],vis[maxn];
void tsort(){
    queue<int> q;
    for (int i = 1; i <= n; i ++) if(!indeg[i]) q.push(i),st[i] = 1;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        t[now] = ++tcnt;
        for (int i = 0; i < e[now].size(); i ++){
            indeg[e[now][i]] --;
            if(!indeg[e[now][i]]){
                q.push(e[now][i]);
            }
        }
    }
}
void dfs(int x){
    if(dp[x]) return ;
    vis[x] = 1;
    for (int i = 0; i < e[x].size(); i ++){
        if(t[e[x][i]] > t[x]){
            dfs(e[x][i]);
            dp[x] += dp[e[x][i]];
            dp[x] %= Mod;
        }
    }
    dp[x] = max(dp[x],1ll);
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        indeg[y] ++;
    }
    tsort();
    for (int i = 1; i <= n; i ++){
        if(!vis[i]){
            dfs(i);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i ++){
        if(st[i]){
            ans += dp[i];
            ans %= Mod;
        }
    }
    printf("%lld",ans);
    return 0;
}