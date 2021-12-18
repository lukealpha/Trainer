#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;
stack<int> k;
int h[100010];
int n,ans = 0;

int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&h[i]);
    }
    h[++n] = 0x3f3f3f3f;
    for (int i = 1; i <= n;i ++){
        if(k.empty() || h[k.top()] > h[i]){
            k.push(i);
        }
        else{
            while(!k.empty() && h[k.top()] < h[i]){
                ans += i - k.top() - 1;
                k.pop();
            }
            k.push(i);
        }
    }
    printf("%d",ans);
    return 0;
}