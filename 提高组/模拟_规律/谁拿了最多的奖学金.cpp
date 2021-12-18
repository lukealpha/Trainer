#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 110;
string kmap[110];
struct st{
    int i;
    long long sum;
}student[maxn];
bool cmp(st a, st b){
    return a.sum > b.sum;
}
int main(){
    long long n, sum = 0;
    cin>>n;
    int maxi = 0;
    for(int i = 1;  i<= n; i ++){
        string name, p1,p2;
        int s1, s2, pas;
        cin >> name >> s1 >> s2 >> p1 >> p2 >> pas;
        kmap[i] = name;
        student[i].i = i;
        long long ans = 0;
        if(s1 > 80 && pas >= 1){
            ans += 8000;
        }
        if(s1 > 85 && s2 > 80){
            ans += 4000;
        }
        if(s1 > 90){
            ans += 2000;
        }
        if(s1 > 85 && p2 == "Y"){
            ans += 1000;
        }
        if(s2 > 80 && p1 == "Y"){
            ans += 850;
        }
        
        student[i].sum += ans;
        if(student[i].sum > student[maxi].sum){
            maxi = i;
        }
        sum += ans;
    }
    cout<<kmap[maxi]<<endl;
    cout<<student[maxi].sum<<endl;
    cout<<sum;

    return 0;
}