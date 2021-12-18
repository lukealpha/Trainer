#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
int main(){
    a.push_back(1);

    a.push_back(3);

    a.push_back(5);

    for (int i = 0; i < a.size(); i ++){
        printf("%d\n",a[i]);
    }
    return 0;
}