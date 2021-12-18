#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e4 + 5;
int st[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int f[maxn];
int n, m, num[10];

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        scanf("%d",&num[i]);
    }
    memset(f,-1,sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if(i - st[num[j]] >= 0){
                f[i] = max(f[i],f[i - st[num[j]]] + 1);
            }
        }
    }
    sort(num + 1, num + m + 1);
    int p = n;
    while (p){
        for (int i = m; i >= 1; i --){
            if(p - st[num[i]] >= 0 && f[p] - 1 == f[p - st[num[i]]]){
                printf("%d",num[i]);
                p = p - st[num[i]];
                break;
            }
        }   
    }
    return 0;
}
/*
11111111111111111111111111111111111111111111111117
71111111111111111111111111111111111111111111111111
*/