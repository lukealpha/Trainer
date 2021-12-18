#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int p[55];
int n;
long long ans = 0;
void dfs(int x){
    if(x >= n){
        ans ++;
        return ;
    }
    for (int i = 1; i < n; i ++){
        if(p[i] > p[i + 1]){
            swap(p[i],p[i + 1]);
            dfs(x + 1);
            swap(p[i],p[i + 1]);
        }
    }
}
int main(){
    freopen("arrangement.in","r",stdin);
    freopen("arrangement.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&p[i]);
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            if(p[i] > p[j]){
                cnt ++;
            }
        }
    }
    if(cnt != n - 1){
        printf("0");
        return 0;
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}