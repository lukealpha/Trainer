#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int n;
long long m, cnt1, cnt2, price[45];
struct state{
    long long st, m;
}st1[1 << 21],st2[1 << 21];
void dfs1(int step, long long lseq, long long sum){
    if(step > (n/2)){
        st1[++cnt1].m = sum;
        st1[cnt1].st = lseq;
        return ;
    }
    dfs1(step + 1, lseq << 1, sum);
    dfs1(step + 1, (lseq << 1) + 1, sum + price[step]);
}
void dfs2(int step, long long lseq, long long sum){
    if(step > n){
        st2[++cnt2].m = sum;
        st2[cnt2].st = lseq;
        return ;
    }
    dfs2(step + 1, lseq << 1, sum);
    dfs2(step + 1, (lseq << 1) + 1, sum + price[step]);
}
bool cmp(state a, state b){
    return a.m < b.m;
}
int main(){
    scanf("%d%lld",&n,&m);
    for (int i  = 1; i <= n; i ++){
        scanf("%lld",&price[i]);
    }
    dfs1(1,0,0);
    dfs2(n / 2 + 1,0,0);
    sort(st1 + 1, st1 + cnt1 + 1,cmp);
    sort(st2 + 1, st2 + cnt2 + 1,cmp);
    long long sol = 0;
    for (int i = 1; i <= cnt2; i ++){
        long long L = 1, R = cnt1, ans = 0;
        while (L <= R){
            int mid = (L + R) / 2;
            if(st1[mid].m + st2[i].m <= m){
                L = mid + 1;
                ans = mid;
            }
            else{
                R = mid - 1;
            }
        }
        sol += ans;
    }
        
    printf("%lld",sol);
    return 0;
}