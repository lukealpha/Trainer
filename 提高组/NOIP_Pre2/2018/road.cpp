#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n;
struct depth{
    int loc,val;
}d[100010];
bool vis[100010];//loc
bool cmp(depth a, depth b){
    return a.val < b.val;
}
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++){
        scanf("%d",&d[i].val);
        d[i].loc = i;
    }
    sort(d + 1, d + n + 1,cmp);
    // for(int i = 1; i <= n; i ++){
    //     printf("%d ",d[i].val);
        
    // }
    int last = 1;
    int p = 1;
    int ans = 0, tim = 1;
    int dep_cnt = 0;
    vis[0] = vis[n + 1] = 1;
    while(last <= n){
        p = last;
        while(d[p].val == d[p + 1].val) p ++;
        ans += (d[p].val - dep_cnt) * tim;
        dep_cnt = d[p].val;
        for (int i = last; i <= p; i ++){
            if(vis[d[i].loc-1] && vis[d[i].loc+1] ){
                tim --;
            }
            else if((!vis[d[i].loc-1]) && (!vis[d[i].loc+1])){
                tim ++;
            }
            vis[d[i].loc] = 1;
        }
        last = p + 1;
    }
    printf("%d",ans);
    return 0;
}