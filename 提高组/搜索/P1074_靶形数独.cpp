#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int ordx[90] = {0,5,4,4,4,5,5,6,6,6,3,3,3,3,3,4,5,6,4,5,6,7,7,7,7,7,2,2,2,2,2,2,2,3,4,5,6,7,3,4,5,6,7,8,8,8,8,8,8,8,1,1,1,1,1,1,1,1,1,2,3,4,5,6,7,8,2,3,4,5,6,7,8,9,9,9,9,9,9,9,9,9};
int ordy[90] = {0,5,6,5,4,6,4,6,5,4,7,6,5,4,3,7,7,7,3,3,3,7,6,5,4,3,8,7,6,5,4,3,2,8,8,8,8,8,2,2,2,2,2,8,7,6,5,4,3,2,9,8,7,6,5,4,3,2,1,9,9,9,9,9,9,9,1,1,1,1,1,1,1,9,8,7,6,5,4,3,2,1};
bool row[10][10], col[10][10], section[10][10];
int g[15][15],max_ans,max_step = 0;
int get_section(int x, int y){
    int row = x/3;
    int col = y/3;
    if(x % 3 != 0){
        row ++;
    }
    if(y % 3 != 0){
        col ++;
    }
    return (row - 1)*3 + col;
}
void dfs(int step){
    //printf("cur_step : %d\n",step);
     /* for (int i = 1; i <= 9; i ++){
        for (int j = 1; j <= 9; j ++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    } */
    //printf("\n");
    max_step = max(step,max_step);
    //printf("%d\n",step);
    if(step > 81){
        return ;
    }
    if(g[ordx[step]][ordy[step]] != 0){
        dfs(step + 1);
    }
    for (int i = 1; i <= 9; i ++){
        if(row[ordx[step]][i] == 0 && col[ordy[step]][i] == 0 && section[get_section(ordx[step],ordy[step])][i] == 0){
            row[ordx[step]][i] = 1;
            col[ordy[step]][i] = 1;
            section[get_section(ordx[step],ordy[step])][i] = 1;
            g[ordx[step]][ordy[step]] = i;
            dfs(step + 1);
            g[ordx[step]][ordy[step]] = 0;
            row[ordx[step]][i] = 0;
            col[ordy[step]][i] = 0;
            section[get_section(ordx[step],ordy[step])][i] = 0;
        }
    }
}
bool verified[90][90];
int main(){
    
    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j ++){
            scanf("%d",&g[i][j]);
            row[i][g[i][j]] = 1;
            col[j][g[i][j]] = 1;
            section[get_section(i,j)][g[i][j]] = 1;
        }
    }
    int cnt = 0;
    dfs(1);
    printf("%d",max_step);
    return 0;
}