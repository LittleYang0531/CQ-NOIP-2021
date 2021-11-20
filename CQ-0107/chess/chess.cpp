#include<bits/stdc++.h>
#define cin lin
#define cout lout
#define int long long
using namespace std;
const int dd[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
string s;
int T,N,M,Q,col,lv,sx,sy,ans=0;//memset!
int opt[200010][5],a[200010][2];
bool has[200010];
bool vis[5010],can[5010];//sub1
queue<pair<int,int> >q;
int h(int x,int y) {return (x-1)*M+y;}
int nxt(int p,int dir) {
	if (dir==0) return p>M ? p-M:0;
	if (dir==1) return p%M ? p+1:0;
	if (dir==2) return p-(N-1)*M>0 ? 0:p+M;
	return p%M==1 ? 0:p-1;
}
bool in(int x,int y) {return x>=1 && x<=N && y>=1 && y<=M;}
bool check_eat(int p1,int p2) {return a[p1][0]!=a[p2][0] && a[p1][1]>=a[p2][1];}
void bfs(int sx,int sy) {
	while (!q.empty()) q.pop();
	vis[h(sx,sy)]=1;
	q.push(make_pair(sx,sy));
	while (!q.empty()) {
		int nowx=q.front().first;
		int nowy=q.front().second;
		int p1=h(nowx,nowy);
		q.pop();
		for (int i=0;i<4;i++) {
			int dx=nowx+dd[i][0];
			int dy=nowy+dd[i][1];
			int p2=h(dx,dy);
			if (!in(dx,dy) || vis[p2] || opt[p1][i]!=3) continue;
			if (has[p2]) {
				can[p2]=(check_eat(h(sx,sy),p2) ? 1:0);
				continue;
			}
			can[p2]=1,vis[p2]=1;
			q.push(make_pair(dx,dy));
		}
	}
	return;
}
void sub1(int od,int sx,int sy) {
	for (int i=0;i<4;i++) {
		int dx=sx+dd[i][0];
		int dy=sy+dd[i][1];
		int p1=h(sx,sy),p2=h(dx,dy);
		if (opt[p1][i]!=1 || !in(dx,dy)) continue;
		if (!has[p2] || (has[p2] && check_eat(p1,p2))) can[p2]=1;
	}//处理1 
	for (int i=0;i<4;i++) {
		int dx=sx+dd[i][0];
		int dy=sy+dd[i][1];
		int p1=h(sx,sy);
		if (opt[p1][i]!=2 || !in(dx,dy)) continue;
		for (int p2=h(dx,dy);p2;p2=nxt(p2,i)) {
			if (!has[p2] || (has[p2] && check_eat(p1,p2))) can[p2]=1;
			if (opt[p2][i]!=2 || has[p2]) break;
		}
	}//处理2 
	bfs(sx,sy);//处理3
	for (int i=1;i<=N*M;i++) ans+=(int)can[i];
	return; 
}
signed main() {
	ifstream cin("chess.in");
	ofstream cout("chess.out");
	cin>>T;
	while (T--) {
		cin>>N>>M>>Q;
		memset(a,0,sizeof(a));
		memset(has,0,sizeof(has));
		for (int i=1;i<=N;i++) {
			cin>>s;
			for (int j=0;j<(int)s.size();j++) {
				int val=s[j]-'0';
				opt[h(i,j+1)][1]=opt[h(i,j+2)][3]=val;
			}
		}
		for (int i=1;i<N;i++) {
			cin>>s;
			for (int j=0;j<(int)s.size();j++) {
				int val=s[j]-'0';
				opt[h(i,j+1)][2]=opt[h(i+1,j+1)][0]=val;
			}
		}
	    for (int i=1;i<=Q;i++) {
			cin>>col>>lv>>sx>>sy;
			ans=0;
			memset(vis,0,sizeof(vis));
			memset(can,0,sizeof(can));
			int p=h(sx,sy);
			has[p]=1;
			a[p][0]=col;
			a[p][1]=lv;
			sub1(i,sx,sy);
			cout<<ans<<endl;
		}
	}
	return 0;
}
