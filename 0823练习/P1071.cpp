#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
char ori[120];
char encrypted[120];
char un_s[120];

char relation[30];
bool target_used[30];
int main(){
    cin >> encrypted >> ori >> un_s;
    memset(relation, 0, sizeof relation);
    int cnt = 0;
    for (int i = 0; i < strlen(ori); i ++){
        if(relation[encrypted[i] - 'A'] == 0 && target_used[ori[i]] == 0){
            relation[encrypted[i] - 'A'] = ori[i];
            cnt ++ ;
            target_used[ori[i]] = true;
        }
        else{
            if(relation[encrypted[i] - 'A'] == ori[i]){
                continue;
            }
            else{
                printf("Failed\n");
                return 0;
            }
        }
    }
    if(cnt < 26){
        printf("Failed\n");
        return 0;
    }
    for (int i = 0; i < strlen(un_s); i ++){
        printf("%c",relation[un_s[i] - 'A']);
    }
    printf("\n");
    return 0;
}