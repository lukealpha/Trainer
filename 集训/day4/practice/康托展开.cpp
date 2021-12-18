#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>


static const int FAC[] = {1,1,2,6,24,120,720,5040,40320,362880};

int cantor(int *a, int n){
    int x = 0;
    for (int i = 0; i < n; i ++){
            int smaller = 0;
            for (int j = i + 1; j < n; j ++){
                if(a[j] < a[i]){
                    smaller ++;
                }
            }
            x += FAC[n - i - 1] * smaller;
    }
    return x;
}

void decantor(int x, int n){
    vector<int> v;
    vector<int> a;
    for (int i = 1; i <= n; i ++){
        v.push_back(i);
    }
    for (int i = n; i >= 1; i --){
        int r = x % FAC[i - 1];
        int t = x / FAC[i - 1];
        x = r;
        sort(v.begin(),v.end());
        a.push_back(v[t]);
        v.erase(v.begin()+t);
    }
}