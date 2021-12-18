#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    long long n,k;
    long long sum_k = k;
    scanf("%lld%lld",&n,&k);
    while(sum_k <= n){
        sum_k += k;
    }
    printf("%lld",sum_k);
    return 0;
}