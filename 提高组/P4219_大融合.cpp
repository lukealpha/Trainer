#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define lowbit(x) (x&(-x))
using namespace std;

const int maxn = 100010;

int n,q;
int qopt[maxn], qx[maxn], qy[maxn] , ld[maxn], rd[maxn], co = 0, fa[maxn];
int BIT[maxn];
vector<int> e[maxn];

void insert(int x, int y){
    e[x].push_back(y);
    e[y].push_back(x);
    return ;
}
void Add(int x, int k){
    if(!x) return ;
    for (;x <= n; x += lowbit(x)){
        BIT[x] += k;
    }
    return ;
}
int Query(int x){
    int ans = 0;
    for (;x > 0; x -= lowbit(x)){
        ans += BIT[x];
    }
    return ans;
}
int Query(int x, int y){
    return Query(y) - Query(x - 1);
}
struct unionSet{
    int fa[maxn];
    void build(){
        for (int i = 1; i <= n; i ++){fa[i] = i;}
    }
    int getf(int x){
        if(fa[x] == x){
            return x;
        }
        else return fa[x] = getf(fa[x]);
    }
    void combine(int x, int y){
        int fx = getf(x);
        int fy = getf(y);
        if(fx != fy){
            fa[fx] = fy;
        }
    }
}uni;
void dfs_ord(int x, int fat){
    ld[x] = ++ co;
    fa[x] = fat;
    for (int i = 0; i < e[x].size(); i ++){
        if(e[x][i] ^ fat) dfs_ord(e[x][i], x);
    }
    rd[x] = co;
    return ;
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= q; i ++){
        char opt[2];
        int x,y;
        scanf("%s%d%d",opt,&x,&y);
        if(opt[0] == 'A'){
            qopt[i] = 0;
            qx[i] = x;
            qy[i] = y;
            insert(x,y);
        }
        if(opt[0] == 'Q'){
            qopt[i] = 1;
            qx[i] = x;
            qy[i] = y;
        }
    }
    uni.build();
    for (int i = 1; i <= n; i ++){
        if(!ld[i]){dfs_ord(i,0);}
    }
    for (int i = 1; i <= n; i ++){
        Add(ld[i], 1);
        Add(fa[ld[i]], -1);
    }
    long long ans = 0;
    for (int i = 1; i <= q; i ++){
        int x = qx[i], y = qy[i];
        if(ld[x] < ld[y]) swap(x,y);
        int t = 0;
        t = Query(ld[x],rd[x]);
        if(qopt[i]){
            ans = (long long)t * (long long)(Query(ld[uni.getf(y)], rd[uni.getf(y)]) - t);
            printf("%lld\n",ans);
        } 
        else{
            int fy = uni.getf(y);
            Add(ld[y], t);
            uni.combine(x,uni.getf(y));
            Add(ld[fa[uni.getf(y)]],-t);
        }
    }
    return 0;
}