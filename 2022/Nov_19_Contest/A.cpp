#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
char str[10100];
int cnt[60]; // -64;
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    ll ans = 0;
    ll tar = 0;
    for (int i = 0; i < n; i ++){
        if(!cnt[str[i]-64]){
            tar ++;
            cnt[str[i]-64] = 1;
        }
    }
    for (int i = 0; i < n; i ++){
        int minn = 0x3f3f3f3f, maxx = 0;
        memset(cnt,0,sizeof cnt);
        for (int j = i; j < n; j ++){
            int now = str[j] - 64;
            cnt[now] ++;
            minn = min(minn,cnt[now]);
            maxx = max(maxx,cnt[now]);
            if((j - i + 1)%tar != 0 )continue;
            if(minn == maxx){
                ans ++;
                minn = 0x3f3f3f3f, maxx = 0;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}