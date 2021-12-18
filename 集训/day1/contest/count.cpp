#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int inp[20010];
int a[110];
int main(){
    //freopen("count.in","r",stdin);
    //freopen("count.out","w",stdout);
    int n, cnt = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
        inp[a[i]] = 1;
    }
    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            if(inp[a[i] + a[j]] == 1){
                inp[a[i] + a[j]] = 2;
                cnt ++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}