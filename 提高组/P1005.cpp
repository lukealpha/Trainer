#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

#define bll __int128
#define k m-(j-i)
using namespace std;

const int maxn = 85;
int n,m;
bll num[maxn],f[maxn][maxn],p[maxn] = {1};
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}

bll dp(){
    for (int len = 0; len < m; len ++){
        for (int i = 1, j = i + len; j <= m; ++i, ++j){
            if(i == j){
                f[i][j] = num[i];
            }
            f[i][j] = max(f[i][j - 1] + num[j]*p[k], f[i+1][j] + num[i]*p[k]);
        }
    }
    return f[1][m];
}

void print(bll x,int dig = 0){
    if(!x){if(dig == 0) putchar('0'); return;}
    if(x) print(x/10,dig + 1);
    putchar(x%10+'0');
    return ;
}

int main(){

    scanf("%d%d",&n,&m);
    bll ans = 0;
    for (int i = 1; i <= m; i ++){
        p[i] = p[i - 1] << 1;
    }
    for (int i = 1; i <= n; i ++){
        memset(f,0,sizeof f);
        for (int j = 1; j <= m; j ++)
        num[j] = read();
        ans += dp();
    }
    print(ans);
    return 0;
}