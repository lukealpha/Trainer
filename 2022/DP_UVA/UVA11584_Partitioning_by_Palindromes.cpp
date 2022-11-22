/*
为什么这个题不用区间dp？因为一个字符串总能拆分成“n+1”个回文串的形式，只要枚举最后的“1”是什么即可
另外找回文串的时候需要注意有的回文串没有中心字符
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char str[1010];
bool palin[1010][1010];
int dp[1010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(palin,0,sizeof palin);
        scanf("%s",str+1);
        int n = strlen(str+1);
        for (int i = 1; i <= n; i ++){
            palin[i][i] = true;
            for (int j = 1; i + j <= n && i - j >= 1; j ++){
                if(!(str[i+j]==str[i-j])){
                    break;
                }
                else palin[i-j][i+j]=palin[i+j][i-j]=true;
            }
            for (int j = 0; i+1+j <= n && i - j >= 1; j ++){
                if(!(str[i+1+j]==str[i-j])){
                    break;
                }
                else palin[i-j][i+1+j]=palin[i+1+j][i-j]=true;
            }
        }
        for (int i = 1; i <= n; i ++){
            dp[i] = palin[1][i]?1:i;
            for (int j = 1; j < i; j ++){
                dp[i] = min(dp[i],dp[j]+(palin[j+1][i]?1:(i-j)));
            }
        }
        printf("%d\n",dp[n]);
    }
    
    return 0;
}