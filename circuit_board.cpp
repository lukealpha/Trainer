// https://loj.ac/p/2632
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 510, cap = 250010;
int li = cap, ri = cap, n, m, dist[maxn][maxn];
pair<int, int> q[cap << 1];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}
char graph[maxn][maxn];
void que_add(int x, int y, int val)
{
    if (val < dist[x][y])
    {
        dist[x][y] = val;
        if (li == ri || val > dist[q[li].first][q[li].second])
        {
            q[ri++] = make_pair(x, y);
        }
        else
        {
            q[--li] = make_pair(x, y);
        }
    }
    return;
}
bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x <= n && y <= m;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", graph[i] + 1);
    }
    if ((n + m) % 2)
    {
        printf("NO SOLUTION\n");
        return 0;
    }
    q[ri++] = make_pair(0, 0);
    memset(dist, 0x3f, sizeof dist);
    dist[0][0] = 0;
    while (li != ri)
    {
        int cx = q[li].first, cy = q[li].second;
        ++li;
        if (valid(cx - 1, cy - 1))
        {
            if (graph[cx][cy] == '\\')
            {
                que_add(cx - 1, cy - 1, dist[cx][cy]);
            }
            else
                que_add(cx - 1, cy - 1, dist[cx][cy] + 1);
        }
        if (valid(cx + 1, cy - 1))
        {
            if (graph[cx + 1][cy] == '/')
            {
                que_add(cx + 1, cy - 1, dist[cx][cy]);
            }
            else
                que_add(cx + 1, cy - 1, dist[cx][cy] + 1);
        }
        if (valid(cx + 1, cy + 1))
        {
            if (graph[cx + 1][cy + 1] == '\\')
            {
                que_add(cx + 1, cy + 1, dist[cx][cy]);
            }
            else
                que_add(cx + 1, cy + 1, dist[cx][cy] + 1);
        }
        if (valid(cx - 1, cy + 1))
        {
            if (graph[cx][cy + 1] == '/')
            {
                que_add(cx - 1, cy + 1, dist[cx][cy]);
            }
            else
                que_add(cx - 1, cy + 1, dist[cx][cy] + 1);
        }
    }
    printf("%d\n", dist[n][m]);
    //system("pause");
    return 0;
}
