#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define lowbit(x) (x&(-x))
int a[80000010];
using namespace std;
int query(int x){
    if(a[x]||x == 1){
        return a[x];
    }
    else{
        if(x%2 == 0){
            return a[x] = log2(lowbit(x)) + query(x/lowbit(x));
        }
        return a[x] = query(3*x+1) + 1;
    }
}
int main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",query(x));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}