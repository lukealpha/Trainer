#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#define maxn 2000010
using namespace std;
int n;
vector<int> e[maxn];
int node[maxn];
long long psum[maxn], pmax[maxn];
void add_edge(int u, int v){
    e[u].push_back(v);
    e[v].push_back(u);
}
int main(){
    //freopen("test.in","r",stdin);
    scanf("%d",&n);
    for (int i = 1; i <= n - 1; i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    for (int i = 1; i <= n; i ++){
        scanf("%d",&node[i]);
    }
    long long ans = 0;
    long long mx = -0x3f3f3f3f;
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j < e[i].size(); j ++){
            psum[j + 1] = psum[j] + node[e[i][j]];
            pmax[j + 1] = max(pmax[j], (long long)(node[e[i][j]]));
        }

        for (int j = 1; j <= e[i].size(); j ++){
            ans += psum[j - 1] * node[e[i][j- 1]];
            ans %= 10007;
            long long mul = pmax[j - 1] * node[e[i][j - 1]];
            mx = max(mx, mul);
        }
        for (int j = 1; j <= e[i].size(); j ++){
            pmax[j] = 0;
            psum[j] = 0;
        }
    }
    ans = ans * 2;
    ans %= 10007;
    printf("%lld %lld",mx,ans);
    return 0;
}