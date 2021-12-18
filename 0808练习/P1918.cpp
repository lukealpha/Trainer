#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
map<string,int> g;
int main(){
    int n,q;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        string input;
        cin >> input;
        g[input] = i;
    }
    scanf("%d",&q);
    for (int i = 1; i <= q ; i ++){
        string input;
        cin >> input;
        printf("%d\n",g[input]);
    }
    return 0;
}