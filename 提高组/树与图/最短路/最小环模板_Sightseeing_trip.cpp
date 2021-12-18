/*
    [CEOI1999] Sightseeing trip
    https://loj.ac/p/10072
    http://poj.org/problem?id=1734
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 105;
int dis[MAXN][MAXN], mp[MAXN][MAXN], path[MAXN] ,pre[MAXN][MAXN];
int n,m,cnt,ans;
void floyd(){
    for (int k = 1; k <= n; k ++){

        for (int i = 1; i < k; i ++){
            for (int j = i + 1; j < k; j ++){
                if(ans > mp[i][k] + mp[k][j] + dis[i][j]){
                    ans = mp[i][k] + mp[k][j] + dis[i][j];
                    cnt = 0;
                    int t = j;
                    while(t != i){
                        path[++cnt] = t;
                        t = pre[i][t];
                    }
                    path[++cnt] = i;
                    path[++cnt] = k;
                }
            }
        }
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j  ++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }
}
int main(){
    freopen("DebugFiles/test.in","r",stdin);
    freopen("DebugFiles/test.out","w",stdout);
    scanf("%d%d",&n,&m);
    ans = INF;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            pre[i][j] = i;
            mp[i][j] = mp[j][i] = dis[i][j] = dis[j][i] = INF;
        }
    }
    for (int i = 1; i <= m;  i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        dis[u][v] = dis[v][u] = 
        mp[u][v] = mp[v][u] = min(mp[v][u],w);
    }
    floyd();
    if(ans==INF){
        cout<<"No solution."<<endl;
    }
    else{
        for(int i=1;i<cnt;i++){
            cout<<path[i]<<" ";
        }
        cout<<path[cnt]<<endl;
    }
    return 0;
}

/*
TestDataIn:
5 7
1 4 1
1 3 300
3 1 10
1 2 16
2 3 100
2 5 15
5 3 20

TestDataOut:
3 1 2 5
*/