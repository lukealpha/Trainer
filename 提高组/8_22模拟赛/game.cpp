#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int op[15];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++){
        int x;
        scanf("%1d",&x);
        if(x == 9){
            op[3] += 2;
            op[2] ++; 
            op[7] ++;
        }
        if(x == 8){
            op[2] += 3;
            op[7] ++;
        }
        if(x == 7){
            op[7] ++;
        }
        if(x == 6){
            op[3] ++;
            op[5] ++;
        }
        if(x == 5){
            op[5] ++;
        }
        if(x == 4){
            op[2] += 2;
            op[3] ++;
        }
        if(x == 3){
            op[3] ++;
        }
        if(x == 2){
            op[2] ++;
        }
    }
    for (int i = 7; i >= 2; i --){
        if(op[i]){
            for (int j = 1; j <= op[i]; j ++) printf("%d",i);
        }
    }
}
