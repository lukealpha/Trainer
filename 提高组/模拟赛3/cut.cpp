#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const int maxn = 100000;
int n,m;
vector<int> e[maxn];
ll v[maxn];
void add_edge(int x,int y){
	e[x].push_back(y);
	e[y].push_back(x);
}
void bfs(int x){
	bool vis[maxn];
	for (int i = 0; i <= n; i ++){
		vis[i] = 0;
	}
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		v[now] --;
		for (int i = 0; i < e[now].size(); i++){
			if(!vis[e[now][i]] &&v[e[now][i]] > 0){
				q.push(e[now][i]);
				vis[e[now][i]] = 1;
			}
		}
		
	}
}
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i ++){
		scanf("%d",&v[i]);
	}
	for (int i = 1; i <= m; i ++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	long long ans = 0;
	bool flag = 1;
	while(flag){
		flag = 0;
		for (int i = 1; i <= n; i ++){
			if(v[i] > 0){
				flag = 1;
				bfs(i);
				ans ++;
			}
		}
	}
	
	printf("%lld",ans);
	return 0;
}
/*
3 2
3 2 3
1 2
2 3
*/

