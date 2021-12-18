#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
int s,p;

struct cur{
    int x,y;
}pos[510];

struct E{
    int u,v;
    double w;
    bool used;
}edge[260100];
int cnt = 0;
bool cmp(E a,E b){
    return a.w < b.w;
}
int fa[510];
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
double getl(int a1,int a2){
    double val;
    val = sqrt((pos[a1].x-pos[a2].x)*(pos[a1].x-pos[a2].x) + (pos[a1].y-pos[a2].y)*(pos[a1].y-pos[a2].y));
    return val;
}
int main(){
    scanf("%d%d",&s,&p);
    if(s >= p){
        printf("0.00");
        return 0;
    }
    for (int i = 1; i <= p ; i ++){
        scanf("%d%d",&pos[i].x,&pos[i].y);
    }
    for (int i = 1; i <= p; i ++){
        for (int j = 1; j <= p;j ++){
            if(i != j){
                edge[++cnt].u = i;
                edge[cnt].v = j;
                edge[cnt].w = getl(i,j);
            }
        }
    }
    sort(edge + 1, edge + cnt + 1, cmp);
    for (int i = 1; i <= p; i ++){
        fa[i] = i;
    }
    int last = 0;
    for (int i = 1; i <= cnt; i ++){
        int fu = getf(edge[i].u);
        int fv = getf(edge[i].v);
        if(fu != fv){
            combine(fu,fv);
            edge[i].used = true;
            last = i;
        }
    }
    if(s == 1){
        printf("%.2lf\n",edge[last].w);
        return 0;
    }
    int reversed = 0;
    for (int i = last; i >= 1; i --){
        if(reversed == s - 1){
            if(!edge[i].used) continue;
            printf("%.2lf\n",edge[i].w);
            break;
        }
        if(edge[i].used){
            reversed ++ ;
        }
    }
    return 0;
}