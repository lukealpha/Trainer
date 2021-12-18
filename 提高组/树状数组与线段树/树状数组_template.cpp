#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define lowbit(x) (x & (-x))
using namespace std;
const int maxn = 500010;
int n,m;
int tarr[maxn];
void add(int x,int y){
    for (;x <= n; x += lowbit(x)) tarr[x] += y;
}
int ask(int x){
    int res = 0;
    for (;x;x -= lowbit(x)) res += tarr[x];
    return res;
}
int query(int l, int r){
    return ask(r) - ask(l - 1);
}
int main(){
    scanf("%d%d",&n,&m);
    int x, last = 0;
    for (int i = 1; i <= n; i ++){
        scanf("%d", &x);
        add(i, x - last);
        last = x;
    }
    for (int i = 1; i <= m; i ++){
        int typ;
        scanf("%d",&typ);
        if(typ == 1){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            add(x,k);
            add(y + 1, -k);
        }
        else if(typ == 2){
            int x;
            scanf("%d",&x);
            printf("%d\n",ask(x));
        }
    }
    return 0;
}
