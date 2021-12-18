//改数据范围！！！
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#define MAXN 100
using namespace std;
struct ppl{
    int i,p,v;
}p[MAXN];
int n, same[MAXN],last[MAXN];
bool cmp(ppl a, ppl b){
    if(a.p == b.p){
        return a.v > b.v;
    }
    else return a.p > b.p;
}
bool cmp_v(ppl a, ppl b){
    return a.v > b.v;
}
stack<int> k; 
int cal_op(int a, int b){
    if(p[a].p > p[b].p){
        swap(a,b);
    }
    int returnValue = p[a].p + p[a].v*(ceil((double)(p[b].p - p[a].p)/(double)(p[a].v - p[b].v)));
    return returnValue;
}
int main(){
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d",&p[i].p,&p[i].v);
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i ++){
        if(p[i].p == p[i + 1].p && p[i].v == p[i + 1].v){
            same[i] = same[i + 1] = 1;
        }
    }

    int maxi = 0, ans = 0;
    for (int i = 1; i <= n; i ++){
        if((!k.empty()) && p[k.top()].v < p[i].v){
            last[i] = k.top();
            if(p[i].v > p[maxi].v){
                maxi = i;
            }
            k.pop();
        }
        while((!k.empty()) && p[k.top()].v < p[i].v){
            k.pop();
        }
        k.push(i);
    }
    bool flag = 0;
    while(maxi!= 0){
        if(!same[maxi] && !flag){
            ans ++;
        }
        if(cal_op(maxi,last[last[maxi]]) == cal_op(last[maxi],last[last[maxi]]) && last[maxi] != 0 && last[last[maxi]]!= 0){
            flag = true;
        }else{
            flag = false;
        }
        maxi = last[maxi];
    }
    printf("%d",ans);
    return 0;
}