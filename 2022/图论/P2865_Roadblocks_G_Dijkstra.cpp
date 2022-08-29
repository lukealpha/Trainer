#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const int maxm = 100010;
const int maxn = 5050;
int fst[maxn], to[maxm*2], nxt[maxm*2], cnt = 0, vis[maxn],vis2[maxn],vis3[maxn];
ll val[maxm*2], dis[maxn][2]; // dis[i][0] 表示到i节点的最短路， dis[i][1] 表示到i节点的次短路
int n,r;

void add_edge(int x, int y, ll v){
    to[++cnt] = y;
    val[cnt] = v;
    nxt[cnt] = fst[x];
    fst[x] = cnt;
    return ;
}
struct Pt{
    int id; ll dis; bool type;
    bool operator < (const Pt &a) const{
        return dis > a.dis;
    }
};
void Dijkstra1(){
    memset(dis,0x3f,sizeof dis);
    dis[1][0] = 0;
    priority_queue<Pt> q;
    q.push(Pt{1,0});
    while(!q.empty()){
        Pt now = q.top();
        q.pop();
        if(vis[now.id]) continue;
        vis[now.id] = true;
        for (int i = fst[now.id]; i != -1; i = nxt[i]){
            int v = to[i];
            if(dis[now.id][0] + val[i] < dis[v][0]){
                dis[v][1] = dis[v][0];
                dis[v][0] = dis[now.id][0] + val[i];
                q.push(Pt{v,dis[v][0]});
            }
        }
    }
}
void Dijkstra2(){
    priority_queue<Pt> q;
    q.push(Pt{1,0,0});
    while(!q.empty()){
        Pt now = q.top();
        q.pop();
        if(now.type == 0 && vis3[now.id]) continue;
        if(now.type == 0) vis3[now.id] = true;
        if(now.type == 1 && vis2[now.id]) continue;
        if(now.type == 1) vis2[now.id] = true;
        for (int i = fst[now.id]; i != -1; i = nxt[i]){
            int v = to[i];
            q.push(Pt{v,dis[v][0],0});
            if(dis[now.id][0] + val[i] < dis[v][1] && dis[now.id][0] + val[i] > dis[v][0]){
                dis[v][1] = dis[now.id][0] + val[i];
                q.push(Pt{v,dis[v][1],1});
            }
            else if(dis[now.id][1] + val[i] < dis[v][1]){
                dis[v][1] = dis[now.id][1] + val[i];
                q.push(Pt{v,dis[v][1],1});
            }
        }
    }
}
int main(){
    memset(fst, -1, sizeof fst);
    scanf("%d%d",&n,&r);
    for (int i = 1; i <= r; i ++){
        int a,b; ll d;
        scanf("%d%d%lld",&a,&b,&d);
        add_edge(a,b,d);
        add_edge(b,a,d);
    }
    Dijkstra1();
    Dijkstra2();
    printf("%lld",dis[n][1]);
    return 0;
}