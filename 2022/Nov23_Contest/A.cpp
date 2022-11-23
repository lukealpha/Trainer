#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll n,s,v,x;
bool check(ll p){
    ll cur=v,nv=v,tim=x;
    for (int i = 1; i <= n; i ++){
        if(cur>p){
            return false;
        }
        if((cur+nv)>p&&tim){
            cur = 0;
            nv += s;
            tim--;
        }
        cur += nv; //每天结束前更新第二天的值
    }
    return true;
}

int main(){
    scanf("%lld%lld%lld%lld",&n,&s,&v,&x);
    ll l = 0, r = 1e12, ans = -1;
    while(l <= r){
        ll mid = (l+r)>>1;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    printf("%lld",ans);
    return 0;
}