#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
void standard(int n,int y,int r,int m){
    int group = 0;
    group = m / r;
    int acc = m % r;
    if (acc == 0){
        acc = r;
    }
    else{
        group ++;
    }
    if(y == 1){
        printf("%d %d ",group,acc);
    }
    if(y == 2) {
        printf("%d %d ",acc,group);
    }
}
void meihua(int n,int y,int r,int m){
    int group = 0;
    group = m / r;
    int acc = m % r;
    if (acc == 0){
        acc = r;
    }
    else{
        group ++;
    }
    int di = r % 2;
    int s = (r / 2) + di; //s = (r / 2) + di + 1 - 1
    if (acc > ((r / 2) + di)){
        acc = (acc - s) * 2;
        group = group * 2;
    }
    else{
        acc = acc * 2 - 1;
        group = group * 2 - 1;
    }
    if(y == 1){
        printf("%d %d ",group,acc);
    }
    if(y == 2) {
        printf("%d %d ",acc,group);
    }
}

int main(){
    //meihua(16,1,7,14);
    int k;
    scanf("%d",&k);
    for (int i = 1; i <= k; i ++){
        int n,x,y,r,m;
        scanf("%d%d%d%d%d",&n,&x,&y,&r,&m);
        if(x == 1){
            standard(n,y,r,m);
        }
        else{
            meihua(n,y,r,m);
        }
        
    }
    return 0;
}