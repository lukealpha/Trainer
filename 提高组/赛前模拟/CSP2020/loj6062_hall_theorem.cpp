#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 300010;
ll a[maxn],b[maxn];
int c[maxn];
struct segment{
    int l,r;
    long long val = 0 ,mark = 0;
}seg[maxn];

void buildTree(int x, int l, int r){
    seg[x].l = l;
    seg[x].r = r;
    if(l == r){
        seg[x].val = l;
        return ;
    }
    int mid = (l + r) >> 1;
    int lch = x * 2, rch = x * 2 + 1;
    buildTree(lch, l, mid);
    buildTree(rch, mid + 1, r);
    seg[x].val = min(seg[lch].val, seg[rch].val);
    return ;
}

void release(int x){
    if(seg[x].l < seg[x].r && seg[x].mark != 0){
        int lch = x * 2;
        int rch = x * 2 + 1;
        seg[lch].val += seg[x].mark;
        seg[lch].mark += seg[x].mark;
        seg[rch].val += seg[x].mark;
        seg[rch].mark += seg[x].mark;
    }
    seg[x].mark = 0;
    
    return ;
}

void modify(int x, int l, int r, long long k){
    release(x);
    if(l <= seg[x].l && seg[x].r <= r){
        seg[x].val += k;
        seg[x].mark += k;
        return ;
    }
    int mid = (seg[x].l + seg[x].r) >> 1;
    if(l <= mid){
        modify(x * 2, l, r, k);
    }
    if(r > mid){
        modify(x * 2 + 1, l, r, k);
    }
    seg[x].val = min(seg[x * 2].val, seg[x * 2 + 1].val);
}



int main(){
    int n,m;ll h;
    scanf("%d%d%lld",&n,&m,&h);
    for (int i = 1; i <= m; i ++){
        scanf("%lld",&b[i]);
    }
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
        c[i] = m - (lower_bound(b + 1, b + m + 1, h - a[i]) - b) + 1;
    }
    buildTree(1,0,m);
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        modify(1,c[i],m,-1);
        if(i > m){
            modify(1,c[i - m],m, 1);
        }
        if(i >= m){
            ans += (seg[1].val >= 0);
        }
    }
    cout << ans;
    return 0;
}