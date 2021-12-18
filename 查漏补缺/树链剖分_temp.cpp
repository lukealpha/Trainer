#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 100010;
ll p;
struct segment{
	int l, r;
	ll val, tag;
	
}seg[maxn*2 + 9];
ll w[maxn],wt[maxn];


int id[maxn], rd[maxn], fa[maxn], top[maxn], dep[maxn], son[maxn], siz[maxn], cnt = 0;
vector<int> e[maxn];
void add_edge(int x, int y){
	e[x].push_back(y);
	e[y].push_back(x);
	return ;
}
void dfs0(int x, int fat, int deep){
	fa[x] = fat;
	dep[x] = deep;
	siz[x] = 1;
	ll maxson = -1;
	for (int i = 0; i < e[x].size(); i ++){
		if(e[x][i] != fat){
			dfs0(e[x][i], x, deep + 1);
			siz[x] += siz[e[x][i]];
			if(siz[e[x][i]] > maxson){
				son[x] = e[x][i];
				maxson = siz[e[x][i]];
			}
		}
	}
}
void dfs1(int x, int topf){
	id[x] = ++ cnt;
	wt[cnt] = w[x];
	top[x] = topf;
	if(!son[x]) return ;
	dfs1(son[x], topf);
	for (int i = 0; i < e[x].size(); i ++){
		int y = e[x][i];
		if(y != fa[x] && y != son[x]){
			dfs1(y,y);
		}
	}
	rd[x] = cnt;
}
void buildTree(int x, int l, int r){
    seg[x].l = l;
    seg[x].r = r;
    if(l == r){
        seg[x].val = wt[l];
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
    if(seg[x].l < seg[x].r && seg[x].tag != 0){
        int lch = x * 2;
        int rch = x * 2 + 1;
        seg[lch].val += (long long)(seg[lch].r - seg[lch].l + 1) * seg[x].tag; seg[lch].val %= p;
        seg[lch].tag += seg[x].tag; seg[lch].tag %= p;
        seg[rch].val += (long long)(seg[rch].r - seg[rch].l + 1) * seg[x].tag; seg[rch].val %= p;
        seg[rch].tag += seg[x].tag; seg[rch].tag %= p;
    }
    seg[x].tag = 0;
    return ;
}

void Add(int x, int l, int r, long long k){
	k %= p;
    release(x);
    if(l <= seg[x].l && seg[x].r <= r){
        seg[x].val += k * (long long)(seg[x].r - seg[x].l + 1); seg[x].val %= p;
        seg[x].tag += k; seg[x].tag %= p;
        return ;
    }
    int mid = (seg[x].l + seg[x].r) >> 1;
    if(l <= mid){
        Add(x * 2, l, r, k);
    }
    if(r > mid){
        Add(x * 2 + 1, l, r, k);
    }
    seg[x].val = seg[x * 2].val + seg[x * 2 + 1].val;
	seg[x].val %= p;
	return ;
}

ll Query(int x, int l, int r){
    release(x);
    if(l <= seg[x].l && seg[x].r <= r){
        return seg[x].val % p;
    }
    int mid = (seg[x].l + seg[x].r) >> 1;
    long long ans = 0;
    if(l <= mid){
        ans += Query(x * 2, l, r);
    }
    if(r > mid){
        ans += Query(x * 2 + 1, l, r);
    }
    return ans % p;
}

void path_Addition(int x, int y ,ll z){
	z %= p;
	while(top[y] != top[x]){
		if(dep[top[x]] > dep[top[y]]) swap(x,y);
		Add(1,id[top[y]],id[y],z);
		y = fa[top[y]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	Add(1,id[x],id[y],z);
	return ;
}

ll path_Query(int x, int y){
	ll ans = 0;
	while(top[y] != top[x]){
		if(dep[top[x]] > dep[top[y]]) swap(x,y);
		ans += Query(1,id[top[y]],id[y]);
		ans %= p;
		y = fa[top[y]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	ans += Query(1,id[x],id[y]);
	return ans % p;
}
ll sub_Query(int x){
	ll ans = 0;
	ans = Query(1,id[x],id[x] + siz[x] - 1);
	return ans;
}
void sub_Addition(int x, ll z){
	Add(1,id[x],id[x] + siz[x] - 1,z);
	return ;
}
int main(){
	int n,m,r;
	scanf("%d%d%d%lld",&n,&m,&r,&p);
	for (int i = 1; i <= n; i ++){
		scanf("%lld",&w[i]);
	}
	for (int i = 1; i <= n - 1; i ++){
		int x, y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	dfs0(r, 0, 1);
	dfs1(r, r);
	buildTree(1, 1, n);
	for (int i = 1; i <= m; i ++){
		int opt;
		scanf("%d",&opt);
		if(opt == 1){
			int x, y;
			ll z;
			scanf("%d%d%lld",&x,&y,&z);
			path_Addition(x,y,z);
		}
		if(opt == 2){
			int x, y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",path_Query(x,y));
		}
		if(opt == 3){
			int x;
			ll z;
			scanf("%d%lld",&x,&z);
			sub_Addition(x,z);
		}
		if(opt == 4){
			int x;
			scanf("%d",&x);
			printf("%lld\n",sub_Query(x));
		}

	}
	return 0;
}