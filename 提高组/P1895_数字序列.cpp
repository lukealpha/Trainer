#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int T,n;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        string str;
        ll ans = 0;
        for (int i = 1;;i ++){
            str += to_string(i);
            ans += str.size();
            if(ans >= n){
                printf("%c\n",str[n - ans + str.size() - 1]);
                break;
            }
        }
    }

    return 0;
}