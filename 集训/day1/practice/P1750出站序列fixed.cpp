#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
stack <int> s;
int a[10005];
int n,c;
int main(){
    scanf("%d%d",&n,&c);
    for (int i = 0; i < n; i ++){
        scanf("%d",&a[i]);
    }
    int k = 0,cnt = 0,pos = 0;
    while (cnt + s.size() < n){
        int min = 0x7fffffff;
        for(int i = k; i < k + c - s.size() && i < n;i ++ ){
            if(a[i] < min){
                min = a[i];
                pos = i;
            }
        }
        if(s.empty() || min <= s.top()){
            for (int i = k; i <= pos; i ++){
                s.push(a[i]);
            }
            k = pos + 1;
        }
        printf("%d ",s.top());
        s.pop();
        cnt ++;
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}