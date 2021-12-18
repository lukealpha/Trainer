#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    ll ans = 0;
    for (int i = 4713; i >= 1; i --){
        if(i % 4 == 1){
            ans += 366;
        }
        else{
            ans += 365;
        }
    }
    cout << ans;
    return 0;
}