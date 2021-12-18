#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int n,m;
bool check(int x){
    int t = 0, seg = 1;
    for (int i = 1; i <= n; i ++){
        if(t + a[i] <= x) {
            t += a[i];
        }
        else{
            t = a[i], seg ++;
        }
    }
    //cout<<seg<<' ';
    return seg <= m;
} 
int main(){
    //freopen("P1182_4.in","r",stdin);
    //freopen("P1182_4.out","w",stdout);
    scanf("%d%d",&n,&m);
    int maxx = 0;
    int l = 0, r;
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
        maxx += a[i];
        l = max(a[i],l);
    }
    //printf("%d\n",maxx);
    r = maxx;
    while (l < r){
        int mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }

    }
    printf("%d",l);
    return 0;
}


//1 2 3 4 5 6 7 8 9 10 11 12
