#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
    int n;
    int cnt = 1;
    int floor = 2;
    int x = 1,y = 1;
    scanf("%d",&n);
    int last = 2;
    while(cnt <= n){
        if(cnt == n){
            printf("%d/%d",x,y);
            break;
        }

        if(x == 1 && x + y == last){
            last = x + y;
            cnt ++;
            y ++;
            continue;
        }
        else if(y == 1 && x + y == last){
            last = x + y;
            cnt ++;
            x ++;
            continue;
        }
        last = x + y;
        if((x + y) % 2 == 1){
            x ++;
            y --;
        }
        else{
            x --;
            y ++;
        }
        cnt ++;
    }
    return 0;
}