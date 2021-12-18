#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char t[100000001];
char p[100001];
int nxt[100001];
void init_nxt(){
    nxt[0] = -1;
    int j = 0;
    int k = -1;
    int len = strlen(p);
    while(j < len){
        if(k == -1 || p[j] == p[k]){
            nxt[++j] = ++k;
        }
        else{
            k = nxt[k];
        }

    }
}
int kmp(){
    int i = 0, j = 0;
    int len_t = strlen(t);
    int len_p = strlen(p);
    while(i < len_t && j < len_p){
        if(j == -1 || t[i] == p[j]){
            i ++;
            j ++;
        }
        else{
            j = nxt[j];
        }
        if(j == len_p){
            return i - j;
        }
        else{
            return -1;
        }
    }
}
int main(){
    
    return 0;
}