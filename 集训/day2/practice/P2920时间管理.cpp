#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
//long long ans;
ll n,l,r = 0x3f3f3f3f,mid,ans,f;
struct node{
    ll t,s;   
}a[100005];
bool cmp (node a, node b){
    return a.s < b.s;
}
bool check(ll x){
    for (int i = 1; i <= n; i ++){
        if(x + a[i].t <= a[i].s)
            x +=a[i].t;
        else return false;
    }
    f = 1;
    //printf("%d\n",x);
    return true;
}
int main(){
    //freopen("P2920_8.in","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i= 1; i <= n; i ++){
        cin >> a[i].t >>a[i].s;
        r = min(r,a[i].s - a[i].t);
    }
    sort(a + 1, a + 1 + n, cmp);
    l = 0;
    r = 0x7fffffff;
    while (l < r){
        mid = (l + r + 1) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    if(!f) 
        cout << -1;
    else
        cout << l;
    return 0;
}