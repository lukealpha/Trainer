#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define bll __int128


using namespace std;

inline bll read(){
    bll x = 0, f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
void print(bll x,int dig = 0){
    if(!x){if(dig == 0) putchar('0'); return;}
    if(x) print(x/10,dig + 1);
    putchar(x%10+'0');
    return ;
}
int main(){
    bll n,m;
    n = read();
    m = read();
    print(n);
    puts("");
    print(m);
    puts("");
    print(n + m);
    return 0;
}