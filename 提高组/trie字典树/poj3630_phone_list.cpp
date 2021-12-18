//[POJ 3630] Phone List
//http://poj.org/problem?id=3630

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100006;
const int Z = 15;
int ch[N][Z], tot = 1;
bool ise[N];

bool insert(char *a){
    int len = strlen(a);
    int u = 1;
    bool flag = 0;
    for (int i = 0; i < len; i ++){
        int id = a[i] - '0';
        if(!ch[u][id]){
            ch[u][id] = ++tot;
        }
        else if(i == (len - 1) || ise[ch[u][id]]){
            flag = true;
        }
        u = ch[u][id];
    }
    ise[u] = true;
    return flag;
}
void init(){
    memset(ch, 0, sizeof ch);
    memset(ise, 0, sizeof ise);
    tot = 0;
}
int main(){
    int T;
    scanf("%d",&T);
    for (int i = 1; i <= T; i ++){
        init();
        char a[15];
        bool ans = false;
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++){
            scanf("%s",a);
            ans = insert(a);
        }
        if(ans){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
/*
1
21
980700
9807
113
12340
123440
12345
98346
7987
7879
6876
66986
5986
9869
9869
9867
7676876
687697
7678759
766587678
976876
769
8678768



*/