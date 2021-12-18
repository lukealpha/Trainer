#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int to;
    int value;
    bool operator < (const Node &a) const {
        return value > a.value;
    }
};
vector<Node> e[100010];
bool visited[100010];
int dis[100010];
int N,M,S;
void add_edge(int x, int y, int value){
    Node edge;
    edge.to  = y;
    edge.value = value;
    e[x].push_back(edge);
}
void Dij(){
    memset(dis,0x3f,sizeof dis);
    dis[S] = 0;
    priority_queue<Node> q;
    q.push(Node{S,0});
    while(!q.empty()){
        Node now = q.top();
        q.pop();
        if(visited[now.to])
            continue;
        visited[now.to] = true;
        for (int i = 0; i < e[now.to].size(); i ++){
            if(dis[now.to] + e[now.to][i].value < dis[e[now.to][i].to]){
                dis[e[now.to][i].to] = dis[now.to] + e[now.to][i].value;
                q.push(Node{e[now.to][i].to,dis[e[now.to][i].to]});
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&N,&M,&S);
    for (int i = 1; i <= M; i ++){
        int tx,ty,value;
        scanf("%d%d%d",&tx,&ty,&value);
        add_edge(tx,ty,value);
    }
    Dij();
    for (int i = 1;i <= N;i ++){
        printf("%d ",dis[i]);
    }
    return 0;
}