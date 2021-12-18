#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int n, m, idx = 0, k = 1, cnt = 0;
int head[100];
int dfn[100], low[100], ingroup[100], instack[100];
stack<int> s;
struct edge
{
    int v, next;
}e[100];
void addedge(int u, int v)
{
    e[k].v = v;
    e[k].next = head[u];
    head[u] = k++;
}
void tarjan(int u)
{
    int v;
    dfn[u] = low[u] = ++idx;                      //每次 dfs，缺省 u 的次序号增加 1
    s.push(u);                                    //将 u 入栈
    instack[u] = 1;                               //标记 u 在栈内
    for (int i = head[u]; i != -1; i = e[i].next) //访问从u出发的边
    {
        v = e[i].v;
        if (!dfn[v]) //如果 v 没被处理过
        {
            tarjan(v);                    //dfs(v)
            low[u] = min(low[u], low[v]); //u 点能到达的最小次序号是它自己能到达点的最小次序号和连接点 v 能到达点的最小次序号中较小的
        }
        else if (instack[v])
        {
            low[u] = min(low[u], dfn[v]); //如果 v 在栈内，u 点能到达的最小次序号是它自己能到达点的最小次序号和 v 的次序号中较小的
        }
    }
    if (dfn[u] == low[u])
    {
        cnt++;
        do
        {
            v = s.top();
            s.pop();
            instack[v] = 0;
            ingroup[v] = cnt;
        } while (u != v);
    }
}
int main()
{
    int u, v;
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        addedge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dfn[i] << " " << low[i] << endl;
    }
    cout << "total : " << cnt << endl;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ingroup[j] == i)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
/*
6 8
1 2
1 3
2 4
3 4
3 5
4 1
4 6
5 6
*/