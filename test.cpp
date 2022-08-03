#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 100010, maxm = 2000050;
int astar[maxn],val_c[maxm];
int head_c[maxn],to_c[maxm],nxt_c[maxm],cnt = 0;
int n, m, s;
struct Edge{
    int id;
    int value;
    bool operator < (const Edge &a) const{
        return value > a.value;
    }
};
void add_edge(int x, int y, int value){
    to_c[++cnt] = y;
    val_c[cnt] = value;
    nxt_c[cnt] = head_c[x];
    head_c[x] = cnt;
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
int main(){
    for (int i = 1; i <= m; i ++){
        int x,y,val;
        add_edge(x,y,val);
    }
    Astar(s);
    for (int i = 1; i <= n; i ++){
        printf("%d",astar[i]);
    }
    return 0;
}