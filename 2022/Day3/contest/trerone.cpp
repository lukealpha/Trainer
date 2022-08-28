#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 100050;
int n,m;
vector<int> e[2*maxn];
int stat[maxn];
struct node{
    int fa = 0, pos = 0, size = 0;
    bool flip = 0;
}Nd[maxn];
void buildTree(int x){
    Nd[x].size = 1;
    for (int i = 0; i < e[x].size(); i ++){
        if(e[x][i] == Nd[x].fa) continue;
        Nd[e[x][i]].fa = x;
        buildTree(e[x][i]);
        Nd[x].size += Nd[e[x][i]].size;
        Nd[x].pos += Nd[e[x][i]].pos;
    }
    if(stat[x] == 1) Nd[x].pos += 1;
    return ;
}
bool check_flipped(int x){
    if(Nd[x].fa == x) return 0;
    if(check_flipped(Nd[x].fa)) return !Nd[x].flip;
    else return Nd[x].flip;
}
void flip(int x){
    Nd[x].flip = !Nd[x].flip;
    int old_pos = Nd[x].pos;
    Nd[x].pos = Nd[x].size - Nd[x].pos;
    int i = Nd[x].fa, modi = Nd[x].pos - old_pos;
    while(1){
        Nd[i].pos += modi;
        if(Nd[i].fa == i) break;
        else i = Nd[i].fa;
    }
    return ;
}
int main(){
    freopen("trerone.in","r",stdin);
    freopen("trerone.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++) scanf("%1d",&stat[i]);
    for (int i = 1; i <= n - 1; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    Nd[1].fa = 1;
    buildTree(1);
    for (int i = 1; i <= m; i++){
        int opt, x;
        scanf("%d%d",&opt,&x);
        if(opt == 0) flip(x);
        if(opt == 1){
            if(check_flipped(x)) printf("%d\n",Nd[x].size - Nd[x].pos);
            else printf("%d\n", Nd[x].pos);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}