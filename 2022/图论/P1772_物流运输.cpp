/*
输入时应该输入ocp[p][j] = true
结果写成了ocp[i][j] = true;
long long清字节0x3f和int不一样！不要想当然
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;

const int maxn = 110, maxm = 50, maxe = 4050;
int fst[maxm], to[maxe], nxt[maxe], tot = 1;
bool ocp[maxm][maxn],stat[maxm],vis[maxm];//1表示被占用（不可用）,0表示可用
ll val[maxe],dis[maxm],co[maxn][maxn];
ll dp[maxn];
int n,m,k,e,d;
void add_edge(int x, int y, ll v){
    to[++tot] = y;
    val[tot] = v;
    nxt[tot] = fst[x];
    fst[x] = tot;
    return ;
}
struct Node{
    int id; ll dis;
    bool operator < (const Node &a) const{
        return dis > a.dis;
    }
};
void Dijkstra(){
    memset(vis,0,sizeof vis);
    for (int i = 1; i <= m; i ++){
        dis[i] = (int)0x3f3f3f3f;
    }
    priority_queue<Node> q;
    dis[1] = 0;
    q.push(Node{1,0});
    while(!q.empty()){
        Node now = q.top();
        q.pop();
        if(vis[now.id]) continue;
        vis[now.id] = true;
        for (int i = fst[now.id]; i != -1; i = nxt[i]){
            int v = to[i];
            if(!stat[v]) continue;
            if(dis[now.id] + val[i] < dis[v]){
                dis[v] = dis[now.id] + val[i];
                q.push(Node{v,dis[v]});
            }
        }
    }
}
int main(){
    memset(fst,-1,sizeof fst);
    scanf("%d%d%d%d",&n,&m,&k,&e);
    for (int i = 1; i <= e; i ++){
        int x,y; ll v;
        scanf("%d%d%lld",&x,&y,&v);
        add_edge(x,y,v);
        add_edge(y,x,v);
    }
    scanf("%d",&d);
    for (int i = 1; i <= d; i ++){
        int p,a,b;
        scanf("%d%d%d",&p,&a,&b);
        for (int j = a; j <= b; j ++){
            ocp[p][j] = true;
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = i; j <= n; j ++){
            memset(stat,0,sizeof stat);
            for (int k = 1; k <= m; k ++){
                bool flag = true;
                for (int l = i; l <= j; l ++){
                    if(ocp[k][l]){
                        flag = false;
                        break;
                    }
                }
                if(flag) stat[k] = 1;
            }
            Dijkstra();
            co[i][j] = dis[m];
            //printf("co[%d][%d] = %lld\n",i,j,dis[m]);
        }
    }
    for (int i = 1; i <= n; i ++){
        dp[i] = (int)0x3f3f3f3f;
    }
    dp[0] = -k;
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j < i; j ++){
            ll ans = 1ll*dp[j] + 1ll*co[j + 1][i]*((i - j)*1ll) + 1ll*k;
            dp[i] = min(dp[i], ans);
        }
    }
    printf("%lld", dp[n]);
    return 0;
}