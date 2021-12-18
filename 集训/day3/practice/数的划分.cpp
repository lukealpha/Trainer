#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int n,m,a[8],s = 0;
void pr(){

    for (int i = 1; i <= m; i ++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void dfs(int k){
    if(n == 0){
        return ;
    }
    if(k == m){
        if(n >= a[k - 1]){
            s ++;
        }
        a[k] = n;
        //pr();
        return ;

    }
    for (int i= a[k - 1]; i <= n/(m - k + 1); i ++){
        a[k] = i;
        n = n - i;
        dfs(k + 1);
        n = n + i;
    }
}
int main(){
    cin >> n >> m;
    a[0] = 1;
    dfs(1);
    printf("%d",s);
    return 0;
}