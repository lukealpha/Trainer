#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxm 100010
#define maxn 20010
using namespace std;
inline int read(){
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
    return x * f;
}
int n,m;
int st[maxn],tail = 0;
int head[maxn], to[maxm],  nxt[maxm], cnt = 0;
int dfn[maxn], low[maxn], col[maxn], instack[maxn], tim, gps, root = 0;
bool is_crp[maxn];
void add_edge(int u, int v){
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
    return ;
}
void Tarjan(int x, int fa){
    st[++tail] = x;
    instack[x] = true;
    dfn[x] = low[x] = ++ tim;
    int mlow = 0;
    int size = 0;
    for (int i = head[x]; i != -1; i = nxt[i]){
        int y = to[i];
        if(dfn[y] == 0 && y != fa){
            Tarjan(y,x);
            low[x] = min(low[x],low[y]);
            mlow = max(mlow, low[x]);
        }
        else if(instack[y] && y != fa){
            low[x] = min(low[x], low[y]);
            mlow = max(mlow, low[x]);
        }
        if(col[y]) size ++;
    }
    if(dfn[x] == low[x]){
        ++gps;
        while(tail){
            int top = st[tail];
            tail --, instack[top] = 0;
            col[top] = gps; 
            if(top == x){
                break;
            }
        }
    }
    if(size >= 2 && x == root){
        is_crp[x] = 1;
    } 
    else if(mlow >= dfn[x]){
        is_crp[x] = 1;
    }
}
int main(){
    memset(head,-1,sizeof head);
    n = read(),m = read();
    for (int i = 1 ; i <= m; i ++){
        int x = read(), y =  read();
        add_edge(x,y);
        add_edge(y,x);
    }
    for (int i = 1; i <= n; i ++){
        if(dfn[i] == 0){
            root = i;
            Tarjan(i, -1);
        }
    }
    for (int i = 1; i <= n; i ++){
        if(is_crp[i]){
            printf("%d\n",i);
        }
    }
    return 0;
}