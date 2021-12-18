#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 200010;
int arr[maxn], p;
struct segment{
    int l,r;
    long long val = 0 ,mark_add = 0, mark_mul = 1;
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
    seg[x].val %= p;
    return ;
}

void release(int x){
    if(seg[x].l < seg[x].r){
        int lch = x * 2;
        int rch = x * 2 + 1;
        seg[lch].val *= seg[x].mark_mul;
        seg[lch].val += (long long)(seg[lch].r - seg[lch].l + 1) * seg[x].mark_add;
        seg[lch].mark_add += seg[x].mark_add;
        seg[lch].mark_mul *= seg[x].mark_mul;
        seg[lch].val %= p; seg[lch].mark_add %= p; seg[lch].mark_mul %= p;
        seg[rch].val *= seg[x].mark_mul;
        seg[rch].val += (long long)(seg[rch].r - seg[rch].l + 1) * seg[x].mark_add;
        seg[rch].mark_add += seg[x].mark_add;
        seg[rch].mark_mul *= seg[x].mark_mul;
        seg[rch].val %= p; seg[rch].mark_add %= p; seg[rch].mark_mul %= p;
    }
    seg[x].mark_add = 0;
    seg[x].mark_mul = 1;
    return ;
}

void modify_add(int x, int l, int r, long long k){
    release(x);
    if(l <= seg[x].l && seg[x].r <= r){
        seg[x].val += k * (long long)(seg[x].r - seg[x].l + 1);
        seg[x].mark_add += k;
        seg[x].val %= p;
        seg[x].mark_add %= p;
        return ;
    }
    int mid = (seg[x].l + seg[x].r) >> 1;
    if(l <= mid){
        modify_add(x * 2, l, r, k);
    }
    if(r > mid){
        modify_add(x * 2 + 1, l, r, k);
    }
    seg[x].val = seg[x * 2].val + seg[x * 2 + 1].val;
    seg[x].val %= p;
    return ;
}
void modify_mul(int x, int l, int r, long long k){
    release(x);
    if(l <= seg[x].l && seg[x].r <= r){
        seg[x].val *= k ;
        seg[x].mark_add *= k;
        seg[x].mark_mul *= k;
        seg[x].val %= p; seg[x].mark_add %= p; seg[x].mark_mul %= p;
        return ;
    }
    int mid = (seg[x].l + seg[x].r) >> 1;
    if(l <= mid){
        modify_mul(x * 2, l, r, k);
    }
    if(r > mid){
        modify_mul(x * 2 + 1, l, r, k);
    }
    seg[x].val = seg[x * 2].val + seg[x * 2 + 1].val;
    seg[x].val %= p;
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
    return ans % p;
}

int main(){
    int n,m;
    scanf("%d%d%d",&n,&m,&p);
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
            modify_mul(1,x,y,k);
        }
        if(opt == 2){
            int x,y;
            long long k;
            scanf("%d%d%lld",&x,&y,&k);
            modify_add(1,x,y,k);
        }
        if(opt == 3){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}