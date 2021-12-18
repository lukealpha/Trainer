#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 3030;

int arr[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&arr[i]);
    }
    double sum = 0;
    for (int i = 1; i <= n; i ++){
        sum += arr[i];
    }
    sum = sum / (double)n;
    int t = int(round(sum));
    long long ans = 0;
    for (int i = 1; i <= n; i ++){
        ans += (long long)((arr[i] - t) * (arr[i] - t));
    }
    printf("%lld",ans);
    return 0;
}