#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
double d[10];
double _p[10];
struct Su{
    bool valid = 0;
    double left,right;
}chains[120];
int cnt = 0;
struct gas{
    double d,p;
}st[10];


bool cmp(gas a, gas b){
    return a.p<b.p;
};
int main(){
    double d1,c,d2;
    int n;
    scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&st[0].p,&n);
    st[0].d = 0;
    for(int i = 1; i <= n; i ++){
        scanf("%lf%lf",&st[i].d,&st[i].p);
    }
    sort(st,st + n + 1);
    for (int i = 1; i <= n; i ++){
        double left = st[i].d, right = st[i].d + c*d2;
        double lit = c;

        for (int j = 1;j <= cnt; j ++){
            if(chains[j].left < left && chains[j].right >right){
                lit = 0;
                break;
            }
            else if(chains[j].left < left && chains[j].right < right && chains[j].right > left && chains[j].valid){
                lit -= (chains[j].right - left) / d2;
            }
            else if(chains[j].right > right && chains[j].left < right && chains[j].left >left && chains[j].valid){
                lit -= (right - chains[j].left) / d2;
            }
        }
    }
    return 0;
}