#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int a[810][810];
int tmp[810];
int bu;
int n, m, k;
int ans[810];
priority_queue<int> t;
int main(){
    scanf("%d%d%d",&n, &m, &k);
    for (int i = 1; i <= n;i ++){
        for (int j = 1; j <= m; j ++){
            scanf("%d",&a[i][j]);
            tmp[j] = a[i][j];
        }
    }
    for (int q = 2; q <= n;q ++){
        for (int i = 1; i <= m; i ++){
            for (int j = 1; j <= m; j ++){
                if(t.size() < m){
                    t.push(a[1][i] + a[q][j]);
                    //printf("push %d\n",t.top());
                }
                else{
                    if(t.top() > a[1][i] + a[q][j]){
                        //printf("pop %d\n",t.top());
                        t.pop();
                    
                        t.push(a[1][i] + a[q][j]);
                        //printf("push %d\n",t.top());
                    }
                    else{
                        break;
                    }
                }
            }
        }
        for (int i = m; i >= 1; i --){
            a[1][i] = t.top();
            t.pop();
        }
    }
    for (int i = 1; i <= k; i ++){
        printf("%d ",a[1][i]);
    }
    return 0;
}