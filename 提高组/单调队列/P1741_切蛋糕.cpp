#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
const int maxn = 500010;
int n,m;
int a[maxn],sum[maxn];
struct comb{
    int val, pos;
};
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n; i ++){
        sum[i] = sum[i - 1] + a[i];
    }
    deque<comb> q;
    q.push_back(comb{sum[0],0});
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        if(!q.empty() && i - q.front().pos > m){
            q.pop_front();
        }
        if(q.empty()){
            comb tmp;
            tmp.pos = i;
            tmp.val = sum[i];
            q.push_back(tmp);
        }
        else{
            while(!q.empty() && q.back().val >= sum[i]){
                q.pop_back();
            }
            comb tmp;
            tmp.pos = i;
            tmp.val = sum[i];
            q.push_back(tmp);

        }
        ans = max(ans, sum[i] - q.front().val);
    }
    printf("%d",ans);

    return 0;
}