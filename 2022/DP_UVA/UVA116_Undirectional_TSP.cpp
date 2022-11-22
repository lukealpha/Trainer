#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int a[15][110];
int dp[15][110];//表示走到当前位置能取得的最小TSP
int g[15][110];
int n,m;
int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                scanf("%d",&a[i][j]);
            }
        }
        // init
        memset(dp,0x3f,sizeof dp);
        for (int i = 1; i <= n; i ++){
            dp[i][m] = a[i][m];
        }
        for (int j = m - 1; j >= 1; j --){
            for (int i = 1; i <= n; i ++){
                vector<int> seq;
                seq.push_back(i),seq.push_back(i-1),seq.push_back(i+1);
                if(seq[1] < 1) seq[1] = n;
                if(seq[2] > n) seq[2] = 1;
                sort(seq.begin(),seq.end());
                for(auto v:seq){
                    if(dp[v][j+1]+a[i][j] < dp[i][j]){
                        dp[i][j] = dp[v][j+1]+a[i][j];
                        g[i][j] = v;
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        int last = 0;
        for (int i = 1; i <= n; i ++){
            if(dp[i][1] < ans){
                ans = dp[i][1];
                last = i;
            }
        }
        for (int j = 1, i = last; i&&j<= m; i = g[i][j],j ++){
            printf("%d",i);
            if(j < m)printf(" ");
        }
        puts("");
        printf("%d\n",ans);
    }
    return 0;
}