#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1010;
const int maxm = 10010;
int h[maxn],to[maxm],nxt[maxm],w[maxm],idx;
int dist[maxn];bool vis[maxn];
int cnt[maxn];
int n,m;
void add_edge(int a, int b, int c){
    to[++idx] = b;
    w[idx] = c;
    nxt[idx] = h[a];
    h[a] = idx;
    return ;
}
bool spfa(int s){
    memset(dist,0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    memset(vis,0,sizeof vis);
    dist[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        s = q.front();
        q.pop();
        vis[s] = 0;
        for (int i = h[s];i;i=nxt[i]){
            int t = to[i];
            if(dist[t] > dist[s] + w[i]){
                dist[t] = dist[s] + w[i];
                cnt[t] = cnt[s] + 1;
                if(cnt[t] >= n)return 0;
                if(!vis[t]){
                    q.push(t);
                    vis[t] = 1;
                }
            }
        }
    }
    return 1;
}
int main(){

    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add_edge(a,b,-c);
    }
    int ans = 0;
    bool flag = 0;
    flag = spfa(1);
    if(!flag){
        printf("Forever love\n");
        return 0;
    }
    ans = dist[n];
    flag = spfa(n);
    if(!flag){
        printf("Forever love\n");
        return 0;
    }
    ans = min(ans,dist[1]);
    printf("%d",ans);
    return 0;
}