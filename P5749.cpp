#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int sum = 1;
    for (int i = 1; i <= n; i ++){
        sum *= i;
    }
    printf("%d",sum);
    return 0;
}