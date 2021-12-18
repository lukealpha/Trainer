#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#define ls 0
#define hs 1001
using namespace std;
const int MAXN = 1010;

struct sp{
    int x,y,z;
}p[1010];

int fa[MAXN];
int getf(int x){
    if(fa[x] == x){
        return x;
    }
    else{
        return fa[x] = getf(fa[x]);
    }
}
void combine(int n1, int n2){
    int f1 = getf(n1);
    int f2 = getf(n2);
    if(f1 == f2){
        return ;
    }
    else{
        fa[f1] = f2;
    }
    return;
}

double get_distance(int n1, int n2){
    double x1 = p[n1].x; double y1 = p[n1].y; double z1 = p[n1].z;
    double x2 = p[n2].x; double y2 = p[n2].y; double z2 = p[n2].z;
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1 -z2)*(z1 -z2));
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(p, 0, sizeof p);
        memset(fa, 0, sizeof fa);
        fa[ls] = ls;
        fa[hs] = hs;
        int n,h,r;
        scanf("%d%d%d",&n,&h,&r);
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
            fa[i] = i;
            if(p[i].z - r <= 0 ){
                combine(ls,i);
            }
            if(p[i].z + r >= h){
                combine(hs,i);
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i ++){
            for (int j = i + 1; j <= n; j ++){
                double dist = get_distance(i,j);
                if(dist <= r*2){
                    combine(i,j);
                }
                if(getf(ls) == getf(hs)){
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(getf(ls) == getf(hs)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    
    return 0;
}