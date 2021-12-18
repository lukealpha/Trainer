#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 805;
struct node{
    int to, val;
    bool operator <(const node a)const{
        return val > a.val;
    }
};
vector<node> e[maxn];
int dis[maxn], vis[maxn];
int nq[maxn], n, m, c;
void add_edge(int x, int y, int val){
    e[x].push_back(node{y, val});
    e[y].push_back(node{x, val});
}
void dij(int x){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[x] = 0;
    priority_queue<node> q;
    q.push(node{x,0});
    while(!q.empty()){
        node now = q.top();
        q.pop();
        if(vis[now.to]) continue;
        vis[now.to] = 1;
        for (int i = 0; i < e[now.to].size(); i ++){
            if(dis[now.to] + e[now.to][i].val < dis[e[now.to][i].to]){
                dis[e[now.to][i].to] = dis[now.to] + e[now.to][i].val;
                q.push(node{e[now.to][i].to, dis[e[now.to][i].to]});
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&c);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&nq[i]);
    }
    for (int i = 1; i <= c; i ++){
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        add_edge(x,y,val);
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i ++){
        dij(i);
        int cnt = 0;
        for (int i = 1; i <= n; i ++){
            cnt += dis[nq[i]];
        }
        ans = min(ans, cnt);
    }
    printf("%d",ans);
    return 0;
}