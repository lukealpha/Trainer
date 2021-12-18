#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const int maxn = 10010;
int n,k,d;
struct node{
    int left = -1, right = -1, fa = 0;
    int val;
}e[maxn];
int ans = 0;
void dfs(int x, int res, int days){
    if(x == -1){
        ans = max(ans,days);
    }
    if((int)ceil((double)res / (double)2) > k){
        dfs(e[x].right, (int)ceil((double)res / (double)2), days + 1);
        dfs(e[x].left, (int)ceil((double)res / (double)2), days + 1);
        dfs(e[x].right, res, days + 1);
        dfs(e[x].left, res, days + 1);
    }
    else{
        dfs(e[x].right, res, days);
        dfs(e[x].left, res, days);
    }
}
int main(){

    scanf("%d%d%d",&n,&k,&d);
    for (int i = 1; i <= n; i ++){
        int a ,l, r;
        scanf("%d%d%d",&a,&l,&r);
        e[i].val = a;
        e[i].left = l;
        e[i].right = r;
        e[l].fa = i;
        e[r].fa = i;
    }
    int fa = 0;
    for (int i = 1; i <= n; i ++){
        if(e[i].fa == 0){
            fa = i;
            break;
        }
    }
    dfs(fa,e[fa].val,0);
    return 0;
}