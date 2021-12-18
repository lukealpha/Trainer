#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	int r = gcd(b, a%b);
	return r;
}
int reverse(int a){
    int b = 0;
    b = a / 1000 + a / 100 % 10 * 10 + a / 10 % 10 * 100 + a % 10 * 1000;
    return b;
}
int main(){
    printf("%d",reverse(1));
    return 0;
}