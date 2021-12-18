
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
struct item{
    int a, grade;
    bool operator <(const item b)const{
        return a > b.a;
    }
}a[maxn];
int n,k;
long long gcnt = 0;
int main(){
    freopen("science.in","r",stdin);
    freopen("science.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i].a);
        a[i].grade = a[i].a / 10;
        a[i].a %= 10;
        gcnt += a[i].grade;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++){
        if(10 - a[i].a > k){
            break;
        }
        gcnt ++;
        k = k - 10 + a[i].a;
    }
    gcnt += min((long long)(10*n-gcnt),(long long)(k / 10));
    cout<<gcnt;
    return 0;
}
/*
3 29
17 15 19
*/