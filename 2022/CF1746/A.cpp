#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int a[55],nxt[55];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i = 1; i <= n; i ++){
            scanf("%d",&a[i]);
            nxt[i - 1] = i;
        }
        int pt = 0, zero = 0,now = 1;
        for (int i =)
    }
    return 0;
}