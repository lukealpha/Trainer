#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
#define maxn 1000010
using namespace std;

int arr[maxn];
struct comb{
    int val, pos;
};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++){
        scanf("%d",&arr[i]);
    }
    deque<comb> q;
    for (int i = 1; i <= n; i ++){
        if(!q.empty() && i - q.front().pos >= m){
            q.pop_front();
        }
        if(q.empty()){
            comb tmp;
            tmp.pos = i;
            tmp.val = arr[i];
            q.push_back(tmp);
        }
        else{
            while(!q.empty() && q.back().val >= arr[i]){
                q.pop_back();
            }
            comb tmp;
            tmp.pos = i;
            tmp.val = arr[i];
            q.push_back(tmp);
        }
        if(i >= m) printf("%d ",q.front().val);
    }
    while(!q.empty()){
        q.pop_back();
    }
    puts("");
    for (int i = 1; i <= n; i ++){
        if(!q.empty() && i - q.front().pos >= m){
            q.pop_front();
        }
        if(q.empty()){
            comb tmp;
            tmp.pos = i;
            tmp.val = arr[i];
            q.push_back(tmp);
        }
        else{
            while(!q.empty() && q.back().val <= arr[i]){
                q.pop_back();
            }
            comb tmp;
            tmp.pos = i;
            tmp.val = arr[i];
            q.push_back(tmp);
        }
        if(i >= m) printf("%d ",q.front().val);
    }
    return 0;
}

//1 -1 2 -2 3 -3
//1 2 -1 -2 3 -3
//1 1 -3
