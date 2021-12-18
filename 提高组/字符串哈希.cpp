//hash一定要注意0的问题！！
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ull unsigned long long
using namespace std;
const ull mod = 212370440130137957ll, p = 131;
ull a[10010];
char str[10010];
ull hashe(char str[]){
    int len = strlen(str);
    ull ans = 0;
    for (int i = 0; i < len; i ++){
        ans = (ans * p + (ull)str[i]);
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%s",str);
        a[i] = hashe(str);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if(a[i] != a[i - 1]){
            ans ++;
        }
    }
    printf("%d",ans);
    return 0;
}