#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int num[2010][2010];
int l, q;
int check(int x, int y){
    int maxn = 0;
    int dx = min(x - 1, l - x);
    int dy = min(y - 1, l - y);
    int i = 1;
    for (i = 1; i <= dx; i ++){
        if(num[x - i][y] != num[x + i][y]){
            break;
        }
    }
    maxn = max(2 * i - 1,maxn);
    for (i = 1; i <= dy; i ++){
        if(num[x][y - i] != num[x][y + i]){
            break;
        }
    }
    maxn = max(2 * i - 1,maxn);
    return maxn;
}
int main(){
    scanf("%d%d",&l,&q);
    for(int i=1;i<=l;i++)
	{
        char s[2010];
        cin>>s+1;//从下标1开始存储 
        for(int j=1;j<=l;j++)
		{
           num[i][j]=s[j]-'a'+1;
        }
    }
    /* for (int i = 1; i <= l; i ++){
        for (int j = 1; j <= l; j ++){
            printf("%c ",a[i][j]);
        }
        printf("\n");
    } */
    for (int i = 1; i <= q; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",check(x,y));
    }
    return 0;
}