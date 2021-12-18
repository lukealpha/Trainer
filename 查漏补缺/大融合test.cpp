#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N=100000;

int n,cq,qopt[N+9],qx[N+9],qy[N+9];
struct side{
  int y,next;
}e[N*2+9];
int lin[N+9],cs;

void Ins(int x,int y){e[++cs].y=y;e[cs].next=lin[x];lin[x]=cs;}
void Ins2(int x,int y){Ins(x,y);Ins(y,x);}

void into(){
  scanf("%d%d",&n,&cq);
  for (int i=1;i<=cq;++i){
    char opt[2];
    scanf("%s%d%d",opt,&qx[i],&qy[i]);
    if (!(qopt[i]=opt[0]=='Q')) Ins2(qx[i],qy[i]);
  }
}

int fa[N+9],ld[N+9],rd[N+9],co;

void Dfs_ord(int k,int fat){
  fa[k]=fat;
  ld[k]=++co;
  for (int i=lin[k];i;i=e[i].next)
    if (e[i].y^fat) Dfs_ord(e[i].y,k);
  rd[k]=co;
}

void Get_ord(){
  for (int i=1;i<=n;++i)
    if (!ld[i]) Dfs_ord(i,0);
}

struct union_find_set{
  int fa[N+9];
  int &operator [] (const int &p){return fa[p];}
  void Build(){for (int i=1;i<=n;++i) fa[i]=i;}
  int Query_fa(int k){return k^fa[k]?fa[k]=Query_fa(fa[k]):k;}
}uni;

int c[N+9];

void Add(int p,int v){if (!p) return;for (;p<=n;p+=p&-p) c[p]+=v;}
int Query(int p){int res=0;for (;p;p-=p&-p) res+=c[p];return res;}
int Query(int l,int r){return Query(r)-Query(l-1);}

LL ans[N+9];

void Get_ans(){
  uni.Build();
  for (int i=1;i<=n;++i) Add(ld[i],1),Add(ld[fa[i]],-1);
  for (int i=1;i<=cq;++i){
    int x=qx[i],y=qy[i];
    if (ld[x]<ld[y]) swap(x,y);
    int fy=uni.Query_fa(y),t=Query(ld[x],rd[x]);
    if (qopt[i]) ans[i]=(LL)t*(Query(ld[fy],rd[fy])-t);
    else Add(ld[y],t),Add(ld[fa[uni[x]=fy]],-t);
  }
}

void work(){
  Get_ord();
  Get_ans();
}

void outo(){
  for (int i=1;i<=cq;++i)
    if (qopt[i]) printf("%lld\n",ans[i]);
}

int main(){
  into();
  work();
  outo();
  return 0;
}