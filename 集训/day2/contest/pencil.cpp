#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int price[4][2];
int main(){
    //freopen("pencil.in","r",stdin);
    //freopen("pencil.out","w",stdout);
    int n;
    scanf("%d",&n);
    int minn = 0x7fffffff;
    for (int i = 1;i <= 3; i ++){
        int x, y;
        scanf("%d%d",&x,&y);
        int cur = ceil(n*1.0/x*1.0); // ceil要加入cmath
        cur = cur * y;
        minn = min(minn,cur);
    }
    printf("%d",minn);
    return 0;
}