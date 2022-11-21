#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int maxn = 1e5 + 7;
char Seq[maxn];
void SeqToNum(){
    int L1 = 0,L2 = 1,R1 = 1,R2 = 0;
    int Mid1 = 1, Mid2 = 1;
    int len = strlen(Seq);
    for (int i = 0; i < len; i ++){
        if(Seq[i] == 'L'){
            R1 = Mid1;
            R2 = Mid2;
            Mid1 = L1 + R1;
            Mid2 = L2 + R2;
        }
        else{
            L1 = Mid1;
            L2 = Mid2;
            Mid1 = L1 + R1;
            Mid2 = L2 + R2;
        }
    }
    printf("%d %d",Mid1,Mid2);
}
void NumToSeq(ll N1, ll N2){
    ll L1 = 0,L2 = 1,R1 = 1,R2 = 0;
    ll Mid1 = 1, Mid2 = 1;
    while(!(Mid1 == N1 && Mid2 == N2)){
        if(N1*Mid2 > N2*Mid1){
            printf("%c",'R');
            L1 = Mid1;
            L2 = Mid2;
            Mid1 = L1 + R1;
            Mid2 = L2 + R2;
        }
        else{
            printf("%c",'L');
            R1 = Mid1;
            R2 = Mid2;
            Mid1 = L1 + R1;
            Mid2 = L2 + R2;
        }
    }
}
int main(){
    freopen("sbt.in","r",stdin);
    freopen("sbt.out","w",stdout);
    int tp;
    scanf("%d",&tp);
    if(tp == 1){
        scanf("%s",Seq);
        SeqToNum();
    }
    else if(tp == 2){
        ll a, b;
        scanf("%lld%lld",&a,&b);
        NumToSeq(a,b);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}