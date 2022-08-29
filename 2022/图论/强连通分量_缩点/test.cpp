#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1000010, M = 5000010;
int head[N], ver[M * 2], Next[M * 2];
int dfn[N], low[N], c[N];//c[x] 表示节点 x 所属的“边双连通分量”的编号。
int n, m, tot = 1, num, dcc;
bool bridge[N * 2];
vector<int> ans[N * 2]; //存储各个连通块及其内部节点编号
void add(int x, int y) {//邻接表存图
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}
void tarjan(int x, int in_edge) { //求割边
	dfn[x] = low[x] = ++num;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y, i);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x])
				bridge[i] = bridge[i ^ 1] = true;
		}
		else if (i != (in_edge ^ 1))
			low[x] = min(low[x], dfn[y]);
	}
}
void dfs(int x) {
	c[x] = dcc;
	if (x) //防止加入 0
		ans[dcc].push_back(x); 
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (c[y] || bridge[i]) continue;
		dfs(y);
	}
}
int main(){
	ios::sync_with_stdio(false); //关闭与 scanf 的同步来提速
    cin >> n >> m;
    for (register int i = 1; i <= m; i++) {
    	int x, y;
    	cin >> x >> y;
    	add(x, y), add(y, x);
	}
	for (register int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i, 0);
	for (register int i = 1; i <= n; i++)
		if (!c[i]) {
			++dcc;
			dfs(i);
		}
	cout << dcc << "\n";
	for (register int i = 1; i <= dcc; i++) { //输出
		cout << ans[i].size();
		for (register int j = 0; j < ans[i].size(); j++)
			cout << ' ' << ans[i][j];
		cout << "\n";
	}
    return 0;
}