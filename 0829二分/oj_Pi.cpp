#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,f;
int a[10010];
const double pi = 3.1415926535897;
const double eps = 0.00001;
bool check(double x){
    int num = 0;
    for (int i = 1; i <= n; i ++){
        double cur = a[i]*a[i]*pi;
        while((cur - x) >= 0 ){
            cur -= x;
            num ++;
        }
    }
    return num >= (f + 1);
}
int main(){
    scanf("%d%d",&n,&f);
    int maxx = 0;
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
        maxx = max(maxx, a[i]);
    }
    double l = 0, r = maxx*maxx*pi;
    while((r - l) > eps){
        double mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    printf("%.3lf",l);
    return 0;
}