//改范围
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k,cnt,ans;
struct question{
    long long x, y;
    int rel;
}q[100010];

long long a[200010];
int fa[200010],rel[200010];
void init(){
    for (int i = 1; i <= cnt; i ++){
        fa[i] = i;
        rel[i] = 0;
    }
}
int getf(int x){
    if(fa[x] == x) return x;
    int t = getf(fa[x]);
    rel[x] = (rel[x] + rel[fa[x]]) % 3;
    return fa[x] = t;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= k; i ++){
        scanf("%d%lld%lld",&q[i].rel,&q[i].x,&q[i].y);
        if(q[i].x > n || q[i].y > n){
            i --;
            k --;
            ans ++;
            continue;
        }
        a[++cnt] = q[i].x;
        a[++cnt] = q[i].y;
    }
    sort(a + 1, a + cnt + 1);
    cnt = unique(a + 1, a + 1 + cnt) -a -1;
    for (int i = 1; i <= k; i ++){
        q[i].x = lower_bound(a + 1, a + 1 + cnt, q[i].x) - a;
        q[i].y = lower_bound(a + 1, a + 1 + cnt, q[i].y) - a;
    }
    init();
    for (int i = 1; i <= k;i ++){
        int x = q[i].x, y = q[i].y, z = q[i].rel;
        if(q[i].rel == 1){ 
            z = 0;
        }
        if(q[i].rel == 2){
            z = 1;
            if(x == y){
                ans ++;
                continue;
            }
        }
        int fx = getf(x);
        int fy = getf(y);
        if(fx != fy){
            fa[fx] = fy;
            rel[fx] = (rel[y] + z - rel[x])%3;
        }
        else if((rel[x] - rel[y] + 3) % 3 != z){
            ans ++;
        }
    }
    printf("%d",ans);
    return 0;
}