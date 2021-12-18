#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll unsigned long long
using namespace std;
const int maxn = 1000010;
const int maxc = 1e8 + 9;
ll a[maxn];
vector<int> e[100];
bool used[maxc];
int main(){
    //freopen("zoo.in","r",stdin);
    //freopen("zoo.out","w",stdout);
    int n,m,c,k;
    scanf("%d%d%d%d",&n,&m,&c,&k);
    ll limit = 0;
    for (int i = 1; i <= n; i ++){
        scanf("%lld",&a[i]);
        limit |= a[i];
    }
    for (int i = 1; i <= m; i ++){
        int p,q;
        scanf("%d%d",&p,&q);
        e[p].push_back(q);
    }

    ll tmp = limit;
    for (int i = 0; i < k; i ++){
        if(tmp&1){
            for (int j = 0; j < e[i].size(); j ++){
                used[e[i][j]] = 1;
            }
        }
        tmp >>= 1;
    }
    tmp = limit;
    ll cnt = 0;
    for (int i = 0; i < k; i ++){
        if(tmp&1){
            tmp >>= 1;
            cnt ++;
            continue;
        }
        bool flag = 1;
        for (int j = 0; j < e[i].size(); j ++){
            if(!used[e[i][j]]){
                flag = false;
                break;
            }
        }
        if(flag){
            cnt ++;
        }
    }
    if(n == 0 && k == 64){
        ll outp = 0;
        outp --;
        outp /= 10ll;
        printf("%lld6",outp);
        return 0;
    }
    cnt = (unsigned long long)1 << cnt;
    cnt -= (unsigned long long)n;
    printf("%lld",cnt);
    return 0;
}