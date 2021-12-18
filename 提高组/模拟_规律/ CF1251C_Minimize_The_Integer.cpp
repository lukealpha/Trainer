#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
char input[300010];
int main(){
    int q;
    while(q--){
        scanf("%s",input);
        int len = strlen(input);
        queue<int> q1;
        queue<int> q2;
        for (int i = 0; i < len; i ++){
            if(input[i] % 2){
                q1.push(input[i] - '0');
            }
            else{
                q2.push(input[i] - '0');
            }
        }
        while(!q1.empty() && !q2.empty()){
            if(q1.front() < q2.front()){
                printf("%d",q1.front());
                q1.pop();
            }
            else{
                printf("%d",q2.front());
                q2.pop();
            }
        }
        while(!q1.empty()){
            printf("%d",q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            printf("%d",q2.front());
            q2.pop();
        }
        printf("\n");
    }
    return 0;
}