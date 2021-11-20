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
#include <iostream>
using namespace std;
typedef long long ll;

const int lim = 2e7;
const int maxn = 1e4+5;
const int bas = 233, mod = 998344853;

int n,a[maxn],tot;
map <int,bool> mp;
ll ans = 1e17;

void dfs(int *a) {
	++tot;
	if(tot>lim) {
		print(ans,'\n');
		exit(0);
	}
	int tmp,t[21],hs=0; ll ret=0,sm=0;
	for(int i=1;i<=n;++i) {
		t[i]=a[i]; sm += a[i];
		ret += 1ll*n*a[i]*a[i];
		hs = (1ll*hs*bas%mod+t[i])%mod;
	}
	ans = min(ans,ret-1ll*sm*sm);
	if(mp.count(hs)) return;
	mp[hs]=1;
	for(int i=2;i<n;++i)
		if(t[i-1]+t[i+1]-t[i]!=t[i]) {
			tmp = t[i];
			t[i] = t[i-1]+t[i+1]-t[i];
			dfs(t);
			t[i] = tmp;
		}
}

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read(9);
	for(int i=1;i<=n;++i)
		a[i]=read(9);
	dfs(a); print(ans,'\n');
	return 0;
}
/*
woc！！！这是不是均值不等式？
所以呢......
不过这个数据范围不像是构造嘛
不会是网络流吧，好像也不是
实在不行就掐表吧！ 
*/
