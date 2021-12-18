#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
stack<int> k;
int v[100010];
int main(){
    int n,ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        scanf("%d",&v[i]);
    }
    v[++n] = 0x3f3f3f3f;
    for (int i = 1; i <= n;i ++){
        if(k.empty() || v[k.top()] > v[i]){
            k.push(i);
        }
        else{
            while(!k.empty() && v[k.top()] < v[i]){
                ans += i - k.top() - 1;
                k.pop();
            }
            k.push(i);
        }
    }
    printf("%d",ans);
    return 0;
}