#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <stack>
using namespace std;
int n,c;
int a[10010];
int output[10010];
int main(){
    scanf("%d%d",&n,&c);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    int pt = 1;
    int ocnt = 0;
    stack<int> s;
    int cnt = 0;
    while (pt <= n){
        int minn = 0x3f3f3f3f;
        int min_pt;
        for (int i = pt; i <= pt + (c - cnt) - 1; i ++){
            if(a[i] < minn){
                minn = a[i];
                min_pt = i;
            }
        }
        if(s.empty()){
            for (int i = pt; i <= min_pt; i ++){
                s.push(a[i]);
                //printf("instack : %d\n",a[i]);
                cnt ++;
            }
            pt = min_pt + 1;
        }
        else if(minn < s.top()){
            for (int i = pt; i <= min_pt; i ++){
                s.push(a[i]);
                //printf("instack : %d\n",a[i]);
                cnt ++;
            }
            pt = min_pt + 1;
        }
        else{
            output[++ocnt] = s.top();
            //printf("outstack : %d\n",s.top());
            cnt --;
            s.pop();
        }
    }
    while(!s.empty()){
        output[++ocnt] = s.top();
        s.pop();
    }
    for (int i = 1; i <= ocnt; i ++){
        printf("%d ",output[i]);
    }
    return 0;
}