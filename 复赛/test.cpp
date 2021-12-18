#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define int long long
#define pi pair<int,int>
#define F first
#define S second
#define mp make_pair
using namespace std;
pi a[100005];
priority_queue<pi> q;

//进一步检查
int now,pro,sum;//思路没问题但是过不了
signed main() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		int x,y;
		cin>>x>>y;
		a[i]=mp(x,y);
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		now+=a[i].F-a[i-1].F;//测试是否通过思路是否正确
		q.push(mp(a[i].S,a[i].F));
		++pro;
		now+=a[i].S;
		if(now>m) {
			while(now>m&&q.size()) {//进行测试
				pro--;
				now-=q.top().F;
				q.pop();
			}
		}
		if(now>m) {//使用pro con
			break;
		}
		sum=max(sum,pro);
	}
	cout<<sum;
	return 0;
}