/*
算法重现：
关键点：栈中存储的边（用边所到达的点来表示了）是可能在不折返的情况下最终返祖的边
一个节点遍历自己的所有儿子，一发现有儿子没能返祖，那么说明它是一个割点，去掉它了以后，它的儿子就无法返祖。
因此以它为边界，刚刚这时候栈中在v之后的所有节点所返回的祖先都在自己所在的子树中，把他们全部找出来，在加上自己，就是一个点双。
因为自身是割点，所以可以把自己形象的理解成一个或多个点双的边界。
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int maxn = 5e5 + 7, maxm = 2e6 + 7;
int n,m,bcc;
int fst[maxn],to[2*maxm],nxt[2*maxm],tot;
void add_edge(int v, int u){
    to[++tot] = u;
    nxt[tot] = fst[v];
    fst[v] = tot;
}
int cnt = 0,dfn[maxn],low[maxn],s[maxn],pt;//栈中元素为在不折返情况下可能返祖的边指向的点
vector<int> ans[maxn];
void Tarjan(int x,int fa){
    int son = 0;
    dfn[x] = low[x] = ++cnt;
    s[++pt] = x;
    for (int i = fst[x]; i != -1; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        if(!dfn[v]){
            son ++;
            Tarjan(v,x);
            low[x] = min(low[x],low[v]);
            if(low[v] >= dfn[x]){
                bcc++;
                while(s[pt] != v){
                    ans[bcc].push_back(s[pt--]);
                }
                ans[bcc].push_back(s[pt--]);
                ans[bcc].push_back(x);
            }
        }
        else {
            low[x] = min(low[x],dfn[v]);
        }
    }
	if(fa == 0 && son == 0) ans[++bcc].push_back(x);
}

int main(){
    memset(fst, -1, sizeof fst);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v); add_edge(v,u);
    }
    for(int i = 1; i <= n; i++) {
		if(dfn[i]) continue;
		pt = 0;
		Tarjan(i, 0);
	}
	printf("%d\n", bcc);
	for(int i = 1; i <= bcc; i++) {
		printf("%d ", int(ans[i].size()));
		for(int j = 0;j < ans[i].size(); j ++) printf("%d ", ans[i][j]);
		printf("\n");
	}
    return 0;
}