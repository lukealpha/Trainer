#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1010;
vector<int> e[maxn];
struct bfsn{
    int x,step;
};
int se[maxn][2];
int q[maxn];
bool vis[maxn];
int bfs(int x){
    queue<bfsn> q;
    bfsn tmp;
    tmp.x =x;
    tmp.step = 1;
    q.push(tmp);
    int ans = 0;
    while(!q.empty()){
        bfsn now = q.front();
        q.pop();
        ans = max(ans,now.step);
        for (int i = 0; i < e[now.x].size(); i++){
            if(!vis[e[now.x][i]]){
                vis[e[now.x][i]] = 1;
                bfsn tmp;
                tmp.x = e[now.x][i];
                tmp.step = now.step + 1;
                q.push(tmp);
            }
        }
    }
    return ans;
}
int calc(int x){
    vis[x] = 1;
    int ans = 1;
    for (int i = 0; i < e[x].size(); i ++){
        int tmp = bfs(e[x][i]);
    }
    return ans;
}
int main(){
    freopen("forest.in","r",stdin);
    freopen("forest.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n - 1; i ++){
        int x, y;
        scanf("%d%d",&x,&y);
        se[i][0] = x;
        se[i][1] = y;
    }
    for (int i = 1; i <= n - 1; i ++){
        scanf("%d",&q[i]);
    }
    for (int i = 0; i <=  n - 1; i ++){
        memset(vis, 0, sizeof vis);
        e[se[q[i]][0]].push_back(se[q[i]][1]);
        e[se[q[i]][1]].push_back(se[q[i]][0]);
        int ans = 0;
        for (int i = 1; i <= n; i ++){
            ans += calc(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}