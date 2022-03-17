#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MAXN 10050
#define MAXM 50050
using namespace std;
int to[MAXM],nxt[MAXM],head[MAXN],cnt;
inline int read(){
	char ch = getchar(); int x = 0, f = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') x = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
	return x * f;
}
void add_edge(int u, int v){
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
	return ;
}

int n, m, outnode[MAXN], dfn[MAXN], low[MAXN], ttime = 1, color[MAXN], col = 0, col_cnt[MAXN];
int st[MAXN], top = 0, ans = 0;
bool instack[MAXN];

void Tarjan(int now){
	instack[now] = 1;
	st[++top] = now;
	dfn[now] = low[now] = ttime ++;
	for (int i = head[now]; i != -1; i = nxt[i]){
		int j = to[i];
		if(!dfn[j]){
			Tarjan(j);
			low[now] = min(low[j],low[now]);
		}
		else if(instack[j]){
			low[now] = min(low[j],low[now]);
		}
	}
	if (dfn[now] == low[now]){
        ++col;
		while(top){
            color[st[top]] = col;
            if(dfn[st[top]] == low[st[top]]){
                instack[st[top]] = 0;
                top --;
                break;
            }
            instack[top] = 0;
            top --;
		}
	}
    return ;
}
int main(){
	memset(head, -1, sizeof head);
	n = read(), m = read();
	for (int j = 1; j <= m; j ++){
		int a = read(), b = read();
		add_edge(a,b);
	} 
	for (int i = 1; i <= n; i ++){
		if(dfn[i] == 0){
			Tarjan(i);
		}
	}
    for (int i = 1; i <= n; i ++){
        col_cnt[color[i]] ++;
        for (int j = head[i]; j != -1; j = nxt[j]){
            if(color[to[j]] != color[i]){
                outnode[color[i]] ++;
            }
        }
    }
    bool flag = 0;
    for (int i = 1; i <= col; i ++){
        if(outnode[i] == 0){
            if(flag){
                printf("%d",0);
                return 0;
            }
            flag = 1;
            ans = col_cnt[i];
        }
    }
    printf("%d",ans);
    return 0;
}