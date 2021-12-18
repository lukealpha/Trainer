#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k,ans;
int a[15],pre[15];
bool visited[15];
void dfs(int step){
    for (int i = 2; i <= n; i ++){
        if(!visited[i] && abs(a[i] - a[pre[step - 1]]) <= k){
            visited[i] = 1;
            pre[step] = i;
            if(step == n && abs(a[pre[step]] - a[1]) <= k){
                ans ++;
            }
            else{
                dfs(step + 1);
            }
            visited[i] = 0;
        }
    }
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin>> a[i];
    }
    if(n == 1){
        ans = 1;
    }
    else{
        visited[1] = 1;
        pre[1] = 1;
        dfs(2);
    }
    printf("%d", ans);
    return 0;
}