#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#define L_INF 9223372036854775800
#define MAXN 100010
using namespace std;
int n,m,p1;
long long s1,s2;
long long a[MAXN];
int main(){
    freopen("fight.in","r",stdin);
    freopen("fight.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
    }
    scanf("%d%d%lld%lld",&m,&p1,&s1,&s2);
    long long q_dragon = 0, q_ti = 0;
    for (int i = 1; i < m; i ++){
        q_dragon += a[i] * (m - i);
    }
    for (int i = m + 1; i <= n; i ++){
        q_ti += a[i] * (i - m);
    }
    if(p1 > m){
        q_ti += s1 * (p1 - m);
    }
    else if(p1 < m){
        q_dragon += s1 * (m - p1);
    }
    long long delta = q_dragon - q_ti;
    int min_cur;
    long long min_delta = L_INF;
    if(delta < 0){
        delta = abs(delta);
        for (int i = 1; i < m; i ++){
            long long min_tmp = s2 * (m - i);
            min_tmp = delta - min_tmp;
            if(abs(min_tmp) < min_delta){
                min_delta = abs(min_tmp);
                min_cur = i;
            }
        }
    }
    else if(delta > 0){
        for (int i = m + 1; i <= n ; i ++){
            long long min_tmp = s2 * (i - m);
            min_tmp = delta - min_tmp;
            if(abs(min_tmp) < min_delta){
                min_delta = abs(min_tmp);
                min_cur = i;
            }
        }
    }
    else{
        min_cur = m;
    }
    if(min_delta > delta){
        min_cur = m;
    }
    printf("%d",min_cur);
    return 0;
}