#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char ch;
    int cnt = 0;
    for (int i = 1; i <= 8; i ++){
        cin>>ch;
        if(ch == '1'){
            cnt ++;
        }
    }
    printf("%d",cnt);
    return 0;
}