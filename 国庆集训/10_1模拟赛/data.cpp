#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
bool used[15];
int main()
{
    freopen("test.in","w",stdout);
    srand(time(0));
    int n = (rand()%10) + 1;
    printf("%d\n",n);
    for (int i = 1; i <= n; i ++){
        int tmp = rand() % n + 1;
        while(used[tmp]){
            srand(time(0));
            tmp = rand() % n + 1;
        }
        used[tmp] = 1;
        printf("%d ",tmp);
    }
    return 0;
}