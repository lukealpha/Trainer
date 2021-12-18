#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
priority_queue<int, vector<int>, greater<int> > q1; //大根堆
priority_queue<int, vector<int>, less<int> > q2; //小根堆

struct Node{
    int a,b;
    bool operator < (const Node x) const{
        return b < x.b; //重载运算符 大根堆 （记得return）
    }
};
priority_queue<Node> e;//结构体堆定义

int main(){
    q1.push(3);
    q1.push(5);
    q1.push(2);
    q1.push(4);
    q1.push(1);
    while(!q1.empty()){
        printf("%d\n",q1.top());
        q1.pop();
    }
    
    printf("\n");

    e.push(Node{1,3});
    e.push(Node{4,7});
    e.push(Node{3,1});
    e.push(Node{2,4});
    e.push(Node{6,37});
    e.push(Node{11,8});

    while(!e.empty()){
        printf("%d\n",e.top().b);
        e.pop();
    }

    return 0;
}