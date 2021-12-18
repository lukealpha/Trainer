#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double ans = a * 0.2 + b * 0.3 + c * 0.5;
    printf("%.0lf\n",ans);
    return 0;
}