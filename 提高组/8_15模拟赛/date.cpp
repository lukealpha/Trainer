#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 100010;
using namespace std;
int t,x,y,tot;
int first[MAXN*2],nxt[MAXN*2],to[MAXN*2];
int depth[MAXN];
int f[MAXN][21];
void addedge(int u,int v){
    nxt[++tot] = first[u];
    first[u] = tot;
    to[tot] = v;
    nxt[++tot] = first[v];
    first[v] = tot;
    to[tot] = u;
}
void init(int u, int father){
    depth[u] = depth[father] + 1;
    for (int i = 0; i <= 19; i ++){
        f[u][i + 1] = f[f[u][i]][i];
    }
    for (int e = first[u];e;e = nxt[e]){
        int v = to[e];
        if(v == father){
            continue;
        }
        f[v][0] = u;
        init(v,u);
    }
}
int lca(int x,int y){
    if(depth[x] < depth[y]){
        swap(x,y);
    }
    for (int i = 20; i >= 0; i --){
        if(depth[f[x][i]] >= depth[y]){
            x = f[x][i];
        }
        if(x == y){
            return x;
        }
    }
    for (int i = 20; i >= 0 ; i --){
        if(f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int dis(int x,int y){
    return depth[x] + depth[y] - 2*depth[lca(x,y)];
}
struct dest{
    int x,y;
}dst[MAXN];
int main(){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    int n,m;
    scanf("%d",&n);
    for (int i = 1; i < n; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
    }
    init(1,0);
    scanf("%d",&m);
    for (int i = 1; i <= m; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        dst[i].x = x;
        dst[i].y = y;
    }
    for (int i = 1; i <= m; i ++){
        int cnt = 0;
        for (int j = 1; j <= n; j ++){
            if(dis(j,dst[i].x) == dis(j,dst[i].y)){
                cnt ++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}