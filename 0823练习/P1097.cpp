#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll input[200010];
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++){
        cin >> input[i];
    }
    sort(input + 1, input + n + 1);
    int j;
    for (int i = 1; i <= n; i = j){
        for (j = i;input[j] == input[i]; j ++);
        printf("%lld %d\n", input[i], j - i);
    }
    return 0;
}