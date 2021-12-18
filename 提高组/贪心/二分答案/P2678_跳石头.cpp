#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAXN = 50010;
int stone[MAXN], l, n, m;
bool check(int len){
    int cur = 0, cnt = 0;
    for (int i= 1; i <= n + 1; i ++){
        if(stone[i] - cur < len){
                cnt ++;
        }
        else{
            cur = stone[i];
        }
    }
    if(cnt <= m){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    scanf("%d%d%d",&l,&n,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&stone[i]);
    }
    stone[n + 1] = l;
    int L = 1, R = l, ans;
    while(L <= R){
        int mid = (L + R) / 2;
        if(check(mid)){
            L = mid + 1;
            ans = mid;
        }
        else{
            R = mid - 1;
        }
    }
    printf("%d",ans);
    return 0;
}