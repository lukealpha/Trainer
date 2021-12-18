#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[100005],l,r,mid,ans;
inline bool check(int x)
{
    int tot=0,num=0;
    for(int i=1;i<=n;i++)
    {
        if(tot+a[i]<=x)tot+=a[i];
        else tot=a[i],num++;
    }
    printf("%d ",num);
    return num>=m;
}
int main()
{
    freopen("P1182_4.in","r",stdin);
    freopen("P1182_4.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),l=max(l,a[i]),r+=a[i];
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}