#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int n,m;

int main(){
    freopen("P1181_4.in","r",stdin);
    freopen("P1181_4.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    int t = 0, seg = 1;
    for (int i = 1; i <= n; i ++){
        if(t + a[i] <= m) {
            t += a[i];
        }
        else{
            t = a[i], seg ++;
        }
    } 
    printf("%d",seg);
    return 0;
}


//1 2 3 4 5 6 7 8 9 10 11 12
