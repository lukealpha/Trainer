#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 100010;
int n,k;
int prem[maxn];
int num[maxn];
int vis[maxn];
struct segment{
	int l,r;
}sg[maxn];
bool cmp(segment a, segment b){
	return a.r < b.r;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	//printf("hah");
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i ++){
		scanf("%d",&num[i]);
	}
	for (int i = 1; i <= n; i ++){
		prem[i] = prem[i - 1] + num[i];
		prem[i] %= k;
	}
	memset(vis, -1, sizeof vis);
	int cnt = 0;
	for (int i = 0; i <= n; i ++){
		if(vis[prem[i]] == -1){
			vis[prem[i]] = i;
		}
		else{
			sg[++cnt].l = vis[prem[i]] + 1;
			sg[cnt].r = i;
			vis[prem[i]] = i;
		}
	}
	int ans = 1;
	sort(sg + 1, sg + cnt + 1, cmp);
	int rr = sg[1].r;
	for (int i = 2;i <= cnt; i ++){
		if(sg[i].l > rr){
			rr = sg[2].r;
			ans ++;
		}
	}
	printf("%d",ans);
	return 0;
}
