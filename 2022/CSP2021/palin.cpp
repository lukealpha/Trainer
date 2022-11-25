#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1e6+7;
int a[maxn],b[maxn];
int lst[maxn];
int nxt[maxn];
int n;
bool solve(char st){
    vector<char> ans1;
    vector<char> ans2;
    ans1.push_back(st);
    ans2.push_back('L');
    int p1 = st=='L'?2:1,p2 = st=='L'?n*2:n*2-1,p3 = nxt[st=='L'?1:n*2]-1,p4 = nxt[st=='L'?1:n*2]+1;
    while(p1<=p3||p4<=p2){
        if(a[p1]==a[p3]&&p1<p3){
            ans1.push_back('L');
            ans2.push_back('L');
            p1++,p3--;
        }
        else if(a[p1]==a[p4]&&p1<p4){
            ans1.push_back('L');
            ans2.push_back('R');
            p1++,p4++;
        }
        else if(a[p2]==a[p3]&&p3<p2){
            ans1.push_back('R');
            ans2.push_back('L');
            p2--,p3--;
        }
        else if(a[p2]==a[p4]&&p4<p2){
            ans1.push_back('R');
            ans2.push_back('R');
            p2--,p4++;
        }
        else break;
    }
    if(!(p1<=p3||p4<=p2)){
        for (auto x:ans1){
            printf("%c",x);
        }
        for (int i = (int)ans2.size()-1; i >= 0; i --){
            printf("%c",ans2[i]);
        }
        puts("");
        return true;
    }
    return false;
}
int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for (int i = 1; i <= 2*n; i ++){
            scanf("%d",&a[i]);
            if(lst[a[i]]){
                nxt[i] = lst[a[i]];
                nxt[lst[a[i]]] = i;
            }
            lst[a[i]] = i;
        }
        if(solve('L'));
        else if(solve('R'));
        else printf("-1\n");
    }
    return 0;
}