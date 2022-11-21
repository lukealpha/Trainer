#include <iostream>
using namespace std;
using namespace std;
int main(){
    string s = "abcdcfg";
    int len = s.length();
    for (int i = 1; i < len - 1; i ++){
        if(s[i - 1] == s[i + 1]){
            string s0 = s.substr(0,i-1) + s.substr(i+1,len-i); 
            
        }
        else{
            string s0 = s.substr(0,i) + s.substr(i+1,len-i)
        }
    }
    return 0;
}