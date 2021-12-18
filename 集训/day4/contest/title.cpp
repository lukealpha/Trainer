#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    freopen("title.in","r",stdin);
    freopen("title.out","w",stdout);
    string A;
    getline(cin,A);
    int cnt = 0;
    for (int i = 0; i <= A.length(); i ++){
        char x = A[i];
        if(x != '\0' && x != '\n' && x != ' '){
            cnt ++;
        }
    }
    cout<<cnt;
    return 0;
}