#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Blocks
{
    int len[3];
} block[35];
int n, f[35][3]; // k = 0,1,2
int dp(int idx, int k)
{ // 以(idx,k)积木为底的最高高度
    if (f[idx][k] != -1) return f[idx][k];
    int len = 0, wid = 0;
    int& ans = f[idx][k];
    ans = block[idx].len[k];
    for (int i = 0; i <= 2; i++)
    {
        if (i == k)
            continue;
        if (!len) len = block[idx].len[i];
        else wid = block[idx].len[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 2; j++)
        { // j表示枚举新的可能的k
            int nlen = 0, nwid = 0;
            for (int t = 0; t <= 2; t++)
            {
                if (t == j)
                    continue;
                if (!nlen) nlen = block[i].len[t];
                else nwid = block[i].len[t];
            }
            if(nlen < len && nwid < wid){
                ans = max(ans,dp(i,j)+block[idx].len[k]);
            }
        }
    }
    return ans;
}
int main()
{   
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int kase = 0;
    while (scanf("%d", &n) && n != 0)
    {
        memset(f, -1, sizeof f);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2; j++) scanf("%d", &block[i].len[j]);
            sort(block[i].len, block[i].len + 3);
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++){
            for (int k = 0; k <= 2; k ++){
                ans = max(ans,dp(i,k));
            }
        }
        printf("Case %d: maximum height = %d\n",++kase,ans);
    }
    return 0;
}
/*

7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0



*/