#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
int s[310], f[310][310][310], siz[310];
vector<int> e[310];

void dfs(int x){
    siz[x] = 1;
    f[x][1][1] = s[x];
    f[x][1][0] = 0;
    for (int i = 2; i <= e[x].size() + 1; ++i){
        int v = e[x][i - 2];
        dfs(v);
        siz[x] += siz[v];
        for (int j = 0; j <= siz[x]; j ++){
            for (int k = 0; k < min(siz[v] + 1, j); k ++){
                f[x][i][j] = max(f[x][i][j], f[v][e[v].size() + 1][k] + f[x][i - 1][j - k]);
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        int x;
        scanf("%d%d",&x,&s[i]);
        e[x].push_back(i);
    }
    dfs(0);
    printf("%d",f[0][e[0].size() + 1][m + 1]);
    return 0;
}