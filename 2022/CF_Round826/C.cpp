#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define ll long long
using namespace std;
ll a[2020];
int vis[1000010];
int n;
bool check(ll val){
    int sum = 0, tier = 1;
    memset(vis,0,sizeof vis);
    for (int i = 1; i <= n; i ++){
        if(vis[a[i]] && vis[a[i]] != tier){
            return false;
        }
        else vis[a[i]] = tier;
        sum += a[i];
        if(sum > val){
            return false;
        }
        else if(sum == val){
            sum = 0;
            tier ++;
            continue;
        }
    }
    return true;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        
    }
    return 0;
}