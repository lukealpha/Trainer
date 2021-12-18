#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	//freopen("ratio.in","r",stdin);
	//freopen("ratio.out","w",stdout);
    int a,b,l;
    scanf("%d%d%d",&a,&b,&l);
    double de = double(a)/double(b);
    double last = 0x3f3f3f3f;
    int ci,cj;
    for (double i = 1; i <= l; i ++){
        for (double j = 1; j <= l; j ++){
            if(i/j >= de && (i/j - de ) < last){
                last = i/j - de;
                ci = i;
                cj = j;
            }
        }
    }
    printf("%d %d",ci,cj);
    return 0;
}