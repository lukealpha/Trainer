#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> t;
int a[100010];
int b[100010];
int ans[100010];
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n; i ++){
        scanf("%d",&b[i]);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if(t.size() < n){
                t.push(a[i] + b[j]);
                //printf("push %d\n",t.top());
            }
            else{
                if(t.top() > a[i] + b[j]){
                    //printf("pop %d\n",t.top());
                    t.pop();
                    
                    t.push(a[i] + b[j]);
                    //printf("push %d\n",t.top());
                }
                else{
                    break;
                }
            }
        }
    }
    for (int i = n; i >= 1; i --){
        ans[i] = t.top();
        t.pop();
    }
    for (int i = 1; i <= n; i ++){
        printf("%d ",ans[i]);
    }
}