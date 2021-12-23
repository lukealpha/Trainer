#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 55;
const int maxd = 1e9 + 5;
struct location{
    int x, y;
}loc[maxn];
int fa[maxn], n;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
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
    if(fx == fy){
        return ;
    }
    else fa[fx] = fy;
    return ;
}
bool check(int t){
    for (int i = 1; i <= n; i ++) {fa[i] = i; }
    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            long long len = 0;
            len = abs(loc[i].x - loc[j].x) + abs(loc[i].y - loc[j].y);
            if(len <= t*2){
                combine(i,j);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if(getf(i) == i){
            cnt ++;
        }
    }
    if(cnt == 1){
        return true;
    }
    else return false;
}

int main(){
    n = read();
    for (int i = 1; i <= n; i ++){
        int x = read(), y = read();
        loc[i].x = x;
        loc[i].y = y;
    }
    int l = 1, r = maxd, ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d", ans);
    system("pause");
    return 0;
}