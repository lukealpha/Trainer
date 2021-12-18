#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct Node{
    long long val; int number;
    bool operator < (const Node &a) const{
        return val < a.val;
    }
};
struct ti{
    long long p,c;
}price[50010];
int n,k;
long long m;
long long now, sum;
bool cmp(ti a, ti b){
    return a.c < b.c;
}
priority_queue<Node> q;
int main(){
    scanf("%d%d%lld",&n,&k,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%lld%lld",&price[i].p,&price[i].c);
    }
    bool flag = true;
    sort(price + 1, price + n + 1,cmp);
    for (int i = 1; i <= k; i ++){
        now += price[i].c;
        q.push(Node{price[i].p - price[i].c});
        if (now>m){flag=false;break;}
        sum++;
    }
    if(!flag){printf("%lld",sum);return 0;}
    for (int i = k + 1; i <= n; i ++){
        long long tmp = 1e18+7;
        if(!q.empty()){
            tmp = q.top().val;
            if(price[i].p - price[i].c > tmp){
                now += (tmp + price[i].c);
                q.pop();q.push(Node{price[i].p - price[i].c,i});
            }
            else now += price[i].p;
            if(now > m) break;
            sum ++;
        }
    }
    printf("%lld",sum);
    return 0;
}