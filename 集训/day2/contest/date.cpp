#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int d1,d2;
bool check(int date){
    int day = date / 10 % 10 * 10 + date % 10;
    int mo = date / 1000 % 10  * 10 + date / 100 % 10;
    int yr = date /10000;
    if(mo > 12 || mo < 1){
        return false;
    }
    if(day < 1) return false;
    if(mo == 4 || mo == 6 || mo == 9 || mo == 11){
        if(day > 30){
            return false;
        }
    }
    else if(mo == 2){
        bool flag = false;
        if(yr % 4 == 0 && yr % 100 != 0) flag = true;
        else if(yr % 400 == 0) flag = true;
        if(flag && day > 29){
            return false;
        }
        if(!flag && day > 28){
            return false;
        }
    }
    else{
        if(day > 31){
            return false;
        }
    }
    return true;
}
int reverse(int a){
    int b = 0;
    b = a / 1000 + a / 100 % 10 * 10 + a / 10 % 10 * 100 + a % 10 * 1000;
    return b;
}
int main(){
    //freopen("date.in","r",stdin);
    //freopen("date.out","w",stdout);
    int cnt = 0;
    scanf("%d%d",&d1,&d2);
    int st = d1 / 10000, ed = d2 / 10000;
    for (int i = st; i <= ed; i ++){
        int tmp = reverse(i);
        tmp = i * 10000 + tmp;
        if(tmp < d1 || tmp >d2){
            continue;
        }
        else{
            if(check(tmp)){
                cnt ++;
                //printf("%d\n",tmp);
            }
        }
    }
    printf("%d",cnt);
    return 0;
}

