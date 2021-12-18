#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--){
        long long l, r;
        scanf("%lld%lld", &l, &r);
        int ans = 0;
        if (r - l > 8){
            r = (r - l + 1) % 9 + l - 1;
        }
        while (l <= r){
            ans += l % 9;
            ans %= 9;
            ++l;
        }
        printf("%d\n", ans);
    }
    return 0;
}