#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int n, pref[100010], q[100010], h[100010];

struct Node{
    int s,a;
}node[100010];
bool cmp (Node a, Node b){
    return a.a > b.a;
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&node[i].s);
    }
    for (int i = 1; i <= n; i ++){
        scanf("%d",&node[i].a);
    }
    sort(node + 1, node + n + 1,cmp);
    for (int i = 1; i <= n; i ++){
        pref[i] = pref[i - 1] + node[i].a;
    }
    for (int i = 1; i <= n; i ++){
        q[i] = max(q[i - 1], node[i].s * 2);
    }
    for (int i = n; i >= 1; i --){
        h[i] = max(h[i + 1],node[i].s * 2 + node[i].a);
    }
    for (int i = 1; i <= n; i ++){
        printf("%d\n",max(pref[i] + q[i], pref[i - 1] + h[i]));
    }
    return 0;
}