#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define ll long long 
using namespace std;
const int maxn = 2020;
int t;
ll w[maxn], val[maxn];
void init(int x){
    scanf("%lld%lld",&w[x],&val[x]);
    w[x]*=2;
    if(val[x] == 0){
        init(x*2);
        init(x*2+1);
    }
}
ll dp[maxn][maxn];
ll dfs(int x, int tot){
    if(dp[x][tot]>0 || !tot) return dp[x][tot];
    if(val[x]) return dp[x][tot] = min(val[x], (tot - w[x])/5);
    for (int i = 0; i <= tot - w[x]; i ++){
        dp[x][tot] = max(dp[x][tot],dfs(x*2,i)+dfs(x*2+1,tot-w[x] -i));
    }
    return dp[x][tot];
}
int main(){
    scanf("%d",&t);
    t --;
    init(1);
    printf("%lld",dfs(1,t));
    return 0;
}