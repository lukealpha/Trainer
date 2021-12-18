#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 700300;
int arr[500010];
struct segment{
    int l,r;
    long long val = 0 ,mark = 0;
}seg[maxn];

void buildTree(int x, int l, int r){
    seg[x].l = l;
    seg[x].r = r;
    if(l == r){
        seg[x].val = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    int lch = x * 2, rch = x * 2 + 1;
    buildTree(lch, l, mid);
    buildTree(rch, mid + 1, r);
    seg[x].val = seg[lch].val + seg[rch].val;
    return ;
}

void release(int x){
    if(seg[x].l < seg[x].r && seg[x].mark != 0){
        int lch = x * 2;
        int rch = x * 2 + 1;
        seg[lch].val += (long long)(seg[lch].r - seg[lch].l + 1) * seg[x].mark;
        seg[lch].mark += seg[x].mark;
        seg[rch].val += (long long)(seg[rch].r - seg[rch].l + 1) * seg[x].mark;
        seg[rch].mark += seg[x].mark;
    }
    seg[x].mark = 0;
    return ;
}

void modify(int x, int l, int r, long long k){
    release(x);
    if(l <= seg[x].l && seg[x].r <= r){
        seg[x].val += k * (long long)(seg[x].r - seg[x].l + 1);
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
    seg[x].val = seg[x * 2].val + seg[x * 2 + 1].val;
}

long long query(int x, int l, int r){
    release(x);
    if(l <= seg[x].l && seg[x].r <= r){
        return seg[x].val;
    }
    int mid = (seg[x].l + seg[x].r) >> 1;
    long long ans = 0;
    if(l <= mid){
        ans += query(x * 2, l, r);
    }
    if(r > mid){
        ans += query(x * 2 + 1, l, r);
    }
    return ans;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&arr[i]);
    }
    buildTree(1,1,n);
    
    for (int i = 1; i <= m; i ++){
        int opt;
        scanf("%d",&opt);
        if(opt == 1){
            int x,y;
            long long k;
            scanf("%d%d%lld",&x,&y,&k);
            modify(1,x,y,k);
        }
        if(opt == 2){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}