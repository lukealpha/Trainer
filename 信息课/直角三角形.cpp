#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= i; j ++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}