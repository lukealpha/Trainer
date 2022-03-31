#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(){
    int r,m,y;
    scanf("%d%d%d",&r,&m,&y);
    double rate = double(r)/100 + 1;
    long long ans = 1ll*m*int(pow(rate,y));
    printf("%lld",ans);
}