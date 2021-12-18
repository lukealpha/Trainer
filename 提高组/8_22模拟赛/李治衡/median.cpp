#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100],b[100], cnt;
int main(){
    freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    bool flag = true;
    int T = 30000;
    while(flag && T --){

        flag = false;
        for (int i = 2; i < n; i ++){
            b[i] = a[i - 1] + a[i] + a[i + 1];
            b[i] /= 2;
        }
        //cout << a[1] << ' ';
        
        for (int i = 2; i < n; i ++){
            if (a[i] != b[i]) {flag = true;}
            a[i] = b[i];
            //printf("%d ",a[i]);
        }
        cnt ++;
        //cout << a[n];
        //puts("");
    }
    if(flag){
        printf("-1");
    }
    else{
        cout << cnt - 1 << endl;
        for (int i = 1; i <= n; i ++){
            printf("%d ",a[i]);
        }
    }
    return 0;
}