#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 500010;
int arr[maxn];
int main(){
    freopen("inversion.in","r",stdin);
    freopen("inversion.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&arr[i]);
    }
    int inv = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            if(arr[i] > arr[j]){
                inv ++;
            }
        }
    }
    while(1){
        next_permutation(arr, arr+ n + 1);
        int tinv = 0;
        for (int i = 1; i <= n; i ++){
            for (int j = i + 1; j <= n; j ++){
                if(arr[i] > arr[j]){
                    tinv ++;
                }
            }   
        }
        if(tinv == inv){
            for (int i = 1; i <= n; i ++){
                printf("%d ",arr[i]);
            }
            break;
        }
    }
    return 0;
}

