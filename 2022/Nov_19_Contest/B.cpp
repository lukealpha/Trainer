#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 5e5+7;
struct Line{
    double k, b;
    ll id;
}A[maxn],B[maxn];
bool visA[maxn],visB[maxn];
struct Intersect{
    double t0;
    ll a0,b0;
}sec[1000100];
ll tot = 0;
bool cmp_A(Line a, Line b){
    if(a.b != b.b) return a.b < b.b;
    else return a.k < b.k;
}
bool cmp_B(Line a, Line b){
    if(a.b != b.b) return a.b > b.b;
    else return a.k > b.k;
}
bool cmp(Intersect a, Intersect b){
    return a.t0 < b.t0;
}
int main(){
    ll n,l,k;
    scanf("%lld%lld%lld",&n,&l,&k);
    for (int i = 1; i <= n; i ++){
        ll v0,t0;
        scanf("%lld%lld",&t0,&v0);
        A[i].k = double(-v0);
        A[i].b = double((v0*t0)+l);
        A[i].id = i;
    }
    for (int i = 1; i <= n; i ++){
        ll v0,t0;
        scanf("%lld%lld",&t0,&v0);
        B[i].k = double(v0);
        B[i].b = double(-(v0*t0));
        B[i].id = i;
    }
    //sort(A + 1, A + n + 1, cmp_A);
    //sort(B + 1, B + n + 1, cmp_B);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            double t0 = -(A[i].b - B[j].b)/(A[i].k - B[j].k);
            if(A[i].k*t0 + A[i].b < 0 || A[i].k*t0 + A[i].b > l) continue;
            sec[++tot] = Intersect{t0,A[i].id,B[j].id};
        }
    }
    sort(sec+1,sec+tot+1,cmp);
    int cnt = 0;
    for (int i = 1; i <= tot && cnt < k; i ++){
        if(!visA[sec[i].a0] && !visB[sec[i].b0]){
            printf("%lld %lld\n",sec[i].a0,sec[i].b0);
            visA[sec[i].a0] = visB[sec[i].b0] = true;
            cnt ++;
        }
    }
    return 0;
}
/*

4 100 2
0 1
2 3
3 2
6 10
0 5
3 10
5 1
7 20

*/