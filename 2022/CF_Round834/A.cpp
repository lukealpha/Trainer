#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
char str[1010];
map<char,char> mp;
int main(){
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    mp['Y'] = 'e';
    mp['e'] = 's';
    mp['s'] = 'Y';
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int len = strlen(str);
        //bool flag = true;
        bool flag = (str[0]=='Y'||str[0]=='e'||str[0]=='s')?true:false;
        for (int i = 1; i < len; i ++){
            if(str[i] != mp[str[i-1]]){
                flag = false;
            }
        }
        if(flag){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}