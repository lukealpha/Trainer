#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x&(-x))
#define ll long long
using namespace std;
const int maxn = 100010;
struct number{
    int val, id;
    bool operator <(const number a)const{
        return val < a.val;
    }
}z[maxn];
int n,a[maxn],b[maxn],sum[maxn];
void modify(int x, int k){
    for (;x <= n; x += lowbit(x)){
        sum[x] += k;
    }
    return ;
}
int query(int x){
    int ans = 0;
    for (;x > 0; x -= lowbit(x)){
        ans += sum[x];
    }
    return ans;
}
void Disk(){
    sort(z + 1, z + n + 1);
    for (int i = 1; i <= n; i ++){
        a[z[i].id] = i;
        b[i] = z[i].val;
    }
    return ;
}
int main(){

    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d",&z[i].val);
        z[i].id = i;
    }
    Disk();
    for (int i = 1; i <= n; i ++){
        modify(a[i],1);
        if(i % 2 == 0) continue;
        int l = 1, r = n, ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(query(mid) >= (i + 1) / 2){
                r = mid - 1;
                ans = b[mid];
            }
            else l = mid + 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}