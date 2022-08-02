#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100010
#define MAXM 400010
using namespace std;

int head[MAXN], to[MAXM], nxt[MAXM], cnt = 1;
void add_edge(int u, int v) {
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
    return ;
}
bool flag[MAXM];
int outnode[MAXN], innode[MAXN], ans[MAXN], tt;
int type, n, m;
void dfs(int x) {
    for (int &i = head[x]; i; i = nxt[i]) {
        int y = to[i];
        int c = (type == 1 ? i / 2 : i - 1);
        int sig = i % 2;

        if (flag[c])
            continue;

        flag[c] = 1;
        dfs(y);

        if (type == 1)
            ans[++tt] = (sig ? -c : c);
        else
            ans[++tt] = c;
    }
}

int main() {
    scanf("%d", &type);
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add_edge(x, y);

        if (type == 1) {
            add_edge(y, x);
        }

        ++ outnode[x];
        ++ innode[y];
    }

    if (type == 1) {
        for (int i = 1; i <= n; i ++) {
            if ((innode[i] + outnode[i]) % 2) {
                printf("NO");
                return 0;
            }
        }
    } else {
        for (int i = 1; i <= n; i ++) {
            if (innode[i] != outnode[i]) {
                printf("NO");
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (head[i]) {
            dfs(i);
            break;
        }
    }
    if (tt != m) {
        printf("NO");
        return 0;
    }
    printf("YES\n");

    for (int i = m; i >= 1; i --) {
        printf("%d ", ans[i]);
    }

    return 0;
}