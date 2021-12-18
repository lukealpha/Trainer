#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 6010;
int n,r[maxn],innode[maxn],f[maxn][2];
vector<int> e[maxn];
void add_edge(int l, int k){
    e[k].push_back(l);
    innode[l] ++;
    return;
}
void dfs(int x, int fa){
    if(!e[x].size()){
        f[x][1] = r[x];
        return ;
    }
    for (int i = 0; i < e[x].size(); i ++){
        dfs(e[x][i],x);
        if(e[x][i] == fa){continue;}
        f[x][1] += f[e[x][i]][0];
        f[x][0] += max(f[e[x][i]][0], f[e[x][i]][1]);
    }
    f[x][1] += r[x];
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&r[i]);
    }
    for (int i = 1; i <= n - 1; i ++){
        int l, k;
        scanf("%d%d",&l,&k);
        add_edge(l,k);
    }
    int fa = 0;

    for (int i = 1; i <= n; i ++){
        if(!innode[i]){fa = i;break;}
    }
    dfs(fa,-1);
    printf("%d",max(f[fa][0],f[fa][1]));

    return 0;
}