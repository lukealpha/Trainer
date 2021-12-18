#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;
struct pr_code{
    int price,t;
    bool avi = 1;
};
pr_code pr[100010];
int pointer = 1;
int cnt = 0;
int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    int n;
    scanf("%d",&n);
    int cost = 0;
    for (int i = 1; i <= n ; i ++){
        int a,price,t;
        scanf("%d%d%d",&a,&price,&t);
        if(a == 0){
            cost += price;
            pr[++cnt].price = price;
            pr[cnt].t = t;
        }
        else{
            bool flag = 0;
            for (int i = pointer; i <= cnt; i ++){
                if(pr[i].price >= price && t - pr[i].t <= 45 && pr[i].avi){
                    pr[i].avi = 0;
                    flag = true;
                    break;
                }
                if(t - pr[i].t > 45){
                    pointer = i + 1;
                }
            }
            if(!flag){
                cost += price;
            }
        }
    }
    printf("%d",cost);
    return 0;
}