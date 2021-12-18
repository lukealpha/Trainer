#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int x,n,a[1005],sum,ans = 0;
bool bj[100005];
int main(){
    scanf("%d%d",&x,&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
        bj[a[i]] = 1;
    }
    sort(a + 1, a + 1 + n);
    if(!bj[1]){
        cout<<-1;
    }
    else{
        while(sum<x){
            for (int i = n; i >=1 ;i --){
                if(sum + 1 >= a[i]){
                    sum = sum + a[i];
                    ans ++;
                    break;
                }
            }
        }
        printf("%d",ans);
    }
    return 0;
}