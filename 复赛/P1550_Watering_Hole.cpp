//P1550 https://www.luogu.com.cn/problem/P1550
//记录: https://www.luogu.com.cn/record/41045745
//添加超级原点0, 假设为水源, 建设水库的话费转化成水源到牧场的权值, 跑Prim
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int to, val;
};
int n;
vector<Node> e[310];
bool book[310];
int dis[310],graph[310][310];
void add_edge(int from, int to, int val){
    e[from].push_back(Node{to,val});
    return ;
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        int w;
        scanf("%d",&w);
        add_edge(0,i,w);
        add_edge(i,0,w);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            int x;
            scanf("%d",&x);
            add_edge(i,j,x);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for (vector<Node>::iterator iter = e[0].begin(); iter != e[0].end(); ++ iter){
        dis[iter -> to] = iter -> val;
    }
    int cnt = 0,mmin = 0x3f3f3f3f,ssum = 0;
    book[0] = 1;
    cnt ++;
    int j;
    while (cnt < (n + 1)){
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
Test_Data

Input:
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

Output:
9
*/