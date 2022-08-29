#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define N 5050
#define M 100010
using namespace std;
int first[N],nxt[M*2],to[M*2],w[M*2],tot;
int n,m;
struct Node{
	int pos,dis;
	bool operator < (Node a) const{
		return a.dis<dis;
	}
};
priority_queue<Node> q; 
int read(){
	int cnt=0;char ch=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))cnt=cnt*10+(ch-'0'),ch=getchar();
	return cnt;
}
void add(int x,int y,int z){
	nxt[++tot]=first[x],first[x]=tot,to[tot]=y,w[tot]=z;
}
int astar(){
	int times[N];
	memset(times,0,sizeof(times));
	Node tmp,h;
	h.pos=1,h.dis=0;
	q.push(h);
	while(!q.empty()){
		Node x=q.top(); q.pop();
		times[x.pos]++;
		if(times[x.pos]==2&&x.pos==n) return x.dis;
		if(times[x.pos]>2) continue;
		for(int i=first[x.pos];i;i=nxt[i]){
			tmp.dis=x.dis+w[i];
			tmp.pos=to[i];
			q.push(tmp);
		}
	}
	return -1;
}
int main(){
    freopen("P2865_2.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
	}
	//spfa();
	cout<<astar();
	return 0;
}