#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
stack<int> k;
int width[100010],h[100010];
int main(){
    int n;
    
    while(cin >> n && n != 0){
        for (int i = 1; i <= n; i ++){
            scanf("%d",&h[i]);
        }
        long long ans = 0;
        h[++n] = -1;
        for (int i = 1; i <= n; i ++){
            if(k.empty() || h[k.top()] <= h[i]){
                k.push(i);
            }
            else{
                while(!k.empty() && h[k.top()] > h[i]){
                    long long tmp_ans;
                    tmp_ans = (long long)(i - k.top())*(long long)h[k.top()];
                    ans = max(ans, (long long)tmp_ans);
                    k.pop();
                }
                k.push(i);
            }
        }
        while(!k.empty()){
            k.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}