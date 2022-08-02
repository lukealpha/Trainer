#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 4e5+10;
int head[maxn],vis[maxn],ver[maxn],nxt[maxn],id[maxn],tot;
int ans[maxn],tt,du[maxn];
int MAX(int x,int y)
{
    return x>y?x:y;
}
void Init()
{
    memset(vis,0,sizeof(vis));
    memset(head,0,sizeof(head));
    memset(du,0,sizeof(du));
    tot=0;tt=0;
}
void addedge(int u,int v,int w)
{
    ver[++tot]=v;nxt[tot]=head[u];id[tot]=w;head[u]=tot;
}
void dfs(int u)
{
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!vis[(i+1)>>1]){
            vis[(i+1)>>1]=1;
            dfs(v);
            ans[++tt]=id[i];
        }
    }
}
int main(void)
{
    int n,m,x,y,z,i,j,ss;
    while(scanf("%d%d",&x,&y)&&(x+y)){
        Init();
        scanf("%d",&z);
        du[x]++;du[y]++;
        ss=x<y?x:y;
        n=MAX(x,y);m=1;
        addedge(x,y,z);addedge(y,x,z);
        while(scanf("%d%d",&x,&y)&&(x+y)){
            scanf("%d",&z);
            n=MAX(n,MAX(x,y));m++;
            du[x]++;du[y]++;
            addedge(x,y,z);addedge(y,x,z);
        }
        int fg=1;
        for(i=1;i<=n;i++)
        if(du[i]%2){
            fg=0;break;
        } 
        
        if(fg==0) printf("Round trip does not exist.\n");
        else{
            dfs(ss);
            if(m!=tt) printf("Round trip does not exist.\n");
            else{
                for(i=tt;i>=2;i--) printf("%d ",ans[i]);
                printf("%d\n",ans[1]);
            }
        }
    }
    return 0;
}