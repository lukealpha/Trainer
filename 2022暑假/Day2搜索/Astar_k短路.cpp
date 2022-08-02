#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 5050, maxm = 200010;
int n,m;double e,val_c[maxm],val[maxm],astar[maxn];
int head_c[maxn],to_c[maxm],nxt_c[maxm],cnt = 0;
int head[maxn],to[maxm],nxt[maxm],cnt = 0;
struct Edge{
    int id;
    double value;
    bool operator < (const Edge &a) const{
        return value > a.value;
    }
};
void add_edge(int x, int y, double value){
    to[++cnt] = y;
    val[cnt] = value;
    nxt[cnt] = head[x];
    head[x] = cnt;
    
    to_c[cnt] = x;
    val_c[cnt] = value;
    nxt_c[cnt] = head[y];
    head_c[y] = cnt;
    return ;
}
void Astar(int x){
    bool vis[maxn];
    memset(astar,0x3f,sizeof astar);
    memset(vis,0,sizeof vis);
    astar[x] = 0;
    priority_queue<Edge> q;
    q.push(Edge{x,0});
    while(!q.empty()){
        int now = q.top().id;
        q.pop();
        if(vis[now]){
            continue;
        }
        vis[now] = true;
        for (int i = head_c[now]; i != -1; i = nxt_c[i]){
            if(astar[now] + val_c[i] < astar[to_c[i]]){
                astar[to_c[i]] = astar[now] + val_c[i];
                q.push(Edge{to_c[i],astar[to_c[i]]});
            }
        }
    }
}
void Dij(){
    
}

int main(){
    memset(head_c, -1, sizeof head_c);
    memset(head, -1, sizeof head);
    scanf("%d%d%lf",&n,&m,&e);
    for (int i = 1; i <= m; i ++){
        int x,y; double val;
        scanf("%d%d%lf",&x,&y,&val);
        add_edge(x,y,val);
    }
    return 0;
}