//两个数的乘积等于两个数的最大公公约数和最小公倍数的乘积
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main(){
    int x,y,ans = 0;
    scanf("%d%d",&x,&y);
    if(x == y) ans --;
    y = y * x;
    for (int i = 1; i <= sqrt(y); i ++){
        if(y % i == 0 && gcd(i,y/i) == x){
            //printf("%d %d\n",i,y/i);
            ans += 2;
        }
    }
    printf("%d",ans);
    return 0;
}