#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 10010;
const int maxm = 50010;
const int INF = 0x3f3f3f3f;
int n,m,cnt;
struct Edge1{
    int x, y, val;
    bool operator < (const Edge1 a) const{
        return val > a.val;
    }
}e1[maxm];
struct Edge2{
    int to, val;
};
vector<Edge2> e2[maxn];
int fa[maxn];

int getf(int x){
    if(fa[x] == x) return x;
    else return fa[x] = getf(fa[x]);
}
void kruskal(){
    sort(e1 + 1, e1 + cnt + 1);
    for (int i = 1; i <= n; i ++){
        fa[i] = i;
    }
    for (int i = 1; i <= m; i ++){
        int fx = getf(e1[i].x);
        int fy = getf(e1[i].y);
        if(fx != fy){
            fa[fx] = fy;
            e2[e1[i].x].push_back({e1[i].y,e1[i].val});
            e2[e1[i].y].push_back({e1[i].x,e1[i].val});
        }
    }
    return ;
}
int f[maxn][21],w[maxn][21],dep[maxn];
bool vis[maxn];
void dfs(int node, int fat){
    vis[node] = true;
    for (int j = 1; j <= 20; j ++){
        f[node][j] = f[f[node][j - 1]][j - 1];
        w[node][j] = min(w[node][j - 1],w[f[node][j - 1]][j - 1]);
    }
    for (int i = 0; i < e2[node].size();i ++){
        int to = e2[node][i].to;
        if(to == fat) continue;
        dep[to] = dep[node] + 1;
        f[to][0] = node;
        w[to][0] = e2[node][i].val;
        
        dfs(to,node);
    }
    return ;
}
int lca(int x, int y){
    if(getf(x) != getf(y)) return -1;
    int ans = INF;
    if(dep[x] > dep[y]) swap(x,y);
    for (int i = 20; i >= 0; i --){
        if(dep[f[y][i]] >= dep[x]){
            ans = min(ans,w[y][i]);
            y = f[y][i];
        }
    }
    if(x == y) return ans;
    for (int i = 20; i >= 0; i --){
        if(f[x][i]!= f[y][i]){
            ans = min(ans,min(w[x][i],w[y][i]));
            x = f[x][i];
            y = f[y][i];
        }
    }
    ans = min(ans,min(w[x][0],w[y][0]));
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++){
        int x, y, z;
        scanf("%d%d%d",&x,&y,&z);
        e1[++cnt].x = x;
        e1[cnt].y = y;
        e1[cnt].val = z;
    }
    kruskal();
    for (int i = 1; i <= n; i ++){
        if(!vis[i]){
            dep[i] = 1;
            f[i][0] = i;
            w[i][0] = INF;
            dfs(i,-1);
        }
    }
    int q;
    scanf("%d",&q);
    for (int i = 1; i <= q; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}