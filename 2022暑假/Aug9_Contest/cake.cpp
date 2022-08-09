#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,ans = inf;
int s[220], lmt[220];
int sel[220],e[220],cnt;
bool judge(){
    cnt = 0;
    memset(e,0,sizeof e);
    for (int i = 1; i <= m; i ++){
        if(!sel[i]) continue;
        cnt ++;
        for (int j = s[i]; j <= s[i] + 8; j ++) e[j] ++;
    }
    for (int i = 1; i <= n; i ++){
        if(e[i] < lmt[i]) return false;
    }
    return true;
}
void dfs(int x){
    if(x > m){
        if(judge()) ans = min(ans,cnt);
        return ;
    }
    for (int i = 1; i >= 0; i --){
        sel[x] = i;
        dfs(x + 1);
    }
}
int main(){
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&lmt[i]);
    }
    for (int i = 1; i <= m; i ++){
        scanf("%d",&s[i]);
    }
    dfs(1);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
}