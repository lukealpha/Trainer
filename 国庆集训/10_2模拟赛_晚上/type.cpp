#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
char s[10010], t[1010];
//deque<char> q;
int main(){
    scanf("%s%s",s,t);
    int lent = strlen(t),lens = strlen(s),ans = 0,pt = 0;
    for (int i = 0; i < lens; i ++){
        if(s[i] == t[pt]){
            pt ++;
        }
        else{
            pt = 0;
        }
        if(pt == lent - 1){
            ans ++;
            pt = i + 1;
            continue;
        }
    }
    cout << lens - ans * (lent - 1);
    return 0;
}