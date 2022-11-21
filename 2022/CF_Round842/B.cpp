#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
map<string,int> mp;
string convert_str(string s){
    int vis[11];
    memset(vis,0,sizeof vis);
    int tot = 0;
    int len = s.length();
    string ans = "";
    for (int i = 0; i < len; i ++){
        if(!vis[s[i]-'0']){
            vis[s[i]-'0'] = ++tot;
        }
        ans += vis[s[i]-'0'] + '0';
    }
    return ans;
}
int dp(string s){
    if(mp[s]) return mp[s];
    int len = s.length();
    int ans = 0;
    if(len == 1) return 1;
    for (int i = 1; i < len - 1; i ++){
        if(s[i - 1] == s[i + 1]){
            string s0 = s.substr(0,i-1) + s.substr(i+1,len-i);
            ans = max(ans,dp(s0)+1);
        }
        else{
            string s0 = s.substr(0,i) + s.substr(i+1,len-i);
            ans = max(ans,dp(s0)+1);
        }
    }
    if(s[1] == s[len-1] && len > 2){
        string s0 = s.substr(2);
        ans = max(ans,dp(s0)+1);
    }
    else {
        string s0 = s.substr(1);
        ans = max(ans,dp(s0)+1);
    }
    if(s[0] == s[len-2] && len > 2){
        string s0 = s.substr(0,len-2);
        ans = max(ans,dp(s0)+1);
    }
    else{
        string s0 = s.substr(0,len-1);
        ans = max(ans,dp(s0)+1);
    }
    mp[s] = ans;
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string x0 = "";
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++){
            int x;
            scanf("%d",&x);
            x0 += x+'0';
        }
        x0 = convert_str(x0);
        printf("%d\n",dp(x0));
    }
    return 0;
}