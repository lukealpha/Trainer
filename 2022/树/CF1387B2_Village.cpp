#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1e5 + 7;
int n,fst[maxn],to[maxn*2],nxt[maxn*2],tot=1;
int v[maxn];
void add_edge(int u, int v){
    to[++tot] = v;
    nxt[tot] = fst[u];
    fst[u] = tot;
}
int Size[maxn],weight[maxn],centroid[2],depth[maxn];


void GetCentroid(int cur, int fa){
    Size[cur] = 1;
    weight[cur] = 0;
    for (int i = fst[cur]; i != -1; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        GetCentroid(v,cur);
        weight[cur] = max(weight[cur],Size[v]);
        Size[cur] += Size[v];
    }
    weight[cur] = max(weight[cur],n - Size[cur]);
    if(weight[cur] <= n/2){
        centroid[centroid[0] != 0] = cur;
    }
}
int seq[maxn],cnt = 0,dep[maxn];

void GetNodes(int x, int fa,int dep){
    seq[++cnt] = x;
    depth[x] = dep;
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        GetNodes(v,x,dep+1);
    }
}

int main(){
    memset(fst,-1,sizeof fst);
    scanf("%d",&n);
    for (int i = 1; i < n; i ++){
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(a,b);
        add_edge(b,a);
    }
    GetCentroid(1,0);
    GetNodes(centroid[0],0,0);
    ll ans = 0;
    for (int i = 1; i <= n/2; i ++){
        int a = seq[i], b = seq[i + (n/2)];
        ans += (depth[a] + depth[b])*2;
        v[a] = b;
        v[b] = a; 
    }
    if(n % 2 == 1){
        int a = seq[1], b = seq[1 + n/2], c = seq[n];
        v[a] = c;
        v[b] = a;
        v[c] = b;
        ans += 2*depth[c];
    }
    printf("%lld\n",ans);
    for (int i = 1; i <= n; i ++){
        printf("%d ",v[i]);
    }
    return 0;
}

