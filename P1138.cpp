#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 10010
using namespace std;
int a[MAXN];
int used[30010];
int cnt = 0;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i ++){
        int x;
        scanf("%d",&x);
        if(!used[x]){
            a[++cnt] = x;
            used[x] = 1;
        }
    }
    sort(a + 1, a + cnt + 1);
    if(k > cnt){
        printf("NO RESULT");
    }
    else{
        printf("%d",a[k]);
    }
    return 0;
}