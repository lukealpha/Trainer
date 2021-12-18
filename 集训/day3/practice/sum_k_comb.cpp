#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n,k;
int a[25];
bool flag;
void dfs(int sum, int step){
    if(flag){
        return ;
    }
    if(sum == 0){
        flag = true;
        return ;
    }
    if(step<=n){
        for (int i = step;i <= n; i ++){
            sum -=a[i];
            dfs(sum, i + 1);
            sum += a[i];
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n; i ++){
        dfs(k,i);
    }
    if(flag){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
    return 0;
}