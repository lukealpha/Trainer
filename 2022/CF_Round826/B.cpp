#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[200010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        if(n == 1 || n == 3){
            printf("-1\n");
            continue;
        }
        for (int i = 1; i <= n; i ++){
            a[i] = i;
        }
        for (int i = 1; i + 1<= n; i += 2){
            swap(a[i],a[i + 1]);
        }
        if(n%2==1){
            swap(a[n],a[n-2]),swap(a[n],a[n-1]);
            for (int i = n; i >= 1; i --){
                printf("%d ",a[i]);
            }
        }
        else{
            for(int i = 1; i <= n; i ++){
                printf("%d ",a[i]);
            }
        }
        puts("");
    }
    return 0;
}