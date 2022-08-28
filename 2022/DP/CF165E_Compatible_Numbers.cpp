//高维前缀和模板
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1e6 + 7;
int n,a[maxn],f[1 << 22];

int main(){
    scanf("%d",&n);
    int maxx = 0;
    for (int i = 1; i <= n ;i ++){
        scanf("%d",&a[i]);
        f[a[i]] = a[i];
    }
    for (int i = 0; i < 22; i ++){
        for (int j = 0; j <= (1 << 22) - 1; j ++){
            if((j&(1 << i)) && f[j^(1<<i)]) f[j] = f[j^(1 << i)];
        }
    }
    for (int i = 1; i <= n; i ++){
        int b = ((1 << 22) - 1) ^ a[i];
        if(f[b]) printf("%d ",f[b]);
        else printf("%d ",-1);
    }
    return 0;
}