#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
bool vis[110];
int arr[110];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof vis);
        int n,eq=0;
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++){
            scanf("%d",&arr[i]);
            if(!vis[arr[i]]){
                vis[arr[i]] = 1;
                eq ++;
            }
        }
        if(eq != 2){
            printf("%d\n",n);
        }
        else printf("%d\n",n/2 +1);
    }
    return 0;
}