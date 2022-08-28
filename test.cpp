#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d",int(ceil((double)x / (double)y)));
	return 0;
}