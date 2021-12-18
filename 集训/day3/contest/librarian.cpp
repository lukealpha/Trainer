#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int a[1010];
int n,q;
int check(int l,int x){
    for (int i = 1; i <= n ; i ++){
        int l1 = 0;
        int tmp = a[i];
        int tmp_x = x;
        while(tmp != 0){
            if(tmp % 10 == tmp_x % 10){
                l1 ++;
                tmp = tmp / 10;
                tmp_x = tmp_x / 10;
            }
            else{
                break;
            }
        }
        if(l1 >= l){
            return a[i];
        }
    }
    return -1;
}
int main(){
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= q; i ++){
        int l, x;
        scanf("%d%d", &l, &x);
        printf("%d\n", check(l, x));
    }
    return 0;
}