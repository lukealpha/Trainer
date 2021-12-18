#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2010;
int a[maxn];
bool vis[maxn];
int main(){
    freopen("program.in","r",stdin);
    freopen("program.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 2; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n - 1; i ++){
        int x = 1, y = 0;
        a[1] = i;
        bool flag = 0;
        memset(vis,0,sizeof vis);
        while(x > 0 && x <= n){
            
            y += a[x];
            x += a[x];
            y += a[x];
            x -= a[x];
            
            if(x > 0 && x <= n &&vis[x] ) {
                flag = true;
                break;
            }
            if(x > 0 && x <= n )vis[x] = 1;
        }
        if(flag){
            printf("-1 ");
        }
        else{
            printf("%d ",y);
        }
    }
    
    return 0;
}