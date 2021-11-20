#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
void put(int x) {
	if(x>=10) put(x/10);
	putchar(x%10+'0');
}
const int p=998244353;
int n,m,k,res;
int a[32],t[64],v[101],sum[32][32];
bitset<106> s;
int f() {
	int len=1,res=1;
	for(register int i=1; i<=n; ++i) {
		if(a[i]!=a[i+1]) res=(res*sum[n-(i-len)][len])%p,len=1;
		else ++len;
	}
	return res;
}
void dfs(const int x) {
	if(x>n) {
		if(s.count()<=k) {
			int add=1;
			for(register int i=1; i<=n; ++i) add=add*v[a[i]]%p;
			res=(res+add*f())%p;
		}
		return;
	}
	for(register int i=a[x-1]; i<=m; ++i) {
		register int o=i;
		while(s[o]) s[o]=0,++o; s[o]=1;
		a[x]=i,dfs(x+1);
		o=i;
		while(!s[o]) s[o]=1,++o; s[o]=0; 
	}
}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read(),t[0]=1;
	for(register int i=0; i<=n; ++i) {
		sum[i][0]=1;
		for(register int j=1; j<=i; ++j) sum[i][j]=(sum[i-1][j-1]+sum[i-1][j])%p;
	}
	for(register int i=0; i<=m; ++i) v[i]=read();
	dfs(1),put(res);
	return 0;
}
