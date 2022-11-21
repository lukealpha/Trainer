#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[55],b[55];
int main(){
    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; i ++){
        scanf("%s%s",a,b);
        int lena = strlen(a);
        int lenb = strlen(b);
        int fa = lena*(a[lena-1]=='L'?1:(a[lena-1]=='M'?0:-1));
        int fb = lenb*(b[lenb-1]=='L'?1:(b[lenb-1]=='M'?0:-1));
        if(fa < fb){
            printf("<\n");
        }
        else if(fa == fb){
            printf("=\n");
        }
        else if(fa > fb){
            printf(">\n");
        }
    }
    return 0;
}