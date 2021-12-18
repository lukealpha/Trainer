#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int inf=0x3f3f3f3f;
struct node{
    int to;
    long long dist;
    bool operator < (const node &x) const{
        return dist > x.dist;
    }
};
struct edge{
    int from, to , next;
    long long dist;
}e[200001];
priority_queue<node> q;
int n,m,s;
int head[100001], dis[100001],cnt;
bool vis[100001];
void init(){
    memset(head,-1,sizeof head);
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
}
void add(int from, int to, int w){
    e[++cnt].from = from;
    e[cnt].to = to;
    e[cnt].dist = w;
    e[cnt].next = head[from];
    head[from] = cnt;
    return ;
}

int main(){

    init();
    scanf("%d%d%d",&n,&m,&s);
    for (int i = 1; i <= m; i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    dis[s] = 0;
    node t = {s,0};
    q.push(t);
    while(!q.empty()){
        node x = q.top();
        q.pop();
        int u = x.to;
        if(vis[u]){
            continue;
        }
        vis[u] = 1;
        for(int i = head[u];i != -1;i=e[i].next){
            if(dis[e[i].to] > dis[u] + e[i].dist){
                dis[e[i].to] = dis[u] + e[i].dist;
                node t = node{e[i].to,dis[e[i].to]};
                q.push(t);
            }
        }
    }
    for (int i = 1;i <= n; i ++){
        printf("%d ", dis[i]);
    }
    return 0;
}