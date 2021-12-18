#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
int a[1000010];
bool check(int m){
    int s = 0,cnt = 0;
    for (int i = 1; i <= N; i ++){
        if(s + a[i] > m){
            cnt ++;
            s = a[i];
        }
        else{
            s += a[i];
        }
    }
    if(cnt + 1 <= M){
        return true;
    }
    else{
        return false;
    }
    
}
int main(){
    //freopen("divide_b4.in","r",stdin);
    //freopen("loj.out","w",stdout);

    scanf("%d%d",&N,&M);
    int l = 0,r = 0;
    for (int i = 1; i <= N; i ++){
        scanf("%d",&a[i]);
        l = max(a[i],l);
        r += a[i];
    }
    while (l < r){
        int mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    /* int left=l;
	int right=r,mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(check(mid))
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	cout<<left<<endl; */
    cout<<l;
    return 0;
}