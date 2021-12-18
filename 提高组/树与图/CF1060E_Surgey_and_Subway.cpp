#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 200010;
vector<int> e[maxn];
int siz[maxn],dep[maxn];
void add_edge(int x, int y){
    e[x].push_back(y);
    e[y].push_back(x);
    return ;
}
void dfs(int d, int x, int fa){
    dep[x] = d;
    for (int i = 0; i < e[x].size(); i ++){
        if(e[x][i] == fa){continue;}
        dfs(d + 1,e[x][i],x);
        siz[x] += siz[e[x][i]];
    }
    siz[x] ++;
}
int main(){
    //remember to recover the data scale.
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n - 1; i ++){
        int x, y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    dfs(0, 1,-1);
    long long ans = 0;
    int odd = 0;
    for (int i = 1; i <= n; i ++){
        ans += siz[i]*(long long)(n - siz[i]);
        if(dep[i]%2==1) odd ++;
    }
    ans += (long long)odd*(long long)(n - odd);
    printf("%lld",ans/2);
    return 0;
}