#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define maxn 100010
using namespace std;
int n,L;
int dp[maxn][2]; //表示从1-i位的最优和次优值 0最优, 1次优
int a[maxn],m[3],x[3],c[3];
int st[1000010];//记录坐标处的石子编号
int opts[5],cnt = 0;
void tr(int i,int t,int path){ //从dp[x][t]尝试转移，通过path;
    int x1 = (dp[i][t]%c[2])/c[1];
    int x2 = (dp[i][t]%c[1])/c[2];
    if(path == 1 && x1 < x[1]){
        opts[++cnt] = dp[i][t] + c[1];
        int nxt = st[a[i] + m[1]];
        dp[nxt][0] = min(dp[nxt][0], dp[i][t] + c[1]);
    }
    if(path == 2 && x2 < x[2]){
        opts[++cnt] = dp[i][t] + c[2];
        int nxt = st[a[i] + m[2]];
        dp[nxt][0] = min(dp[nxt][0], dp[i][t] + c[2]);
    }
    return ;
}
int main(){
    freopen("frog.in","r",stdin);
    freopen("frog.out","w",stdout);
    scanf("%d%d",&n,&L);
    scanf("%d%d%d",&m[1],&x[1],&c[1]);
    scanf("%d%d%d",&m[2],&x[2],&c[2]);
    for (int i = 2; i <= n+1; i ++){
        scanf("%d",&a[i]);
        st[a[i]] = i;
    }
    n = n + 2;
    a[1] = 0, a[n] = L, st[0] = 1, st[L] = n;
    for (int i = 1; i <= n; i ++){
        dp[i][0] = inf, dp[i][1] = inf;
    }
    dp[1][0] = 0;
    for (int i = 2; i <= n; i ++){
        cnt = 0; memset(opts,0x3f,sizeof opts); 
        //处理最优解
        //尝试用最优解转移
        if(st[a[i] - m[1]]){
            tr(st[a[i] - m[1]],0,1);
        }
        if(st[a[i] - m[2]]){
            tr(st[a[i] - m[2]],0,2);
        }
        //尝试用次优解转移 //转移仍要记录次小值
        if(st[a[i] - m[1]]){
            tr(st[a[i] - m[1]],1,1);
        }
        if(st[a[i] - m[2]]){
            tr(st[a[i] - m[2]],1,2);
        }
        //处理次优解
        sort(opts + 1, opts + 5);
        dp[i][1] = opts[2];
    }
    printf("%d",dp[n][0]);
    fclose(stdin);
    fclose(stdout);
    return 0;   
}