#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 1000000007
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char _st;
int T,n,m,Q;
namespace bf {
	int r[5005][5005],d[5005][5005],vst[5005][5005],cur,tag[5005][5005],c,lv;
	struct NIT {
		int c,lv;
	}a[5005][5005];
	int cmp(int x,int y) {
		if(x < 1 || x > n || y < 1 || y > m)return 0;
		if(c == a[x][y].c)return 0;
		return lv>=a[x][y].lv?cur:0;
	}
	bool check(int x,int y){return 1 <= x && x <= n && 1 <= y && y <= m && tag[x][y] != cur && cmp(x,y);}
	int id(int x,int y){return (x-1)*m+y;}
	void dfs(int x,int y) {
		if(vst[x][y] == cur)return;
		vst[x][y] = cur;if(a[x][y].lv)return;
		if(check(x,y+1) && r[x][y] == 3)dfs(x,y+1);
		if(check(x,y-1) && r[x][y-1] == 3)dfs(x,y-1);
		if(check(x+1,y) && d[x][y] == 3)dfs(x+1,y);
		if(check(x-1,y) && d[x-1][y] == 3)dfs(x-1,y);
	}
	void LDFS(int x,int y) {
		tag[x][y] = cur;if(a[x][y].lv)return;
		if(check(x,y-1) && r[x][y-1] == 2)LDFS(x,y-1);
	}
	void RDFS(int x,int y) {
		tag[x][y] = cur;if(a[x][y].lv)return;
		if(check(x,y+1) && r[x][y] == 2)RDFS(x,y+1);
	}
	void UDFS(int x,int y) {
		tag[x][y] = cur;if(a[x][y].lv)return;
		if(check(x-1,y) && d[x-1][y] == 2)UDFS(x-1,y);
	}
	void DDFS(int x,int y) {
		tag[x][y] = cur;if(a[x][y].lv)return;
		if(check(x+1,y) && d[x][y] == 2)DDFS(x+1,y);
	}
	void solve() {
		char s[5005];
		for(int i=1; i<=n; ++i) {
			scanf("%s",s+1);
			for(int j=1; j<m; ++j) {
				r[i][j] = s[j]-'0';
			}
		}
		for(int i=1; i<n; ++i) {
			scanf("%s",s+1);
			for(int j=1; j<=m; ++j) {
				d[i][j] = s[j]-'0';
			}
		}
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				a[i][j] = {-1,0};
		memset(vst,0,sizeof(vst));
		memset(tag,0,sizeof(tag));
		cur = 0;
		while(Q--) {
			int x,y;
			read(c);read(lv);read(x);read(y);
			cur++;
			dfs(x,y);
			RDFS(x,y);LDFS(x,y);UDFS(x,y);DDFS(x,y);
			if(r[x][y] == 1 && vst[x][y+1] != cur)vst[x][y+1] = cmp(x,y+1);
			if(d[x][y] == 1 && vst[x+1][y] != cur)vst[x+1][y] = cmp(x+1,y);
			if(r[x][y-1] == 1 && vst[x][y-1] != cur)vst[x][y-1] = cmp(x,y-1);
			if(d[x-1][y] == 1 && vst[x-1][y] != cur)vst[x-1][y] = cmp(x-1,y);
			int ans = 0;
//			for(int i=1; i<=n; ++i,cout << '\n')
//				for(int j=1; j<=m; ++j)
//					cout << (vst[i][j]==cur) << ' ';
//			for(int i=1; i<=n; ++i,cout << '\n')
//				for(int j=1; j<=m; ++j)
//					cout << (tag[i][j]==cur) << ' ';
			for(int i=1; i<=n; ++i)
				for(int j=1; j<=m; ++j)
					if(vst[i][j] == cur || tag[i][j] == cur)ans++;
			cout << ans-1 << '\n';
			a[x][y] = {c,lv};
		}
	}
}
namespace NO_UP_NIT {
	int r[200005],d[200005],c,lv;
	struct NIT {
		int c,lv;
	}a[200005];
	int id(int x,int y){return (x-1)*m+y;}
	int cmp(int x,int y) {
		if(x < 1 || x > n || y < 1 || y > m)return 0;
		if(c == a[id(x,y)].c)return 0;
		return lv>=a[id(x,y)].lv?1:0;
	}
	void solve() {
		char s[100005];
		for(int i=1; i<=n; ++i) {
			scanf("%s",s+1);
			for(int j=1; j<m; ++j) {
				r[id(i,j)] = s[j]-'0';
			}
		}
		for(int i=1; i<n; ++i) {
			scanf("%s",s+1);
			for(int j=1; j<=m; ++j) {
				d[id(i,j)] = s[j]-'0';
			}
		}
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				a[id(i,j)] = {-1,0};
		while(Q--) {
			int x,y;
			read(c);read(lv);read(x);read(y);
			int ans = 0;
			if(r[id(x,y)] == 1)ans += cmp(x,y+1);
			if(d[id(x,y)] == 1)ans += cmp(x+1,y);
			if(r[id(x,y-1)] == 1)ans += cmp(x,y-1);
			if(d[id(x-1,y)] == 1)ans += cmp(x-1,y);
			cout << ans << '\n';
			a[id(x,y)] = {c,lv};
		}
	}
}
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	file("chess");
	read(T);
	while(T--) {
		read(n);read(m);read(Q);
		if(n <= 5000 && m <= 5000 && Q <= 2000)bf::solve();
		else NO_UP_NIT::solve();
	}
}
/*
1
3 3 5
11
11
11
010
111
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
