#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a1[110];
int b1[110];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int i;
        for (i = 1; i <= a; i ++){
            a1[i] = b1[i] = i;
        }
        int j;
        for (j = n; (n-j+1)<=b; j --){
            a1[j] = b1[j] = j;
        }
        int div = abs(i - j);
        while(abs(i-j) <= div){
            a1[i] = i;
            b1[j] = i;
            i ++, j --;
        }
        int pre = 0, suf = 0;
        for (int i = 1; i <= n; i ++){
            if(a1[i] == b1[i]){
                pre ++;
            }
            else break;
        }
        for (int j = n; j >= 1; j --){
            if(a1[j] == b1[j]){
                suf ++;
            }
            else break;
        }
        if(pre == a && suf == b){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}