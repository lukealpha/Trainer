//PreOJ-1053玩具谜题
//linked to target "PreOJ_1053"
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
struct custom_list{
    string value;
    int det;
    int last;
    int next;
}toys[100010];
int n,m;
int positive_move (int current,int step) {
    int returnValue;
    returnValue = current + step;
    if(returnValue > n) returnValue = returnValue % n;
    return returnValue;
}
int negative_move (int current, int step) {
    step = step % n;
    current -= step;
    if(current <= 0){
        current = n - abs(current);
    }
    return current;
}
int main(int argc, const char * argv[]) {

    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; ++i){
        cin>>toys[i].det;
        cin>>toys[i].value;
        if(i != n)
            toys[i].next = i + 1;
        else
            toys[i].next = 1;
        toys[i].last = i - 1;
    }
    int curser = 1;
    for (int i = 1;i <= m; i ++ ) {
        int command;
        int value;
        scanf("%d%d",&command,&value);
        if (toys[curser].det == 0) {
            if(command == 0){
                curser = negative_move(curser, value);
            }
            if (command == 1)
                curser = positive_move(curser, value);
        }
        else if (toys[curser].det == 1) {
            if (command == 0) //1 2 3 4 5
                curser = positive_move(curser, value);
            if (command == 1)
                curser = negative_move(curser, value);
        }
        if(curser < 1 || curser > n){
            printf("%d ",i);
        }
    }
    cout<<toys[curser].value;
    return 0;
}