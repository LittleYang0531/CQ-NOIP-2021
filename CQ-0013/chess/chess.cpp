#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 200005
#define LL long long
#define ENDL putchar('\n')
#define DB double
#define lowbit(x) (-(x) & (x))
#define FI first
#define SE second
#define PR pair<int,int>
LL read() {
	LL f = 1,x = 0;int s = getchar();
	while(s < '0' || s > '9') {if(s<0)return -1;if(s=='-')f=-f;s = getchar();}
	while(s >= '0' && s <= '9') {x = (x<<1) + (x<<3) + (s^48);s = getchar();}
	return f*x;
}
void putpos(LL x) {if(!x)return ;putpos(x/10);putchar((x%10)^48);}
void putnum(LL x) {
	if(!x) {putchar('0');return ;}
	if(x<0) putchar('-'),x = -x;
	return putpos(x);
}
void AIput(LL x,int c) {putnum(x);putchar(c);}

int n,m,s,o,k;
int N;
int I(int x,int y) {return (x-1)*m+y;}
int I2(int x,int y) {return (y-1)*n+x;}
int ok2(int a,int b) {
	return m > 1 && (b == a+1 || b == a-1);
}
int tre[MAXN*64],cnt;
int ls[MAXN*64],rs[MAXN*64];
int newp() {
	++ cnt; tre[cnt] = ls[cnt] = rs[cnt] = 0;
	return cnt;
}
int addtree(int a,int x,int al,int ar) {
	if(al > x || ar < x) return a;
	if(!a) a = newp();
	if(al == ar) {tre[a] ++; return a;}
	int md = (al + ar) >> 1;
	ls[a] = addtree(ls[a],x,al,md);
	rs[a] = addtree(rs[a],x,md+1,ar);
	tre[a] = tre[ls[a]] + tre[rs[a]];
	return a;
}
int mergtree(int a,int b) {
	if(!a || !b) return a+b;
	tre[a] += tre[b];
	ls[a] = mergtree(ls[a],ls[b]);
	rs[a] = mergtree(rs[a],rs[b]);
	return a;
}
int findtree(int a,int l,int r,int al,int ar) {
	if(al > r || ar < l || l > r || !a) return 0;
	if(al >= l && ar <= r) return tre[a];
	int md = (al + ar) >> 1;
	return findtree(ls[a],l,r,al,md) + findtree(rs[a],l,r,md+1,ar);
}
int rt1[MAXN],rt2[MAXN];
int fa[MAXN],fa2[MAXN],fa3[MAXN];
int l2[MAXN],r2[MAXN],l3[MAXN],r3[MAXN];
int findf(int x) {return x==fa[x] ? x:(fa[x]=findf(fa[x]));}
int findf2(int x) {return x==fa2[x] ? x:(fa2[x]=findf2(fa2[x]));}
int findf3(int x) {return x==fa3[x] ? x:(fa3[x]=findf3(fa3[x]));}
void unionSet(int a,int b) {
	int u = findf(a),v = findf(b);
	if(u == v) return ;
	fa[u] = v; rt1[v] = mergtree(rt1[v],rt1[u]);
	rt2[v] = mergtree(rt2[v],rt2[u]);
}
void unionSet2(int a,int b) {
	int u = findf2(a),v = findf2(b);
	if(u == v) return ;
	fa2[u] = v;
	l2[v] = min(l2[v],l2[u]); r2[v] = max(r2[v],r2[u]);
}
void unionSet3(int a,int b) {
	int u = findf3(a),v = findf3(b);
	if(u == v) return ;
	fa3[u] = v;
	l3[v] = min(l3[v],l3[u]); r3[v] = max(r3[v],r3[u]);
}
int ti[MAXN];
int hd[MAXN],v[MAXN<<2],nx[MAXN<<2],w[MAXN<<2],cne;
void ins(int x,int y,int z) {
	nx[++cne] = hd[x]; v[cne] = y; w[cne] = z; hd[x] = cne;
}
char ss[MAXN];
PR p[MAXN],ad[MAXN];
vector<PR> bu[MAXN];
void addp(int x,int y,int tm) {
	int p = I(x,y),p2 = I2(x,y);
	rt1[p] = addtree(rt1[p],p,1,N);
	rt2[p] = addtree(rt2[p],p2,1,N);
	for(int i = hd[p];i;i = nx[i]) {
		if(ti[v[i]] < tm) continue;
		if(w[i] == 3) unionSet(p,v[i]);
		if(w[i] == 2) {
			if(ok2(p,v[i])) {
				unionSet2(p,v[i]);
			}
			else unionSet3(p,v[i]);
		}
	}return ;
}
bool OK(int a,int b) {
	return findf(a) == findf(b) || findf2(a) == findf2(b) || findf3(a) == findf3(b);
}
int res[MAXN];
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T = read();
	while(T --) {
		n = read();m = read();k = read();
		cnt = 0; N = n*m; cne = 0;
		for(int i = 1;i <= N;i ++) {
			fa[i] = fa2[i] = fa3[i] = i;
			rt1[i] = rt2[i] = 0;
			l2[i] = r2[i] = i;
			ti[i] = k+1; hd[i] = 0;
		}
		int mxw = 0;
		for(int i = 1;i <= n;i ++) {
			scanf("%s",ss + 1);
			for(int j = 1;j < m;j ++) {
				int op = ss[j]-'0';
				if(op) ins(I(i,j),I(i,j+1),op);
				if(op) ins(I(i,j+1),I(i,j),op);
				mxw = max(mxw,op);
			}
		}
		for(int i = 1;i < n;i ++) {
			scanf("%s",ss + 1);
			for(int j = 1;j <= m;j ++) {
				int op = ss[j]-'0';
				if(op) ins(I(i,j),I(i+1,j),op);
				if(op) ins(I(i+1,j),I(i,j),op);
				mxw = max(mxw,op);
			}
		}
		for(int i = 1;i <= k;i ++) {
			int c = read(),vl = read();
			s = read();o = read();
			ad[i] = make_pair(s,o);
			ti[I(s,o)] = i;
			p[I(s,o)] = make_pair(c,vl);
			bu[i].clear();
		}
		bu[k+1].clear();
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= m;j ++) {
				l3[I(i,j)] = r3[I(i,j)] = I2(i,j);
				bu[ti[I(i,j)]].push_back(make_pair(i,j));
			}
		}
		for(int i = 0,le = bu[k+1].size();i < le;i ++) {
			addp(bu[k+1][i].FI,bu[k+1][i].SE,k+1);
		}
		for(int i = k;i > 0;i --) {
			s = ad[i].FI; o = ad[i].SE;
			addp(s,o,i);
			int me = I(s,o);
			int f1 = findf(me),f2 = findf2(me),f3 = findf3(me);
			int ans = tre[rt1[f1]]-1 + (r2[f2]-l2[f2]) + (r3[f3]-l3[f3]);
			ans -= findtree(rt1[f1],l2[f2],r2[f2],1,N)-1 + findtree(rt2[f1],l3[f3],r3[f3],1,N)-1;
			for(int j = hd[me];j;j = nx[j]) {
				if(w[j] == 1) {
					if(ti[v[j]] >= i && !OK(me,v[j])) ans ++;
				}
			}
			if(mxw > 1) {
				for(int jj = i-1;jj > 0;jj --) {
					int y = I(ad[jj].FI,ad[jj].SE);
					if(p[y].FI == p[me].FI || p[y].SE > p[me].SE) continue;
					for(int j = hd[y];j;j = nx[j]) {
						if(w[j] == 3) {
							if(findf(v[j]) == findf(me)) {ans ++;break;}
						}
						if(w[j] == 2) {
							if(ok2(y,v[j])) {
								if(findf2(v[j]) == findf2(me)) {ans ++;break;}
							}
							else if(findf3(v[j]) == findf3(me)) {ans ++;break;}
						}
					}
				}
			}
			for(int j = hd[me];j;j = nx[j]) {
				if(w[j] == 1 && ti[v[j]] < i) {
					if(p[v[j]].FI != p[me].FI && p[v[j]].SE <= p[me].SE) ans ++;
				}
			}
			res[i] = ans;
		}
		for(int i = 1;i <= k;i ++) {
			AIput(res[i],'\n');
		}
	}
	return 0;
}
