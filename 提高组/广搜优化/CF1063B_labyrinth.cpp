#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
int n,m,sx,sy,l,r;
char g[2010][2010];
bool vis[2010][2010];

struct now{
    int x,y,l,r;
};
deque<now> q;

bool valid(now dst){
    if(dst.l >= 0 && dst.r >= 0 && dst.x >= 1 && dst.x <= n && dst.y >= 1 && dst.y <= m && g[dst.x][dst.y] != '*'){
        //printf("vf%d %d %d %d\n",dst.x, dst.y, dst.l, dst.r);
        return true;
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&sx,&sy);
    scanf("%d%d",&l,&r);
    int ans = 0;
    getchar();
    for (int i =1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            scanf("%c",&g[i][j]);
        }
        getchar();
    }
    /* for (int i =1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            printf("%c",g[i][j]);
        }
        cout<<endl;
    } */
    q.push_back(now{sx,sy,l,r});
    while(!q.empty()){
        now cur = q.front();
        q.pop_front();
        if(!vis[cur.x][cur.y]){
            vis[cur.x][cur.y] = true;
            ans ++;
            //printf("%d %d\n",cur.x,cur.y);
        }
        else{
            continue;
        }
        now to = cur;
        to.x --;
        if(valid(to)){
            q.push_front(to);
        }
        to = cur;
        to.x ++;
        if(valid(to)){
            q.push_front(to);
        }
        to = cur;
        to.y --;to.l --;
        if(valid(to)){
            q.push_back(to);
        }
        to = cur;
        to.y ++; to.r --;
        if(valid(to)){
            q.push_back(to);
        }
    }
    printf("%d",ans);
    return 0;
}

/*
4 4
2 2
0 1
....
..*.
....
....

*/