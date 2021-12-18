#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
struct Node{
    ll pos, ti;
    bool operator < (const Node a) const{
        return ti < a.ti;
    }
}c[100110];
bool cmp(Node a, Node b){
    return a.pos < b.pos;
}
ll n,m;
ll now, pb, ak;
priority_queue<Node> q;

int main(){
    //c[0].pos = 0;
    scanf("%lld%lld",&n,&m);
    for (ll i = 1; i <= n; i ++){
        scanf("%lld%lld",&c[i].pos, &c[i].ti);
    }
    sort(c + 1, c + n + 1, cmp);
    for (ll i = 1; i <= n; i ++){
        now += c[i].pos - c[i - 1].pos;

        q.push(Node{c[i].pos,c[i].ti});
        pb ++;
        now += c[i].ti;
        if(now > m){
            while(q.size()&& now > m){
                pb --;
                now -= q.top().ti;
                q.pop();
            }
        }
        if(now > m){
            break;
        }
        ak = max(ak,pb);
    }
    printf("%lld",ak);
    return 0;
}