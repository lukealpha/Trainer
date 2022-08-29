#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const int maxm = 100010;
const int maxn = 5050;
int fst[maxn], to[maxm*2], nxt[maxm*2], cnt = 0,tims[maxn];
ll val[maxm*2];int n,r;

void add_edge(int x, int y, ll v){
    to[++cnt] = y;
    val[cnt] = v;
    nxt[cnt] = fst[x];
    fst[x] = cnt;
    return ;
}
struct Pt{
    int id; ll dis;
    bool operator < (Pt a) const{
        return a.dis < dis;
    }
};
ll Dijkstra1(){
    priority_queue<Pt> q;
    q.push(Pt{1,0});
    Pt tmp;
    while(!q.empty()){
        Pt now = q.top();
        q.pop();
        tims[now.id] ++;
        if(tims[now.id] == 2 && now.id == n){
            return now.dis;
        }
        if(tims[now.id]> 2) continue;
        for (int i = fst[now.id]; i != -1; i = nxt[i]){
            tmp.id = to[i];
            tmp.dis = now.dis + val[i];
            q.push(tmp);
        }
    }
    return -1;
}

int main(){
    freopen("P2865_2.in","r",stdin);
    memset(fst, -1, sizeof fst);
    scanf("%d%d",&n,&r);
    for (int i = 1; i <= r; i ++){
        int a,b; ll d;
        scanf("%d%d%lld",&a,&b,&d);
        add_edge(a,b,d);
        add_edge(b,a,d);
    }
    cout << Dijkstra1();
    return 0;
}