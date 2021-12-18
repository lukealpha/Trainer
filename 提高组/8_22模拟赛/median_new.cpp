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
    /* for (int i = 2; i < n; i ++){
        cout << iso[i] << ' ';
    } */
    //cout << "1";
    int cnt = 0;
    op[++cnt] = a[1];
    //printf("%d ",a[1]);
    for (int i = 2; i < n; i ++){
        if(iso[i]){
            int j;
            for (j = i; iso[j]; j ++);
            if((j - i) % 2 == 0){
                ans = max((j - i) / 2,ans);
                for (int k = 1; k <= (j - i)/2; k ++){
                    op[++cnt] = a[i - 1];
                    //printf("%d ",a[i - 1]);
                    
                    //if(k > 100000) return 0;
                }
                for (int k = 1; k <= (j - i)/2; k ++){
                    
                    op[++cnt] = a[j];
                    //printf("%d ",a[j]);
                    //if(k > 100000) return 0;
                }
            }
            else{
                ans = max(ans,(j - i + 1) / 2);
                for (int k = 1; k <= (j - i); k ++){
                    op[++cnt] = a[i - 1];
                    // printf("%d ",a[i - 1]);
                }
            }
            i = j - 1;
        }
        else{
            op[++cnt] = a[i];
            //printf("%d ",a[i]);
        }
    }
    op[++cnt] = a[n];
    cout <<ans<<endl;
    for (int i = 1; i <= cnt; i ++){
        cout << op[i] << ' ';
    }

    return 0;
}
/*
1 0 1 0 1 0 1 0 1
1 1 0 1 0 1 0 1 1
1 1 1 0 1 0 1 1 1
1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1

*/