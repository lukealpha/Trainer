#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int b[55];
int vis[1010];
int main(){
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof vis);
        int m,s;
        scanf("%d%d",&m,&s);
        int mm = 0;
        for (int i = 1; i <= m; i ++){
            scanf("%d",&b[i]);
            vis[b[i]] = 1;
            mm = max(mm,b[i]);
        }
        bool flag = true;
        for (int i = 1; s; i ++){
            if(vis[i]) continue;
            if(s < i) {
                flag = false;
                break;
            }
            s -= i;
            vis[i] = 1;
        }
        for (int i = 1; i <= mm; i ++){
            if(!vis[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}