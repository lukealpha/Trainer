#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 15
using namespace std;

const double eps = 1e-6;
int n;
double deg[MAXN];
double get_val(double x){
    double ans = 0;
    for (int i = 0; i <= n; i ++){
        ans += (double)deg[i]*pow(x,i);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    double l,r;
    scanf("%lf%lf",&l,&r);
    l *= 1.000000, r*= 1.000000;
    for (int i = n; i >= 0; i --){
        scanf("%lf",&deg[i]);
    }
    while((r - l) >= eps){
        double mid = (2*l + r)/3, mmid = (2*r + l)/3;
        if(get_val(mid) > get_val(mmid)){
            r = mmid;
        }
        else l = mid;
    }
    printf("%.5lf",l);
    system("pause");
    return 0;
}