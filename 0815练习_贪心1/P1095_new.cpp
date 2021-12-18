#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int sh,run;
int main(){
    int m,s,t;
    cin >> m >> s >> t ;
    int i;
    for (i = 1; i <= t; i ++){
        if(m >= 10){
            sh += 60;
            m -= 10;
        }
        else{
            m += 4;
        }
        if(sh > run + 17){
            run = sh;
        }
        else{
            run += 17;
        }
        if (run >= s) break;
    }
    if (i>t) 
	{
		printf("No\n%d\n",run);
	}
    else 
	{
		printf("Yes\n%d\n",i);
	}
    return 0;
}