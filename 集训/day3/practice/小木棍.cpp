//UVA 307 Sticks

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int a[105],used[105],n,len,m,mmin = 0, sum = 0,bj;
bool cmp(int a, int b){
    return a > b;
}
void dfs(int k, int last, int rest){
    int i,j;
    if(k == m){
        bj = 1;
        return ;
    }
    if(rest == 0){
        for (i = 1; i <= n; i ++){
            if(!used[i]){
                used[i] = 1;
                break;
            }
        }
        dfs(k + 1, i ,len - a[i]);
    }
    for (i = last + 1; i <= n; i ++){
        if(!used[i] && rest >= a[i]){
            used[i] = 1;
            dfs(k,i,rest - a[i]);
            used[i] = 0;
            j = i;
            while (i < n && a[i] == a[j]) i ++;
            if(i == n) {
                return;
            }
        }
    }
}
void solve(){
    int i;
    for (i = mmin; i <= sum; i ++){
        if(sum % i == 0){
            memset(used,0,sizeof(used));
            len = i;
            used[1] = 1;
            bj = 0;
            m = sum / i;
            dfs(1,1,len - a[1]);
            if(bj){
                printf("%d\n",len);
                break;
            }
        }
    }
}
int main(){
    //cin >> n;
    while(cin >> n && n != 0){
        memset(a,0,sizeof(a));
        len = 0,m = 0,mmin = 0, sum = 0,bj = 0;
        for (int i = 1; i <= n; i ++){
            cin >> a[i];
            mmin = max(mmin,a[i]);
            sum = sum + a[i];
        }

        sort(a + 1, a + 1 + n, cmp);
        solve();
    }
    return 0;
}

/*
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0
*/