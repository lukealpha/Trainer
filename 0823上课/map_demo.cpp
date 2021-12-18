#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
int main(){
    map <string,int> cp;
    int n;
    cin >> n;
    string s1,s2;
    int u,v,cnt = 0, k;
    for (int i = 1; i <= n; i ++){
        cin >> s1 >> s2 >> k;
        u = cp[s1];
        if(u == 0){
            cnt ++;
            cp[s1] = cnt;
            u = cp[s1];
        }
        v = cp[s2];
        if(v == 0){
            cnt ++;
            cp[s2] = cnt;
            v = cp[s2];
        }
        printf("%d->%d=%d\n",u,v,k);
    }
    return 0;
}