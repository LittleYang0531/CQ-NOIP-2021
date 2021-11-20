#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 998244353
#define ll long long
#define N 200005
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char _st;
int n,m,k;
ll v[N],ans,bit[N],cnt[N],inv[N];
int count(ll x) {
	int res = 0;
	while(x) {
		res++;x -= x&-x;
	}return res;
}
void dfs(int x,ll S,ll val,int lst) {
	if(!val)return;
	if(x == n+1) {
		if(count(S) <= k)ans = (ans+val)%mod;
		return;
	}
	for(int i=lst; i<=m; ++i) {
		cnt[i]++;
		dfs(x+1,S+bit[i],val*v[i]%mod*x%mod*inv[cnt[i]]%mod,i);
		cnt[i]--;
	}
}
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	file("sequence");
	read(n);read(m);read(k);
	bit[0] = 1;
	for(int i=1; i<=m; ++i)bit[i] = bit[i-1]*2;
	inv[1] = 1;
	for(int i=2; i<=n; ++i)inv[i] = (mod-mod/i)*inv[mod%i]%mod;
	for(int i=0; i<=m; ++i)read(v[i]);
//	for(int i=0; i<=m; ++i)v[i] = rand();
	dfs(1,0,1,0);
	cout << ans << '\n';
}
