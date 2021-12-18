#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n,ANS;
void dfs(int step, int ans, int z, int t){
    if(step == 9 && z){
        ans += z * t;
    }
    if(step == 9 && ans == n){
        ANS ++;
    }
    if(step == 9){
        return ;
    }
    dfs(step + 1, ans + z * t, step + 1, 1);
    dfs(step + 1, ans + z * t, step + 1, -1);
    dfs(step + 1, ans, z * 10 + step + 1, t);
}
int main(){
    scanf("%d",&n);
    dfs(1,0,1,1);
    printf("%d",ANS);
    return 0;
}
//https://qzyz.sites.dotkrnl.com/problem/show/1159