//P1194 https://www.luogu.com.cn/problem/P1194
//思路同P1550建立超级原点, 注意输入距离为0时代表不建立边
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int to, val;
};
int n,a;
vector<Node> e[510];
bool book[510];
int dis[510];
void add_edge(int from, int to, int val){
    e[from].push_back(Node{to,val});
    return ;
}
int main(){
    scanf("%d%d",&a,&n);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            int x;
            scanf("%d",&x);
            if(x != 0)
                add_edge(i,j,x);
        }
    }
    for (int i = 1; i <= n; i ++){
        add_edge(i,0,a);
        add_edge(0,i,a);
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