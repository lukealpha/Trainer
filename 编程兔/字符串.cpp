#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000010;
string st[maxn];
bool inc_cmp(string a, string b){
    if(strcmp(a.c_str(),b.c_str())<0){
        return true;
    }
    return false;
}
bool dec_cmp(string a, string b){
    if(strcmp(a.c_str(),b.c_str())<0){
        return false;
    }
    return true;
}
bool ncinc_cmp(string a, string b){
    if(strcasecmp(a.c_str(),b.c_str())<0){
        return true;
    }
    return false;
}
bool ncdec_cmp(string a, string b){
    if(strcasecmp(a.c_str(),b.c_str())<0){
        return false;
    }
    return true;
}
int main(){
    string str;
    cin >> str;
    int n;
    scanf("%d",&n);
    getchar();
    for (int i = 1; i <= n; i ++){
        getline(cin,st[i]);
    }
    if(str == "inc") sort(st + 1, st + n + 1, inc_cmp);
    if(str == "dec") sort(st + 1, st + n + 1, dec_cmp);
    if(str == "ncinc") sort(st + 1, st + n + 1, ncinc_cmp);
    if(str == "ncdec") sort(st + 1, st + n + 1, ncdec_cmp);
    for (int i = 1; i <= n; i ++){
        if(i != n)
            cout << st[i] << endl;
        else
            cout << st[i];
    }
    
}