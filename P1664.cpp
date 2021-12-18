#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int power(int a,int b){
    int returnValue = 1;
    for (int i = 1; i <= b; i ++){
        returnValue *= a;
    }
    return returnValue;
}
int stat[1010];
int main(){
    memset(stat,-1,sizeof(stat));
    int n;
    scanf("%d",&n);
    int cnt = 0;
    int point = 0;
    for (int i = 1; i <= n; i ++){
        scanf("%d",&stat[i]);
    }
    for (int i = 1; i <= n; i ++){
        
        if(stat[i] == 1){
            cnt ++;
        }
        else{
            int j;
            for (j = i; stat[j] == 0; j ++);
            int po = power(2,j - i - 1);
            if (po > cnt) cnt = 0;
            else{
                cnt -= po;
            }
            i = j - 1;
            continue;
        }
        if(1 <= cnt && cnt < 3){
            point += 1;
        }
        else if(3 <= cnt && cnt < 7){
            point += 2;
        }
        else if(7 <= cnt && cnt < 30){
            point += 3;
        }
        else if(30 <= cnt && cnt < 120){
            point += 4;
        }
        else if(120 <= cnt && cnt < 365){
            point += 5;
        }
        else if(cnt >= 365){
            point += 6;
        }
        
    }
    printf("%d",point);
    return 0;
}