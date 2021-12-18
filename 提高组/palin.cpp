#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
int a[1000010];
int n;
struct sta{
	int s[1000010],l=0,r=0;
	int L(){return s[l];}
	int R(){return s[r-1];}
	void push(int x){s[r++]=x;}
	void pL(){l++;}
	void pR(){r--;}
	void clear(){l=r=0;}
	bool empty(){return r==l;}
	int size(){return r-l;}
}s1,s2;
bool get_ans(int dir){
    int l = 1,r = n,mid = 0;
    string ls,rs;
    if(dir == n) {
        ls = "R";
        rs = "L";
        r --;
    }
    else {
        ls = "L";
        rs = "L";
        l ++;
    }

    for (int i = l; i <= r; i ++){
        if(a[i] == a[dir]){
            mid = i;
            break;
        }
    }
    if(!mid) return false;
    for (int i = mid - 1; i >= l; i --){
        s1.push(a[i]);
    }
    for (int i = mid + 1; i <= r; i ++){
        s2.push(a[i]);
    }
    for(int i = 1; i < n / 2; i ++){
        if(!s1.empty() && !s2.empty() && s1.R() == s2.L()){
            ls = ls + "L";
            rs = "R" + rs;
            s1.pR();
            s2.pL();
        }
        else if(s1.size() > 1 && s1.R() == s1.L()){
            ls = ls + "L";
            rs = "L" + rs;
            s1.pR();
            s1.pL();
        }
        else if(s2.size() > 1 && s2.R() == s2.L()){
            ls = ls + "R";
            rs = "R" + rs;
            s2.pR();
            s2.pL();
        }
        else if(!s1.empty() && !s2.empty() && s2.R() == s1.L()){
            ls = ls + "R";
            rs = "L" + rs;
            s2.pR();
            s1.pL();
        }
        else{
            while(!s1.empty()){
                s1.pL();
            }
            while(!s2.empty()){
                s2.pL();
            }
            return false;
        } 
    }
    while(!s1.empty()){
        s1.pL();
    }
    while(!s2.empty()){
        s2.pL();
    }
    cout << ls + rs << endl;
    return true;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        n = n * 2;
        for (int i = 1; i <= n; i ++){
            scanf("%d",&a[i]);
        }
        if(!get_ans(1)){
            if(!get_ans(n)){
                printf("%d\n",-1);
            }
        }
    } 
    return 0;  
}
/*

LLRRRLRLRLLRLLLLRRLLLLLRLLLLLRLLRRLLLLLL
LLRRRLRLRLLRLLLLRRLLLLLRLLLLLRLLRRLLLLLL
*/
