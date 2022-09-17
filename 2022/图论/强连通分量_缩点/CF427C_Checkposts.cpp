//rejudge
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 200100, maxm = 300100;
const int MOD = 1e9 + 7;
int n,m,fst[maxn],to[maxm],nxt[maxm],tot=1;
int dfn[maxn],low[maxn],s[maxn] ,col[maxn],cnt,scc,top;
ll a[maxn];
priority_queue<int, vector<int>, greater<int> > ans[maxn];

bool instack[maxn];
map<pair<int,int>,bool> E;
void add_edge(int x, int y){
    to[++tot] = y;
    nxt[tot] = fst[x];
    fst[x] = tot;
    return ;
}
void Tarjan(int x){
    dfn[x] = low[x] = ++ cnt;
    s[++top] = x;
    instack[x] = true;
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(!dfn[v]){
            Tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(instack[v]){
            low[x] = min(low[x],dfn[v]);
        }
    }
    if(dfn[x] == low[x]){
        scc++;
        while(s[top] != x){
            int z = s[top --];
            instack[z] = false;
            col[z] = scc;
            ans[col[z]].push(a[z]);
        }
        top --;
        col[x] = scc;
        ans[col[x]].push(a[x]);
        instack[x] = false;
    }
}
int main(){
    memset(fst,-1,sizeof fst);
    scanf("%d",&n);scc = n;
    for (int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    scanf("%d",&m);
    for (int i = 1; i <= m; i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    for (int i = 1; i <= n; i ++){
        if(!dfn[i]){
            Tarjan(i);
        }
    }
    ll res = 0, ct = 1;
    for (int i = n + 1; i <= scc; i ++){
        ll tp = ans[i].top();
        ans[i].pop();
        ll ctt = 1;
        while(!ans[i].empty() && ans[i].top() == tp){
            ans[i].pop();
            ctt ++;
        }
        ct *= (ctt%MOD);
        ct %= MOD;
        res += tp;
    }
    printf("%lld %lld",res,ct);
    return 0;
}