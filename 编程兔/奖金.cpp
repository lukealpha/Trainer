#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxm = 20010;

struct que{
    int q[maxn], l = 0, r = 0;
    int front(){return q[l];}
    void push(int x){q[r++]=x;}
    void clear(){l=r=0;}
    void pop(){l ++;}
    bool empty(){return l==r;}
};

bool vis[maxn], con[maxn][maxn];
int head[maxn],nxt[maxm],to[maxm],cnt,ind[maxn],layer[maxn];

void add_edge(int x, int y){
    if(con[x][y] == 1) return ;
    con[x][y] = 1;
    ind[y] ++;
    to[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
    return ;}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for (int i = 1; i <= m; i ++){
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(b,a);
    }

    que q;
    for (int i = 1; i <= n; i ++)
    if(ind[i] == 0)
        q.push(i),layer[i] = 1;
    int ans = 0;
    while(!q.empty()){
        int now = q.front();
        ans += layer[now]-1;
        for (int i = head[now]; i; i = nxt[i]){
            layer[to[i]] = layer[now] + 1;
            ind[to[i]] --;
            if(ind[to[i]] == 0)
                q.push(to[i]);
        }
        q.pop();
    }
    for (int i = 1; i <= n; i ++){
        if(ind[i] != 0){
            printf("-1");
            return 0;
        }
    }
    ans += 100*n;
    printf("%d\n",ans);
    return 0;
}