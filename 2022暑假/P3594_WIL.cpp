#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 2e6 + 7;
ll p,w[maxn],pre[maxn];
ll q[4*maxn];int head = 1,tail = 0,id[4*maxn];
int n,d;
int main(){
    scanf("%d%lld%d",&n,&p,&d);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&w[i]);
        pre[i] = pre[i - 1] + w[i];
    }
    int l = 1,r = 1;
    q[++tail] = w[1];
    id[tail] = 1;
    int ans = d;
    while (l <= r){
        if(pre[r] - pre[l - 1] - q[head] <= p && r <= n){
            ans = max(r - l + 1,ans);
        }
        if(pre[r] - pre[l - 1] - q[head] <= p && r < n){
            r ++;
        }
        else{
            l ++;
        }
        while(head <= tail && id[head] < l){
            head ++;
        }
        ll max_sum = pre[r] - pre[max(l - 1, r - d)];
        while(head <= tail && max_sum >= q[tail]){
            tail --;
        }
        q[++tail] = max_sum, id[tail] = max(l,r - d + 1);
    }
    printf("%d",ans);
    return 0;
}