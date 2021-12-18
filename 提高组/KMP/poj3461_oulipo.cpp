#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char W[10010];
char T[1000010];
int p[10010];
void init_kmp(){
    memset(p,0,sizeof p);
    p[0] = -1;
    int j = 0;
    int k = -1;
    int len_W = strlen(W);
    while(j < len_W){
        if(k == -1 || W[j] == W[k]){
            p[++j] = ++k;
        }
        else{
            k = p[k];
        }
    }
    return ;
}
int kmp(){
    int i , j; i = j = 0;
    int len_T = strlen(T);
    int len_W = strlen(W);
    int cnt = 0;
    while(i < len_T){
        if(j == -1 || T[i] == W[j]){
            i ++;
            j ++;
        }
        else{
            j = p[j];
        }
        if(j == len_W){
            cnt ++;
            j = p[j];
        }
    }
    return cnt;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",W);
        scanf("%s",T);
        init_kmp();
        cout << kmp() << endl;
    }
    return 0;
}