// https://loj.ac/p/10064 #10064黑暗城堡

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MOD 2147483647
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
}e[1000000];
priority_queue<node> q;
int n,m,s;
long long head[100001], dis[100001],cnt,cntr[100001];
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
    scanf("%d%d",&n,&m);
    s = 1;
    for (int i = 1; i <= m; i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
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
/*     for (int i = 1;i <= n; i ++){
        printf("%d ",dis[i]);
    } */
    cntr[1] = 1;
    for (int i = 1;  i<= n; i ++){
        for (int  j = head[i]; j != -1; j = e[j].next){
            if(dis[i] + e[j].dist == dis[e[j].to]){
                cntr[e[j].to] ++;
            }
        }
    }
    long long ans = 1;
    for (int i = 1;i <= n; i ++){
        ans *= (cntr[i]%MOD);
        ans %= MOD;
        
    }
    printf("%lld",ans);
    return 0;
}