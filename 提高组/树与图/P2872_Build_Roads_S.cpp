#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1010;
int n,m,fa[maxn];
double ans = 0;
struct position{
    int x, y;
}pos[maxn];
struct edge{
    int from, to;
    double dis;
}e[10100000];
int cnt = 0;
void init(){
    for (int i = 1; i <= n; i ++){
        fa[i] = i;
    }
    return ;
}
bool cmp(edge a, edge b){
    return a.dis < b.dis;
}
int getf(int x){
    if(fa[x] == x){
        return x;
    }
    return fa[x] = getf(fa[x]);
}
void combine(int x, int y){
    int fx = getf(x);
    int fy = getf(y);
    if(fx != fy){
        fa[fx] = fy;
    }
    getf(fx);
    return ;
}
void kruskal(){
    for (int i = 1; i <= cnt; i ++){
        int fx = getf(e[i].from);
        int fy = getf(e[i].to);
        if(fx != fy){
            combine(e[i].from,e[i].to);
            ans += e[i].dis;
        }
        
    }
}
int main(){
    //freopen("test.out","w",stdout);
    scanf("%d%d",&n,&m);
    init();
    for (int i = 1; i <= n; i ++){
        scanf("%d%d",&pos[i].x, &pos[i].y);
    }
    for (int i = 1; i <= m; i ++){
        int x, y;
        scanf("%d%d",&x,&y);
        combine(x,y);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = i +1; j <= n; j ++){
            //printf("#%d\n",cnt);
            double dis = 0;
            double xp = pos[i].x - pos[j].x;
            double yp = pos[i].y - pos[j].y;
            dis = sqrt(xp*xp + yp*yp);
            e[++cnt].from = i;
            e[cnt].to = j;
            e[cnt].dis = dis;
        }
    }
    sort(e + 1, e + cnt + 1,cmp);
    kruskal();
    printf("%.2lf",ans);
    return 0;
}