//prim算法 + vector邻接表
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int to, val;
};
int n,m;//n个点,m条边
vector<Node> e[310];
bool book[310];
int dis[310];
void add_edge(int from, int to, int val){
    e[from].push_back(Node{to,val});
    e[to].push_back(Node{from,val});
    return ;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i ++){
        int from, to, value;
        scanf("%d%d%d",&from,&to,&value);
        add_edge(from, to, value);
    }
    memset(dis,0x3f,sizeof(dis));
    for (vector<Node>::iterator iter = e[1].begin(); iter != e[1].end(); ++ iter){
        dis[iter -> to] = iter -> val;
    }
    int cnt = 0,mmin = 0x3f3f3f3f,ssum = 0;
    book[1] = 1;
    cnt ++;
    int j;
    while (cnt < n){
        mmin = 0x3f3f3f3f;
        for (int i = 1; i <= n; i ++){
            if(book[i] == 0 && dis[i] < mmin){
                mmin = dis[i];
                j = i;
            }
        }
        book[j] = 1;
        cnt ++;
        ssum += dis[j];
        //printf("%d\n",j);
        for (vector<Node>::iterator iter = e[j].begin(); iter != e[j].end(); ++ iter){
            if(book[iter -> to] == 0 && dis[iter -> to] > iter -> val){
                dis[iter -> to] = iter -> val;
            }
        }
        
    }
    printf("%d",ssum);
    return 0;
}
/*
6 10 
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
*/