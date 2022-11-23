#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char str[110];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);
        int n = strlen(str+1);
        for (int len = 1; len <= n; len ++){
            for (int i = 1; i + len - 1 <= n; i ++){
                int j = i + len - 1;
                
            }
        }
    }
    return 0;
}