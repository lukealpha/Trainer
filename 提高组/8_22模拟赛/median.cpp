#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1000000];
bool iso[1000000];
int op[1000010];
int main(){
    freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    for (int i = 2; i < n; i ++){
        if(a[i] != a[i - 1] && a[i] != a[i + 1]){
            iso[i] = 1;
        }
    }
    int cnt = 0;
    op[++cnt] = a[1];
    for (int i = 2; i < n; i ++){
        if(iso[i]){
            int j;
            for (j = i; iso[j]; j ++);
            if((j - i) % 2 == 0){
                ans = max((j - i) / 2,ans);
                for (int k = 1; k <= (j - i)/2; k ++){
                    op[++cnt] = a[i - 1];
                }
                for (int k = 1; k <= (j - i)/2; k ++){
                    op[++cnt] = a[j];
                }
            }
            else{
                ans = max(ans,(j - i + 1) / 2);
                for (int k = 1; k <= (j - i); k ++){
                    op[++cnt] = a[i - 1];
                }
            }
            i = j - 1;
        }
        else{
            op[++cnt] = a[i];
        }
    }
    op[++cnt] = a[n];
    printf("%d\n",ans);
    for (int i = 1; i <= cnt; i ++){
        printf("%d ",op[i]);
    }

    return 0;
}
