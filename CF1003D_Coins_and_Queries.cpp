#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
const int maxn = 35;
int a[maxn];
int split[maxn];
int n,q;
int main(){
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i ++){
        ll val;
        scanf("%lld",&val);
        int p = 0;
        while(val > 1){
            val >>= 1;
            ++ p;
        }
        a[p] ++;
    }
    while(q--){
        ll x;
        scanf("%lld",&x);
        int p = 0;
        while(x){
            if(x & 1)
                split[p] = 1;
            else
                split[p] = 0;
            p ++;
            x >>= 1;
        }
        bool splited = true;
        int ans = 0;
        for (p = p - 1;p >= 0; p --){
            if(split[p]){
                ans += min(split[p],a[p]);
            }
            split[p] = max(0,split[p] - a[p]);
            if(split[p]){
                if(!p){
                    splited = false;
                    break;
                }
                split[p - 1] += split[p] * 2;
                split[p] = 0;
            }
        }
        if(splited){
            printf("%d\n",ans);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}