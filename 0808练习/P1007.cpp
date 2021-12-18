#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int L,N;
int ma,mi;
int main(){

    scanf("%d%d",&L,&N);

    for (int i = 1; i <= N; i ++){
        int input;
        scanf("%d",&input);
        ma = max(ma,max(input - 0,L + 1 - input));
        mi = max(mi,min(input - 0,L + 1 - input));
    }
    printf("%d %d\n",mi,ma);
    return 0;
}