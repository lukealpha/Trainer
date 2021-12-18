#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char str[1010];
    fgets(str,n + 2,stdin);
    cout << str << endl;
    for (int i = 0; i <= strlen(str); i ++){
        printf("%d:%c:%d\n",i,str[i],int(str[i]));
    }
    return 0;
}