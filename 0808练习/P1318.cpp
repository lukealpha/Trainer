#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10010];
int main(){
    int n;
    scanf("%d",&n);
    int max_h = 0;
    for (int i = 1; i <= n;  i++){
        scanf("%d",&a[i]);
        max_h = max(max_h, a[i]);
    }
    int cnt = 0;
    for(int i = max_h; i >= 1; i --){
        int last = 0;
        for (int j = 1; j <= n; j ++){
            if(a[j] >=i){
                if(last == 0){
                    last = j;
                    continue;
                }
                else{
                    cnt += (j - last - 1);
                    last = j;
                }
            }
        }
    }
    printf("%d",cnt);
    return 0;
}