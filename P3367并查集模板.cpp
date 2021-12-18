#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 10000001
using namespace std;
int n,m;
int z[maxn],x[maxn],y[maxn];
int fa[maxn];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x] = find(fa[x]);
}
bool query(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx==fy)return true;
    return false;
}
void link(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx==fy)
        return;
    else
        fa[fx]=fy;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&z[i],&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(z[i]==1)
        {
            link(x[i],y[i]);
        }
        if(z[i]==2)
        {
            bool print=query(x[i],y[i]);
            if(print==true)
            {
                cout<<"Y"<<endl;
            }
            else if(print==false)
            {
                cout<<"N"<<endl;
            }
        }
    }
    return 0;
}