#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t --){
        ll n,m,p = 0,q = 0;
        ll pp = 1,qq = 1;
        scanf("%lld%lld",&n,&m);
        while(n%5==0){
            n /= 5;
            p ++;
            pp *= 5;
        }
        while(n%2==0){
            n /= 2;
            q ++;
            qq *= 2;
        }
        ll mag = 1;
        if(p < q){
            while(mag*5<=m && p != q){
                mag *= 5;
                p ++;
                pp *= 5;
            }
        }
        else {
            while(mag*2<=m && p != q){
                mag *= 2;
                q ++;
                qq *= 2;
            }
        }
        while(mag*10<=m){
            mag *= 10;
            p ++, q ++;
            pp *= 5, qq *= 2;
        }
        printf("%lld\n",n*pp*qq*(m/mag));
    }
    return 0;
}