#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct E{
    int u,v,w;
}edge[40010];
bool cmp(E a,E b){
    return a.w < b.w;
}
int fa[40010];
int getf(int x){
    if(fa[x] == x){
        return x;
    }
    else{
        fa[x] = getf(fa[x]);
        return fa[x];
    }
}
void combine(int x, int y){
    int fx = getf(x);
    int fy = getf(y);
    if(fx == fy){
        return ;
    }
    else{
        fa[fx] = fy;
    }
}
int ans;
int main(){
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (int i = 1; i <= m; i ++){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= n; i ++){
        fa[i] = i;
    }
    for (int i = 1; i <= m; i ++){
        int fu = getf(edge[i].u);
        int fv = getf(edge[i].v);
        if(fu != fv){
            combine(fu,fv);
            //ans = max(ans,edge[i].w); //多余
        }
        if(getf(s) == getf(t)){
            printf("%d",edge[i].w);
            break;
        }
    }
    return 0;
}