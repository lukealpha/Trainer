#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

inline int read(){
    int x=0,f=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch == '-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}

int n;
int main(){
    n = read();
    
    return 0;
}