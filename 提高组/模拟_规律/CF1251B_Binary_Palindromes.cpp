#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
char input[55];
int main(){
    int Q;
    scanf("%d",&Q);
    while(Q--){
        int n;
        scanf("%d",&n);
        bool flag = true;
        int cnt1 = 0,cnt0 = 0;
        for (int i = 1; i <= n; i ++){
            scanf("%s",input);
            int len = strlen(input);
            if(len % 2){
                flag  = false;
            }
            for (int i = 0 ; i < len; i ++){
                if(input[i] - '0'){
                    cnt1 ++;
                }
                else{
                    cnt0 ++;
                }
            }
        }
        if(cnt1 % 2 && cnt0 % 2 && flag){
            printf("%d\n",n - 1);
        }
        else{
            printf("%d\n",n);
        }
    }
}