#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 5050;
ll a[maxn];bool vis[maxn];
struct pa{
    int x = 0, y = 0;
    ll diff = 0;
}pas[25000010];
int n,cnt = 0;
bool cmp(pa a, pa b){ return a.diff > b.diff; }
int main(){
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
    }
    for (int i = 1; i < n; i ++){
        for (int j = i + 1; j <= n; j ++){
            pas[++cnt].x = i, pas[cnt].y = j;
            pas[cnt].diff = a[j] - a[i];
        }
    }
    sort(pas + 1, pas + cnt + 1,cmp);
    ll ans = 0;
    for (int i = 1; i <= cnt; i ++){
        if(pas[i].diff <= 0){
            break;
        }
        if(vis[pas[i].x] || vis[pas[i].y]){
            continue;
        }
        ans += pas[i].diff;
        vis[pas[i].x] = 1;
        vis[pas[i].y] = 1;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}