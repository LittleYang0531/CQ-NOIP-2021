#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

enum {
    u,r,d,l
};

int ans;
int n,m,q;
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};
vector<vector<int>> a;
vector<vector<int>> b;
vector<vector<int>> s;
vector<vector<int>> col;
vector<vector<int>> put;
vector<vector<int>> vis;
vector<vector<int>> level;

int get(int i,int j,int f) {
	if(f==0) {
		if(i==0) {
			return 0;
		}
		return b[i-1][j];
	} else if(f==1) {
		if(j==m) {
			return 0;
		}
		return a[i][j];
	} else if(f==2) {
		if(i==n) {
			return 0;
		}
		return b[i][j];
	} else {
		if(j==1) {
			return 0;
		}
		return a[i][j-1];
	}
}

void dfs(int x,int y,int type,int col,int level,int op) {
//	cerr<<x<<" "<<y<<"\n";
	if(put[x][y]) {
		if(::col[x][y]==col||::level[x][y]>level) {
			return ;
		}
		if(!s[x][y]) {
			s[x][y]=true;
			ans++;
		}
		return ;
	}
	if(!s[x][y]) {
		s[x][y]=true;
		ans++;
	}
	vis[x][y]=true;
	if(type==1) {
		return ;
	}
	for(int i=0; i<=3; i++) {
		if(!get(x,y,i)||(get(x,y,i)!=type)) {
			continue;
		}
		if(type==2&&i!=op) {
			continue;
		}
		if(vis[x+dx[i]][y+dy[i]]) {
			continue;
		}
		dfs(x+dx[i],y+dy[i],type,col,level,op);
	}
}

//void dfs2(int x,int y,int type,int col,int level,int op) {
//	if(put[x][y]) {
//		if(::col[x][y]==col||::level[x][y]>level) {
//			return ;
//		}
//		s[x][y]=false;
//		return ;
//	}
//	s[x][y]=false;
//	vis[x][y]=true;
//	if(type==1) {
//		vis[x][y]=false;
//		return ;
//	}
//	for(int i=0; i<=3; i++) {
//		if(!get(x,y,i)||(get(x,y,i)!=type)) {
//			continue;
//		}
//		if(type==2&&i!=op) {
//			continue;
//		}
//		if(vis[x+dx[i]][y+dy[i]]) {
//			continue;
//		}
//		dfs2(x+dx[i],y+dy[i],type,col,level,op);
//	}
//	vis[x][y]=false;
//}

signed main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>m>>q;
		a.clear();
		b.clear();
		s.clear();
		col.clear();
		put.clear();
		vis.clear();
		level.clear();
		a.resize(n+1,vector<int>(m+1));
		b.resize(n+1,vector<int>(m+1));
		s.resize(n+1,vector<int>(m+1));
		col.resize(n+1,vector<int>(m+1));
		put.resize(n+1,vector<int>(m+1));
		vis.resize(n+1,vector<int>(m+1));
		level.resize(n+1,vector<int>(m+1));
		int f=1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m-1; j++) {
				char ch;
				cin>>ch;
				a[i][j]=ch-'0';
				if(a[i][j]>=2) {
					f=0;
				}
			}
		}
		for(int i=1; i<=n-1; i++) {
			for(int j=1; j<=m; j++) {
				char ch;
				cin>>ch;
				b[i][j]=ch-'0';
				if(a[i][j]>=2) {
					f=0;
				}
			}
		}
		if(f) {
			while(q--) {
				int col,level,x,y;
				cin>>col>>level>>x>>y;
				put[x][y]=true;
				::col[x][y]=col,::level[x][y]=level;
				ans=0;
				for(int i=0; i<=3; i++) {
					if(get(x,y,i)!=0) {
						int nx=x+dx[i],ny=y+dy[i];
						if(!put[nx][ny]) {
							ans++;
						} else {
							if(::col[nx][ny]==col||::level[nx][ny]>level) {
								continue;
							}
							ans++;
						}
					}
				}
				cout<<ans<<"\n";
			}
			continue;
		}
		while(q--) {
			int col,level,x,y;
			cin>>col>>level>>x>>y;
			s[x][y]=put[x][y]=true;
			::col[x][y]=col,::level[x][y]=level;
			ans=0;
			for(int i=0; i<=3; i++) {
				if(get(x,y,i)!=0) {
					vis.clear();
					vis.resize(n+1,vector<int>(m+1));
					vis[x][y]=true;
					dfs(x+dx[i],y+dy[i],get(x,y,i),col,level,i);
				}
			}
			vis[x][y]=false;
			s.clear();
			s.resize(n+1,vector<int>(m+1));
//			s.clear();
//			s.resize(n+1,vector<int>(m+1));
			cout<<ans<<"\n";
		}
	}
}
