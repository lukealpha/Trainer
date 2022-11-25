#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll __int128
using namespace std;
const int maxn = 1e5+7;
int q[maxn],h=1,t=0,d[maxn];
inline __int128 read(){
    __int128 x=0,f=1; char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
inline void prt(__int128 x){
    if(x<0){putchar('-');x=-x;}
    if(x>9) prt(x/10);
    putchar(x%10+'0');
}
int fst[maxn],nxt[5*maxn],to[5*maxn],tot=1,indeg[maxn];
void add_edge(int x, int y){
    to[++tot] = y;
    nxt[tot] = fst[x];
    fst[x] = tot;
}
__int128 gcd(__int128 a, __int128 b){
    if(b!=0) return gcd(b,a%b);
    else return a;
}
struct Frac{
    __int128 p,q;
};
Frac Deal(Frac A){
    __int128 g = gcd(A.p,A.q);
    A.p/=g,A.q/=g;
    return A;
}
Frac Add(Frac A, Frac B){
    Frac ans;
    A.p*=B.q, B.p*=A.q;
    ans.p = A.p + B.p;
    ans.q = A.q*B.q;
    ans = Deal(ans);
    return ans;
}
Frac Div(Frac A, Frac B){
    Frac ans;
    ans.p = A.p*B.q, ans.q = A.q*B.p;
    ans = Deal(ans);
    return ans;
}
Frac operator/ (const Frac& A, const Frac& B){
    return Div(A,B);
}
Frac operator+ (const Frac& A, const Frac& B){
    return Add(A,B);
}
Frac Zero = {0,1};
Frac f[maxn];

int main(){
    memset(fst,-1,sizeof fst);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        f[i] = Zero;
    }
    vector<int> endd;
    for (int i = 1; i <= n; i ++){
        scanf("%d",&d[i]);
        if(d[i]==0) endd.push_back(i);
        else{
            for (int j = 1; j <= d[i]; j ++){
                int v;
                scanf("%d",&v);
                add_edge(i,v);
                indeg[v]++;
            }
        }
        f[i] = Zero;
    }
    for (int i = 1; i <= n; i ++){
        if(indeg[i]==0){
            q[++t] = i;
            f[i] = {1,1};
        }
    }
    while(h<=t){
        int now = q[h++];
        for (int i = fst[now]; i != -1; i = nxt[i]){
            int v = to[i];
            if(indeg[v]>0){
                indeg[v]--;
                if(indeg[v]==0) q[++t] = v;
            }
            f[v] = f[v] + f[now]/Frac{d[now],1};
        }
    }
    for (auto x:endd){
        prt(f[x].p);putchar(' ');prt(f[x].q);
        puts("");
    }
    return 0;
}
