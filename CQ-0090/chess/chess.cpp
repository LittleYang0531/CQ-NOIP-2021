#include <cstdio>
#define print(x,y) write(x),putchar(y)

template <class T>
inline T read(const T sample) {
	T x=0; char s; bool f=0;
	while((s=getchar())>'9' || s<'0')
		f |= (s=='-');
	while(s>='0' && s<='9')
		x = (x<<1)+(x<<3)+(s^48),
		s = getchar();
	return f?-x:x;
}

template <class T>
inline void write(T x) {
	static int writ[40],w_tp=0;
	if(x<0) putchar('-'),x=-x;
	do writ[++w_tp]=x-x/10*10,x/=10; while(x);
	while(w_tp) putchar(writ[w_tp--]^48);
}

#include <map>
#include <cstring>
using namespace std;
typedef pair <int,int> pii;

const int maxn = 1e5+5;

char opt[maxn];
int n,m,q;

namespace OMG {
	const int maxm = 5005;
	
	int a[maxm][maxm][2],b[maxm][maxm][2];
	map <pii,int> mp;
	struct node {
		int c,p,x,y;
	} s[maxm];
	int vis[maxm*maxm],ans;
	
	inline int ID(int x,int y) {
		return (x-1)*m+y;
	}
	
	bool in(int x,int y) {
		return x<=n && y<=m && x>=1 && y>=1;
	}
	
	void dfs(int c,int p,int x,int y,int id) {
		int tx=x-1,ty=y;
		if(in(tx,ty) && vis[ID(tx,ty)]!=id && b[x][y][0]==3) {
			if(mp.count(make_pair(tx,ty))) {
				int oo=mp[make_pair(tx,ty)];
				if(c!=s[oo].c && p>=s[oo].p) {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			} else {
				++ans; vis[ID(tx,ty)]=id;
				dfs(c,p,tx,ty,id);
			}
		}
		tx=x+1,ty=y;
		if(in(tx,ty) && vis[ID(tx,ty)]!=id && b[x][y][1]==3) {
			if(mp.count(make_pair(tx,ty))) {
				int oo=mp[make_pair(tx,ty)];
				if(c!=s[oo].c && p>=s[oo].p) {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			} else {
				++ans; vis[ID(tx,ty)]=id;
				dfs(c,p,tx,ty,id);
			}
		}
		tx=x,ty=y-1;
		if(in(tx,ty) && vis[ID(tx,ty)]!=id && a[x][y][0]==3) {
			if(mp.count(make_pair(tx,ty))) {
				int oo=mp[make_pair(tx,ty)];
				if(c!=s[oo].c && p>=s[oo].p) {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			} else {
				++ans; vis[ID(tx,ty)]=id;
				dfs(c,p,tx,ty,id);
			}
		}
		tx=x,ty=y+1;
		if(in(tx,ty) && vis[ID(tx,ty)]!=id && a[x][y][1]==3) {
			if(mp.count(make_pair(tx,ty))) {
				int oo=mp[make_pair(tx,ty)];
				if(c!=s[oo].c && p>=s[oo].p) {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			} else {
				++ans; vis[ID(tx,ty)]=id;
				dfs(c,p,tx,ty,id);
			}
		}
	}
	
	void Eat(int c,int p,int x,int y,int tx,int ty,int id) {
		if(in(tx,ty) && vis[ID(tx,ty)]!=id) {
			if(mp.count(make_pair(tx,ty))) {
				int oo=mp[make_pair(tx,ty)];
				if(c!=s[oo].c && p>=s[oo].p) {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			} else {
				++ans;
				vis[ID(tx,ty)]=id;
			}
		}
	}
	
	void ff(int c,int p,int x,int y,int dir,int id) {
		int tx,ty;
		if(!dir) {
			ty=y;
			for(int i=x;i>1;--i) {
				tx=i-1;
				if(b[i][y][0]!=2) return;
				if(vis[ID(tx,ty)]==id) continue;
				if(mp.count(make_pair(tx,ty))) {
					int oo=mp[make_pair(tx,ty)];
					if(c!=s[oo].c && p>=s[oo].p) {
						++ans;
						vis[ID(tx,ty)]=id;
					}
					return;
				} else {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			}
		} else if(dir==1) {
			ty=y;
			for(int i=x;i<n;++i) {
				tx=i+1;
				if(b[i][y][1]!=2) return;
				if(vis[ID(tx,ty)]==id) continue;
				if(mp.count(make_pair(tx,ty))) {
					int oo=mp[make_pair(tx,ty)];
					if(c!=s[oo].c && p>=s[oo].p) {
						++ans;
						vis[ID(tx,ty)]=id;
					}
					return;
				} else {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			}
		} else if(dir==2) {
			tx=x;
			for(int i=y;i>1;--i) {
				ty=i-1; 
				if(a[x][i][0]!=2) return;
				if(vis[ID(tx,ty)]==id) continue;
				if(mp.count(make_pair(tx,ty))) {
					int oo=mp[make_pair(tx,ty)];
					if(c!=s[oo].c && p>=s[oo].p) {
						++ans;
						vis[ID(tx,ty)]=id;
					}
					return;
				} else {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			}
		} else {
			tx=x;
			for(int i=y;i<m;++i) {
				ty=i+1;
				if(a[x][i][1]!=2) return;
				if(vis[ID(tx,ty)]==id) continue;
				if(mp.count(make_pair(tx,ty))) {
					int oo=mp[make_pair(tx,ty)];
					if(c!=s[oo].c && p>=s[oo].p) {
						++ans;
						vis[ID(tx,ty)]=id;
					}
					return;
				} else {
					++ans;
					vis[ID(tx,ty)]=id;
				}
			}
		}
	}
	
	void work() {
		memset(vis,0,sizeof vis); mp.clear();
		n=read(9),m=read(9),q=read(9);
		for(int i=1;i<=n;++i) {
			scanf("%s",opt+1);
			for(int j=1;j<m;++j)
				a[i][j][1]=a[i][j+1][0]=opt[j]-'0';
		}
		for(int i=1;i<n;++i) {
			scanf("%s",opt+1);
			for(int j=1;j<=m;++j)
				b[i][j][1]=b[i+1][j][0]=opt[j]-'0';
		}
		int c,p,x,y;
		for(int i=1;i<=q;++i) {
			scanf("%d %d %d %d",&c,&p,&x,&y);
			s[i] = (node){c,p,x,y};
			ans=0; vis[ID(x,y)]=i;
			
			if(b[x][y][0]==1) Eat(c,p,x,y,x-1,y,i);
			if(b[x][y][1]==1) Eat(c,p,x,y,x+1,y,i);
			if(a[x][y][0]==1) Eat(c,p,x,y,x,y-1,i);
			if(a[x][y][1]==1) Eat(c,p,x,y,x,y+1,i);
			
			if(b[x][y][0]==2) ff(c,p,x,y,0,i);
			if(b[x][y][1]==2) ff(c,p,x,y,1,i);
			if(a[x][y][0]==2) ff(c,p,x,y,2,i);
			if(a[x][y][1]==2) ff(c,p,x,y,3,i);
			
			dfs(c,p,x,y,i);
			
			mp[make_pair(x,y)]=i;
			print(ans,'\n');
		}
	}
}

int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int T=read(9);T;--T) {
		OMG::work();
	}
	return 0;
}
/*
32pts µÄ±©Á¦£¬ÏÈÐ´£¡ 
*/ 
