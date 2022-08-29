//不能使用%1d读入！！效率很低
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5050;
char a[maxn][maxn];
int to[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for (int i =1;i <= n; i++){
        scanf("%s",a[i] + 1);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if(a[i][j] == '1' && (!to[i] || a[j][to[i]] == '1')) to[i] = j;
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j++){
            if(a[i][j] == '1' && a[to[j]][i] == '1'){
                printf("%d %d %d\n",i,j,to[j]);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}