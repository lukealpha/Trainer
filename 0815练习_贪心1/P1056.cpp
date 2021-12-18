#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
struct rows{
    int pos,val = 0;
}row[1100],column[1100];
bool cmp(rows a, rows b){
    return a.val > b.val;
}
bool cmp1(rows a, rows b){
    return a.pos < b.pos;
}
using namespace std;
int main(){
    //freopen("P1056_2.in","r",stdin);
    //freopen("output.out","w",stdout);
    int m,n,k,l,d;
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for (int i = 1; i <= m; i ++){
        row[i].pos = i;
    }
    for (int i = 1; i <= n; i ++){
        column[i].pos = i;
    }
    for (int i = 1; i <= d; i ++){
        int x,y,p,q;
        cin >> x >> y >> p >> q;
        if (x == p){
            column[min(y,q)].val ++;
        }
        else {
            row[min(x,p)].val ++;
        }
    }
    sort(row + 1, row + m + 1,cmp);
    sort(column + 1, column + n + 1,cmp);
    sort(row + 1, row + k + 1, cmp1);
    sort(column + 1, column + l + 1, cmp1);
    for (int i = 1; i <= k; i ++){
        printf("%d ",row[i].pos);
    }
    printf("\n");
    for (int i = 1; i <= l; i ++){
        printf("%d ",column[i].pos);
    }

    return 0;
}