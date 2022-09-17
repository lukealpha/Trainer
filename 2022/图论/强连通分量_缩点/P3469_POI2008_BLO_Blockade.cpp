
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1e5 + 7, maxm = 5e6 + 7;
int n,m,bcc;
int fst[maxn],to[2*maxm],nxt[2*maxm],tot;
void add_edge(int v, int u){
    to[++tot] = u;
    nxt[tot] = fst[v];
    fst[v] = tot;
}
int cnt = 0,dfn[maxn],low[maxn],s[maxn],pt;//栈中元素为在不折返情况下可能返祖的边指向的点
vector<int> ans[maxn];
ll anspt[maxn];
int Tarjan(int x,int fa){
    int son = 0;
    dfn[x] = low[x] = ++cnt;
    s[++pt] = x;
    int pt_sum = 1;
    int del_sum = 1;
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        int lsum = 0;
        if(!dfn[v]){
            son ++;
            int n_sum = Tarjan(v,x);
            pt_sum += n_sum;
            low[x] = min(low[x],low[v]);
            if(low[v] >= dfn[x]){
                del_sum += n_sum;
                anspt[x] += (long long)(n - n_sum) * (long long)n_sum;
            }
        }
        else {
            low[x] = min(low[x],dfn[v]);
        }
    }
    anspt[x] += (long long)(n - del_sum)*(long long)(del_sum) + (n - 1);
    return pt_sum;
}

int main(){
    memset(fst, -1, sizeof fst);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v); add_edge(v,u);
    }
    for(int i = 1; i <= n; i++) {
		if(dfn[i]) continue;
		pt = 0;
		Tarjan(i, 0);
	}
    for (int i = 1; i <= n; i ++){
        printf("%lld\n",anspt[i]);
    }
    return 0;
}