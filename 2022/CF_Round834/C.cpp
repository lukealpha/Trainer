#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll l,r,x,a,b;
        scanf("%lld%lld%lld%lld%lld",&l,&r,&x,&a,&b);
        if(a == b){
            printf("0\n");
            continue;
        }
        if((b < l || b > r) || (a < l || a > r)) {
            printf("-1\n");
            continue;
        }
        if((r-b) < x && (b-l) < x){
            printf("-1\n");
            continue;
        }
        if(abs(a-b) >= x ){
            printf("1\n");
            continue;
        }
        if((r-a) < x && (a-l) < x){
            printf("-1\n");
            continue;
        }
        if((r-a) >= x && (a-l) < x){
            if((r-b) >= x){
                printf("2\n");
            }
            else printf("3\n");
            continue;
        }
        if((r-a) < x && (a-l) >= x){
            if((b-l) >= x){
                printf("2\n");
            }
            else printf("3\n");
            continue;
        }
        if((r-a) >= x && (a-l) >= x){
            printf("2\n");
            continue;
        }
    }
    return 0;
}