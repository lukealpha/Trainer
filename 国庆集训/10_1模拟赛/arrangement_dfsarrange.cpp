#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int p[55];
int s[55];
int q[55];
int n;
int ans = 0;
void dfs(int x, int last){
    if(x >= n){
        /* for (int i = 1; i <= n - 1; i ++){
            printf("%d ",q[i]);
        }
        printf("\n"); */
        for (int i = 1; i <= n; i ++){
            s[i] = i;
        }
        for (int i = 1; i <= n - 1; i ++){
            swap(s[q[i]],s[q[i] + 1]);
        }
        bool flag = true;
        for (int i = 1; i <= n; i ++){
            if(s[i] != p[i]){
                flag = false;
            }
        }
        if(flag) {
            /* for (int i = 1; i <= n - 1; i ++){
                printf("%d ",q[i]);
            }
            puts(""); */
            ans ++;
        }
        //puts("");
        return ;
    }
    for (int i = 1; i <= n; i ++){
        if(i != last){
            q[x] = i;
            dfs(x + 1, i);
            q[x] = 0;
        }
    }
}
int main(){
    //freopen("test.in","r",stdin);
    //freopen("test1.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&p[i]);
    }
    dfs(1,-1);
    cout << ans;
    return 0;
}