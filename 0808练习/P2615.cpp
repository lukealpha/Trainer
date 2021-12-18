#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int a[40][40],n,x,y;

int main()
{
    scanf("%d",&n);
    a[1][(n+1)/2]=1;
    x=1,y=(n+1)/2;
    for(int i=2;i<=n*n;i++)
    {
        if(x==1 && y!=n)
            x=n,y++;
        else if(x!=1 && y==n)
            x--,y=1;
        else if(x==1 && y==n)
            x++;
        else if(!a[x-1][y+1])
            x--,y++;
        else
            x++;
        a[x][y]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}