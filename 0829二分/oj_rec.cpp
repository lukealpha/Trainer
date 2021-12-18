#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long l,r,n;
struct rec{
    long long l,t,w,h; 
}a[100005];
long long check(long long x){
    long long sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i ++){
        if(a[i].l + a[i].w <= x){
            sum1 += a[i].w*a[i].h;
        }
        else if(a[i].l + a[i].w >= x && a[i].l <= x){
            sum1 += (x - a[i].l)*a[i].h;
            sum2 += (a[i].l+a[i].w - x)*a[i].h;
        }
        else if(a[i].l >= x){
            sum2 += a[i].w*a[i].h;
        }
    }
    return sum1 - sum2;
}
int main(){
    //long long sum = 0;
    scanf("%lld",&r);
    scanf("%lld",&n);
    for (int i = 1; i<= n;i ++){
        scanf("%lld%lld%d%lld",&a[i].l,&a[i].t,&a[i].w,&a[i].h);
    }
    while (l + 1< r){
        long long mid = (l + r) / 2;
        if(check(mid)<0) l=mid+1;
		else if(check(mid)==0) l=mid;
		else r=mid;
    }
    long long ans;
    
    if(check(l)>=0&&check(l)<check(r)) ans=l;
	else ans=r;
	printf("%lld",ans);
    return 0;
}


//18561566921