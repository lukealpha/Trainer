#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,p,k;
int ll[1010], rr[1010], dp[];
struct segment{
    int l, r;
}seg[1010];
int cnt = 0;
void init(){
    scanf("%d%d%d",&n,&p,&k);
    int l_num, r_num, last;
    scanf("%d",&l_num);
    last = 1 - k;
    for (int i = 1; i <= l_num; i ++){
        scanf("%d",&ll[i]);
    }
    scanf("%d",&r_num);
    for (int i = 1; i <= r_num; i ++){
        scanf("%d",&rr[i]);
    }
    for (int i = 1; i <= l_num; i ++){
        if(ll[i] - last + 1 > k){
            seg[cnt].r = ll[i - 1];
            seg[++cnt].l = ll[i];
            last = ll[i];
        }
        if(i == l_num) seg[cnt].r = ll[i];
    }
    last = 1 - k;
    for (int i = 1; i <= r_num; i ++){
        if(rr[i] - last + 1 > k){
            if(i != 1) seg[cnt].r = rr[i - 1];
            seg[++cnt].l = rr[i];
            last = rr[i];
        }
        if(i == r_num) seg[cnt].r = rr[i];
    }
    for (int i = 1; i <= cnt; i ++){
        printf("%d %d\n",seg[i].l, seg[i].r);
    }
}
int main(){
    init();
    int len
    return 0;
}