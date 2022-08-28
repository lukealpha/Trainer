#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int maxn = 200010;
map<ll,int> mp;ll a[200010], cnt = 0;
struct inputValue{
    int t,l,r;
}his[maxn];
struct Node{
    int l,r;
    bool _zero, _one;
}seg[4*maxn];
int n;
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        int t; ll l, r;
        scanf("%d%lld%lld",&t,&l,&r);
        a[++cnt] = l, a[++cnt] = r, a[++cnt] = r + 1;
        his[i].t = t, his[i].l = l, his[i].r = r;
    }
    sort(a + 1, a + cnt + 1);
    cnt = unique(a + 1, a + cnt + 1) - a - 1;
    for (int i = 1; i <= cnt; i ++){mp[a[i]] = i;}
    return 0;
}