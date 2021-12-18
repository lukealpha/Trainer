#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int m,s,t;
    scanf("%d%d%d",&m,&s,&t);
    int cu = 17 * t;
    int sch_t = 0;
    int max_mi_t = 0;
    while(sch_t < t)
    {
        if (m >= 10){
            cu = cu - 17 + 60;
            m -= 10;
            sch_t++;
        }
        else if(m < 10){
            int get_t = ceil(double(10 - m)/4);
            int delta = 60 - get_t*17 - 17;
            if((get_t + 1)>(t - sch_t)){
                break;
            }
            if(delta < 0)
                break;
            else{
                cu += delta;
                m = m + get_t*4 - 10;
                sch_t += get_t + 1;
            }

        }
        int avi_mi_t = t - sch_t;
        int mi_t = min(avi_mi_t,(cu - s) / 17);
        max_mi_t = max(mi_t,max_mi_t);
    }
    if(cu >= s){
        printf("Yes\n%d",t - max_mi_t);
    }
    else
    {
        printf("No\n%d",cu);
    }



    return 0;
}