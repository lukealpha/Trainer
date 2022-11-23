#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
double eps = 1e-15;
struct vec
{
    double x, y;
};
double cross(vec A, vec B)
{
    return A.x * B.y - A.y * B.x;
}
vec linear_addition(vec A, vec B)
{
    vec ans = vec{A.x + B.x, A.y + B.y};
    return ans;
}
vec linear_subtraction(vec A, vec B)
{
    vec ans = vec{A.x - B.x, A.y - B.y};
    return ans;
}
vec point[55];
int n;
void reverse()
{
    vector<vec> res;
    for (int i = 1; i <= n; i++)
        res.push_back(point[i]);
    for (int i = res.size() - 1; i >= 0; i--)
        point[n - i] = res[i];
}
double getS()
{
    double S = 0;
    for (int i = 2; i < n; i++)
    {
        S += cross(linear_subtraction(point[i], point[1]), linear_subtraction(point[i + 1], point[1])) / 2.00;
    }
    return S;
}
bool in_tri(vec a, vec b, vec c, vec p){
    double S = fabs(cross(linear_subtraction(a,b),linear_subtraction(a,c)))/2.0;
    double S1 = fabs(cross(linear_subtraction(a,p),linear_subtraction(a,b)))/2.0;
    double S2 = fabs(cross(linear_subtraction(a,p),linear_subtraction(a,c)))/2.0;
    double S3 = fabs(cross(linear_subtraction(b,p),linear_subtraction(c,p)))/2.0;
    if(fabs(S-(S1+S2+S3)) <= eps) return true;
    else return false;
}
double f[55][55];
double dp(int i, int j)
{ // 表示多边形(i,j)的S_minimax
    if (j == i + 1)
    {
        return 0;
    }
    if (f[i][j] != -1)
        return f[i][j];
    double &ans = f[i][j];
    ans = 1e11 + 7;
    for (int k = i + 1; k < j; k++)
    {
        vec A = linear_subtraction(point[j], point[k]), B = linear_subtraction(point[i], point[k]);
        bool flag = true;
        for (int l = 1; l <= n; l ++){
            if(l == i || l==j || l == k) continue;
            if(in_tri(point[i],point[j],point[k],point[l]))
            {
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        ans = min(ans, max(max(dp(i, k), dp(k, j)), cross(A, B) / 2.00));
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                f[i][j] = -1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            point[i].x = x, point[i].y = y;
        }
        double S = getS();
        if (S < 0)
            reverse();
        double ans = 1e11+7;
        printf("%.1lf\n", dp(1,n));
    }
    return 0;
}
/*
1
6
7 0
6 2
9 5
3 5
0 3
1 1


1
22
280 959
552 715
725 475
822 326
764 442
718 717
577 956
887 960
882 742
928 660
904 198
579 356
838 39
482 108
375 310
265 409
124 594
379 534
73 739
215 818
648 478
697 436


1
7
6 0
4 2
6 6
4 4
2 6
2 4
0 4

6.0



1
9
819 726
892 743
937 371
468 105
818 47
159 57
99 386
253 471
821 883

*/