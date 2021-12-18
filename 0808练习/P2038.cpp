#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int graph[122][122];
struct comp{
    int axis,val;
};
bool cmp(comp a, comp b){
    return a.val > b. val;
}
// ha = 1, hb = 2,va = 3, vb = 4;
int main(){
    int d;
    int n;
    cin >> d >> n;
    for (int i = 1; i <= n; i ++){
        int x, y, k;
        scanf("%d%d%d",&x,&y,&k);
        graph[x][y] = k;
    }
    int ha = 0, hb = 128;
    int va = 0, vb = 128;
    while ((hb - ha) > (d * 2) || (vb - va) > (d * 2)){
        comp compd[5];
        for (int i = 1; i <= 4; i ++){
            compd[i].axis = i;
        }
        for (int i = va; i <= vb; i ++){
            compd[1].val += graph[i][ha];
            compd[2].val += graph[i][hb];
        }
        for (int i = ha; i <= hb; i ++){
            compd[3].val += graph[va][i];
            compd[4].val += graph[vb][i];
        }
        sort(compd + 1, compd + 4 + 1,cmp);
        if((hb - ha) > (d * 2) && (vb - va) > (d * 2)){
            if(compd[1].axis == 1){
                ha ++;
            }
            if(compd[1].axis == 2){
                hb --;
            }
            if(compd[1].axis == 3){
                va --;
            }
            if(compd[1].axis == 4){
                vb ++;
            }
        }
        else if((hb - ha) > (d * 2) && !((vb - va) > (d * 2))){
            for (int i = 1; i <= 4; i ++){
                if(compd[i].val != 1 && compd[i].val != 2){
                    if(compd[1].axis == 3){
                        va --;
                    }
                    if(compd[1].axis == 4){
                        vb ++;
                    }
                    break;
                }
            }
        }
        else if(!((hb - ha) > (d * 2)) && (vb - va) > (d * 2)){
            for (int i = 1; i <= 4; i ++){
                if(compd[i].val != 3 && compd[i].val != 4){
                    if(compd[1].axis == 1){
                        ha ++;
                    }
                    if(compd[1].axis == 2){
                        hb --;
                    }
                    break;
                }
            }
        }
        
    }

    return 0;
}