#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100010],b[100010];
int f[100010][7];
int ma[7];
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n;  i++) {
        scanf("%d%d",&a[i],&b[i]);
    }
    for (int i = 1; i <= n; i ++){
        f[i][a[i]] = f[i - 1][a[i]] + 1;
        f[i][b[i]] = f[i - 1][b[i]] + 1; 
        ma[a[i]] = max(ma[a[i]],f[i][a[i]]);
        ma[b[i]] = max(ma[b[i]],f[i][b[i]]); 
    }
    int max_L = 0, max_P;
    for (int i = 5; i >= 1; i --){
        if(ma[i] >= max_L){
            max_L = ma[i];
            max_P = i;
        }
    }
    printf("%d %d\n",max_L,max_P);
    return 0;
    
}

/*
定义运算
f[i][j] 表示到第i排位置，
*/