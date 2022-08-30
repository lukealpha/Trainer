#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 100100, maxm = 400100;
int n,m,k,s;
int fst[maxn],nxt[maxm],to[maxm],val[maxm],tot = 1;
ll dis[maxn][110];
int a[maxn];
struct Node{
    int id;
    ll dis;
};
void add_edge(int x,int y,int v){
    to[++tot] = y;
    nxt[tot] = fst[x];
    val[tot] = v;
    fst[x] = tot;
    return ;
}
void Dijkstra(int col){
    bool vis[maxn];
    memset(vis,0,sizeof vis);
    queue<Node> q;
    for (int i = 1; i <= n ; i++){
        if(a[i] == col){
            q.push(Node{i,0});
            dis[i][col] = 0;
        }
    }
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        if(vis[now.id]) continue;
        vis[now.id] = true;
        for (int i = fst[now.id]; i != -1; i = nxt[i]){
            int v = to[i];
            if(dis[now.id][col] + val[i] < dis[v][col]){
                dis[v][col] = dis[now.id][col] + val[i];
                q.push(Node{v,dis[v][col]});
            }
        }
    }
    return ;
}
int main(){
    memset(dis,0x3f,sizeof dis);
    memset(fst,-1,sizeof fst);
    scanf("%d%d%d%d",&n,&m,&k,&s);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= m; i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,1);
        add_edge(v,u,1);
    }
    for (int i = 1; i <= k; i ++){
        Dijkstra(i);
    }
    for (int i = 1; i <= n; i ++){
        sort(dis[i] + 1, dis[i] + k + 1);
        int ans = 0;
        for (int j = 1; j <= s; j ++){
            ans += dis[i][j];
        }
        printf("%d ",ans);
    }
    return 0;
}