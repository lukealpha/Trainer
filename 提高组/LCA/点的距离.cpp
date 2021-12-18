#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

#define MAXN 1000005
using namespace std;
int n,t,x,y,tot;
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
int main(){
    cin >>n;
    for (int i = 1; i < n ; i++){
        scanf("%d%d",&x,&y);
        addedge(x,y);
    }
    init(1,0);

    cin>>t;
    while (t -- )   {
        scanf("%d%d",&x,&y);
        printf("%d\n",dis(x,y));
    }
    return 0;
}
/*
6
1 2
1 3
2 4
2 5
3 6
2
2 6
5 6
*/