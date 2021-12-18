#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int fa[10010];

int getf(int x){
    if(fa[x] == x){
        return x;
    }
    else{
        return fa[x] = getf(fa[x]);
    }
}
void combine(int x,int y){
    int fx = getf(x);
    int fy = getf(y);
    if(fx == fy){
        return ;
    }
    else{
        fa[fx] = fy;
    }
    return ;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        fa[i] = i;
    }
    for (int i = 1; i <= m; i ++){
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);
        if(z == 1){
            combine(x,y);
        }
        if(z == 2){
            if (getf(x) == getf(y)){
                printf("Y\n");
            }
            else{
                printf("N\n");
            }
        }
    }
    return 0;
}