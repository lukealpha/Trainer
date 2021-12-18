#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n;
bool vis[220],flag = 0;
struct node{
    int id, innode;
}innode[220];
char contacts[220][220];
string strd = "abcdefghijklmnopqrstuvwxyz";
string stra = "";
bool removed[220];
int cnta;
vector<int> e[220];
bool cmp(node a, node b){
    return a.innode < b.innode;
}
void valid(int st){
    if(flag){
        return ;
    }
    if(vis[st]){
        flag = true;
        return ;
    }
    vis[st] = 1;
    for (int i = 0; i < e[st].size(); i ++){
        valid(e[st][i]);
    }
}
void init(){
    for (int i = 1; i <= 130; i ++){
        innode[i].id = i;
    }
}
void qsort(){
    int q = 0;
    sort(innode + 1, innode + 130 + 1,cmp);
    int cur_innode[220];
    for (int i = 1; i <= 220 && innode[i].innode != 0x3f3f3f3f; i ++){
        cur_innode[innode[i].id] = i;
        q ++;
    }
    int st = innode[1].id;
    valid(st);
    if(flag || innode[1].innode != 0){
        flag = true;
        printf("Impossible");
        return ;
    }
    while(q){
        stra = stra + char(st);
        removed[st - 97] = 1;
        for (int i = 0; i < e[st].size(); i ++){
            innode[cur_innode[e[st][i]]].innode --;
        }
        innode[1].innode = 0x3f3f3f3f;
        sort(innode + 1,innode + 130 + 1,cmp);
        st = innode[1].id;
        q = 0;
        for (int i = 1; i <= 220 && innode[i].innode != 0x3f3f3f3f; i ++){
            cur_innode[innode[i].id] = i;
            q ++;
        }
    }
    
}

int main(){
    freopen("order.in","r",stdin);
    freopen("order.out","w",stdout);
    init();
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        scanf("%s",contacts[i]);
    }
    for (int i = 1; i < n; i ++){
        int p = 0, len = strlen(contacts[i]);
        while(p <= len){
            if(contacts[i][p] == contacts[i + 1][p]){
                p ++;
            }
            else{
                break;
            }
        }
        if(p == len + 1) continue;
        else{
            e[contacts[i][p]].push_back(contacts[i + 1][p]);
            innode[contacts[i + 1][p]].innode ++;
        }
    }
    for (int i = 1; i <= 200; i ++){
        if(e[i].size() == 0 && innode[i].innode == 0){
            innode[i].innode = 0x3f3f3f3f;
        }
    }
    qsort();
    if(flag){return 0;}
    int pd = 0,pa = 0;
    stra = stra + "~";
    strd = strd + "~";
    int lend = strd.length();
    int lena = stra.length();
    int cnt = 26;

    while(cnt--){
        while(removed[pd]) pd++;
        if(stra[pa] < strd[pd]){
            cout<<stra[pa++];
        }
        else{
            cout<<strd[pd++];
        }
    }
    return 0;
}