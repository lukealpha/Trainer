#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 5050, maxm = 200010;
int n,m;
ll val_c[maxm],val[maxm],astar[maxn];
int head_c[maxn],to_c[maxm],nxt_c[maxm],cnt = 0;
int head[maxn],to[maxm],nxt[maxm];
int ct = 0;
struct Edge{
    int id;
    ll value, g;
    bool operator < (const Edge &a) const{
        return value > a.value;
    }
};
void add_edge(int x, int y, ll value){
    to[++cnt] = y;
    val[cnt] = value;
    nxt[cnt] = head[x];
    head[x] = cnt;
    
    to_c[cnt] = x;
    val_c[cnt] = value;
    nxt_c[cnt] = head_c[y];
    head_c[y] = cnt;
    return ;
}
void Astar(int x){
    bool vis[maxn];
    for (int i = 1; i <= n; i ++){astar[i] = 0x3f3f3f3f;}
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
void Dij(int x){
    bool vis[maxn];
    memset(vis,0,sizeof vis);
    priority_queue<Edge> q;
    q.push(Edge{x,astar[x],0});
    while(!q.empty()){
        Edge now = q.top();
        q.pop();
        if(now.id == n){
            ct ++;
            if(ct == 2){
                printf("%lld",now.g);
                break;
            }
        }
        for (int i = head[now.id]; i != -1; i = nxt[i]){
            q.push(Edge{to[i],now.value + val[i] + astar[to[i]],now.g + val[i]});
        }
    }
}

int main(){
    memset(head_c, -1, sizeof head_c);
    memset(head, -1, sizeof head);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int x,y; ll d;
        scanf("%d%d%lld",&x,&y,&d);
        add_edge(x,y,d);
        add_edge(y,x,d);
    }
    Astar(n);
    Dij(1);
    return 0;
}