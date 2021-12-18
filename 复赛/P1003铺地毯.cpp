#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct carpet{
    int a,b,g,k;
}c[10010];
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d%d%d",&c[i].a,&c[i].b,&c[i].g,&c[i].k);
    }
    int x,y;
    scanf("%d%d",&x,&y);
    for (int i = n; i >= 1; i --){
        if(c[i].a <= x && x <= c[i].a + c[i].g && c[i].b <= y && y <= c[i].b + c[i].k){
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}