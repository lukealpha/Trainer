#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int input[1010][1010];
bool visable[1010][1010][2];
void refresh_visable(int x, int y,int typ){
    for (int i = 1; i <= n; i ++){

    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    getchar();
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            scanf("%c",&input[i][j]);
            if(input[i][j] == 'm'){
                refresh_visable(i,j,0);
            }
            if(input[i][j] == 'M'){
                refresh_visable(i,j,1);
            }
        }
        getchar();
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            printf("%c",input[i][j]);
        }
    }
    
}