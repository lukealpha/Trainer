#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
char S[1000000010];
int p[1000005];
void init_kmp(){
    memset(p,0,sizeof p);
    p[0] = -1;
    int j = 0;
    int k = -1; 
    int len_S = strlen(S);
    while(j < len_S){
        if(k == -1 || S[j] == S[k]){
            p[++j] = ++k;
        }
        else{
            k = p[k];
        }
    }
    return ;
}
int main(){
    while(1){
        scanf("%s",S);
        if(S[0] == '.'){
            break;
        }
        init_kmp();
        int cnt = 0;
        int j = strlen(S);
        int lp = -1;
        while(j){
            //p = p[j];

            if(lp == -1 || j - p[j] == lp - j){
                lp = j;
                j = p[j];
                cnt ++;
            }
            else{
                cnt = 1;
                break;
            }
        }
        cout << cnt << endl;
    }
    return 0;  
}