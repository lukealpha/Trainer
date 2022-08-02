#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
struct Egde{
    int to;
    double value;
    bool operator < (const Egde &a){
        return value < a.value;
    }
};
int main(){
    Egde a,b;
    a.value = 0.00;
    b.value = 3.00;
    printf("%d",(a<b));
    return 0;
}