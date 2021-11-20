#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<algorithm>
#include<queue>
#define INF 0x7fffffff
using namespace std;
int n,m,q,cnt2,cnt21,cnt23,cnt22,cnt3,ans,T;
int vst[200005],vv[200005],dis[200005],diss[200005],belong[200005],PD[200005];
int h23[400005],h22[400005],h21[400005],h2[400005],h3[800005];
int mapp[200005][10];
struct edge2 {
	int to,next;
} e2[200005];
struct edge21 {
	int to,next;
} e21[200005];
struct edge22 {
	int to,next;
} e22[200005];
struct edge23 {
	int to,next;
} e23[200005];
struct edge3 {
	int to,next;
} e3[200005];
inline void addedge2(int x,int y) {
	cnt2++;
	e2[cnt2].to=y;
	e2[cnt2].next=h2[x];
	h2[x]=cnt2;
}
inline void addedge21(int x,int y) {
	cnt21++;
	e21[cnt21].to=y;
	e21[cnt21].next=h21[x];
	h21[x]=cnt21;
}
inline void addedge22(int x,int y) {
	cnt22++;
	e22[cnt22].to=y;
	e22[cnt22].next=h22[x];
	h22[x]=cnt22;
}
inline void addedge23(int x,int y) {
	cnt23++;
	e23[cnt23].to=y;
	e23[cnt23].next=h23[x];
	h23[x]=cnt23;
}
inline void addedge3(int x,int y) {
	cnt3++;
	e3[cnt3].to=y;
	e3[cnt3].next=h3[x];
	h3[x]=cnt3;
}
void Sch1(int x) {
	for(int i=1; i<=mapp[x][0]; i++) {
		if(!vv[mapp[x][i]]) ans++,vst[mapp[x][i]]=1,vv[mapp[x][i]]=1;
	}
}
void Sch2(int s) {
	queue<int> q;
	q.push(s);
	while(q.empty()) {
		int u=q.front();
		q.pop();
		vst[u]=0;
		for(int i=h2[u]; i; i=e2[i].next) {
			int y=e2[i].to;
			belong[y]=s;
			if(!vst[y]) {
				if(vv[y]==0) diss[s]++;
				q.push(y);
				vst[y]=1;
			}
			vv[y]=1;
		}
	}
}
void Sch21(int s) {
	queue<int> q;
	q.push(s);
	while(q.empty()) {
		int u=q.front();
		q.pop();
		vst[u]=0;
		for(int i=h21[u]; i; i=e21[i].next) {
			int y=e21[i].to;
			belong[y]=s;
			if(!vst[y]) {
				if(vv[y]==0) diss[s]++;
				q.push(y);
				vst[y]=1;
			}
			vv[y]=1;
		}
	}
}
void Sch22(int s) {
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		vst[u]=0;
		for(int i=h22[u]; i; i=e22[i].next) {
			int y=e22[i].to;
			belong[y]=s;
			if(!vst[y]) {
				if(vv[y]==0) diss[s]++;
				q.push(y);
				vst[y]=1;
			}
			vv[y]=1;
		}
	}
}
void Sch23(int s) {
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		vst[u]=0;
		for(int i=h23[u]; i; i=e23[i].next) {
			int y=e23[i].to;
			belong[y]=s;
			if(!vst[y]) {
				if(vv[y]==0) diss[s]++;
				q.push(y);
				vst[y]=1;
			}
			vv[y]=1;
		}
	}
}
void Sch3(int s) {
	queue<int> q;
	belong[s]=s;
	q.push(s);
	vst[s]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
//		vst[u]=0;
		for(int i=h3[u]; i; i=e3[i].next) {
			int y=e3[i].to;
			belong[y]=s;
			if(!vst[y]) {
				if(vv[y]==0) dis[s]++;
				q.push(y);
				vst[y]=1;
			}
			vv[y]=1;
//			cout<<y;
		}
	}
}
signed main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<m; j++) {
				char c;
				cin>>c;
//				c=getchar();
				int x=(i-1)*m+j,y=x+1;
				if(c=='0') ;
				else if(c=='1') {
					mapp[x][++mapp[x][0]]=y;
					mapp[y][++mapp[y][0]]=x;
				} else if(c=='2') {
					addedge2(x,y);
					addedge21(y,x);
				} else if(c=='3') {
					PD[x]=PD[y]=1;
					addedge3(x,y);
					addedge3(y,x);
				}
			}
		}
		for(int i=1; i<n; i++) {
			for(int j=1; j<=m; j++) {
				char c;
				cin>>c;
//				cout<<"**"<<c<<"**"<<endl;
				int x=(i-1)*m+j,y=x+m;
				if(c=='0') ;
				else if(c=='1') {
					mapp[x][++mapp[x][0]]=y;
					mapp[y][++mapp[y][0]]=x;
				} else if(c=='2') {
					addedge22(x,y);
					addedge23(y,x);
				} else if(c=='3') {
					PD[x]=PD[y]=1;
					addedge3(x,y);
					addedge3(y,x);
				}
			}
		}
		for(int i=1; i<=n*m; i++) vst[i]=0,belong[i]=i,vv[i]=0,dis[i]=diss[i]=0;
		for(int i=1; i<=n*m; i++) {
			if(!vst[i]&&PD[i]==1) Sch3(i);
		}
		for(int i=1; i<=n*m; i++) dis[i]=dis[belong[i]];
		while(q--) {
			int A,B,C,D;
			ans=0;
			scanf("%d%d%d%d",&A,&B,&C,&D);
			for(int i=1;i<=n*m;i++) vv[i]=0,diss[i]=0,vst[i]=0;
			Sch1((C-1)*m+D);
			Sch2((C-1)*m+D);
			Sch21((C-1)*m+D);
			Sch22((C-1)*m+D);
			Sch23((C-1)*m+D);
//			cout<<diss[(C-1)*m+D]<<endl;
			ans+=dis[(C-1)*m+D]+diss[(C-1)*m+D];
			printf("%d\n",ans);
		}
	}
	return 0;
}

// 没有时间了 
