#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

stack<int> k;
int value[100010];
int ans[100010];

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&value[i]);
    }
    value[0] = -0x3f3f3f3f;
    for (int i = n; i >= 0; i --){
        if(k.empty() || value[i] >= value[k.top()]){
            k.push(i);
        }
        else{
            while(!k.empty() && value[i] < value[k.top()]){
                int top = k.top();
                ans[top] = value[i];
                if(i == 0){
                    ans[top] = -1;
                }
                k.pop(); 
            }
            k.push(i);
        }
    }
    for (int i = 1; i <= n; i ++){
        printf("%d ",ans[i]);
    }
    return 0;
}