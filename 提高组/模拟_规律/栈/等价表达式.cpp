#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#define ll long long 
using namespace std;
int main(){
    char input[1010];
    scanf("%s",input);
    ll len  = strlen(input);
    stack<ll> st;
    for (ll i = 0; i < len - 1; i ++){
        ll num = 0;
        if('0'<=input[i] && input[i]<='9'){
            for (;input[i] != '.'; ++i) num *= 10, num += input[i] - '0';
            st.push(num);
        }
        if(input[i] == '+') num = st.top(),st.pop(),num += st.top(), st.pop(),st.push(num);
        if(input[i] == '-') num = st.top(),st.pop(),num -= st.top(), st.pop(),st.push(-num);
        if(input[i] == '*') num = st.top(),st.pop(),num *= st.top(), st.pop(),st.push(num);
        if(input[i] == '/') num = st.top(),st.pop(),num = st.top() / num, st.pop(),st.push(num);
    }
    printf("%d",st.top());
    return 0;
}