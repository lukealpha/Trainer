#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define max 40001
#define maxl 17

using namespace std;
struct edge{
    int from, to, w;
};
vector <edge> edges;
vector <int> G[max];

int f[max][maxl], gw[max][maxl];
int depth[max]; // 深度
int n,m,N;
using namespace std;

void addedge(int x, int y, int w){
    edge a= {x,y,w},b = {y,x,w};
    edges.push_back(a);
    edges.push_back(b);
    G
    
}
int main(){
    
    return 0;
}