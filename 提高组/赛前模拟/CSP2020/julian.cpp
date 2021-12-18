#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const ll bc = 1721424;
const ll adgr = 577737;
ll md[2][13] = {{0,31,29,31,30,31,30,31,31,30,31,30,31},{0,31,28,31,30,31,30,31,31,30,31,30,31}};
bool leap(int x){
    if(x % 400 == 0){
        return true;
    }
    else if(x % 4 == 0 && x % 100 != 0){
        return true;
    }
    else{
        return false;
    }
}
//2299249-2299161 = 88
void get_ans(ll r){
    if(r < bc){
        int dd = 1,mm = 1,yy = 4713;
        if(r >= 1461){
            yy -= 4*(r/1461);
            r %= 1461;
        }
        while(r >= 366){
            r -= 366;
            yy --;
            for (int i = 1; i <= 3; i ++){
                if(r >= 365){
                    r -= 365;
                    yy --;
                }
            }
        }
        for (int i = 1; i <= 12; i ++){
            if(r >= md[!(yy%4 == 1)][i]){
                mm ++;
                r -= md[!(yy%4 == 1)][i];
            } 
            else break;
        }
        dd += r;
        printf("%d %d %d BC\n",dd,mm,yy);
        return;
    }
    r -= bc;
    if(r < adgr){
        int dd = 1,mm = 1,yy = 1;
        if(r >= 1461){
            yy += 4*(r/1461);
            r %= 1461;
        }
        while(r >= 365){
            for (int i = 1; i <= 3; i ++){
                if(r >= 365){
                    r -= 365;
                    yy ++;
                }
            }
            if(r >= 366){
                r -= 366;
                yy ++;
            }
            
        }
        for (int i = 1; i <= 12; i ++){
            if(r >= md[!(yy%4 == 0)][i]){
                mm ++;
                r -= md[!(yy%4 == 0)][i];
            } 
            else break;
        }
        dd += r;
        printf("%d %d %d\n",dd,mm,yy);
        return ;
    }
    r -= adgr;
    if(r < 78){
        int dd = 15,mm = 10,yy = 1582;
        if(r < 17){
            dd += r;
        }
        else if (r < 47){
            r -= 17;
            dd = 1;
            dd += r;
            mm ++;
        }
        else{
            r -= 47;
            dd = 1;
            dd += r;
            mm += 2;
        }
        printf("%d %d %d\n",dd,mm,yy);
        return ;
    }
    r -= 78;
    int dd = 1,mm = 1, yy = 1583;
    if(r >= 1461){
        yy += 4*(r/1461);
        int modifier = (yy - 1583)/100;
        if((yy - 1583)%100 >= 17) modifier ++;
        modifier += (-1)*(yy-1583)/400;
        if((yy-1583)%400 >= 17){
            modifier --;
        }
        r %= 1461;
        r += modifier;
        if(r < 0){
            if(leap(yy - 1)){
                r += 366;
                yy --;
            }
            else{
                r += 365;
                yy --;
            }
        }
    }
    while(r >= 365){
        for (int i = 1; i <= 4; i ++){
            if(leap(yy) && r >= 366){
                r -= 366;
                yy ++;
            }
            else if(!leap(yy) && r >= 365){
                r -= 365;
                yy ++;
            }
            else{
                break;
            }
        }
    }
    for (int i = 1; i <= 12; i ++){
        if(r >= md[!leap(yy)][i]){
            mm ++;
            r -= md[!leap(yy)][i];
        } 
        else break;
    }
    dd += r;
    printf("%d %d %d\n",dd,mm,yy);
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        ll r;
        scanf("%lld",&r);
        get_ans(r);
    }

    return 0;
}