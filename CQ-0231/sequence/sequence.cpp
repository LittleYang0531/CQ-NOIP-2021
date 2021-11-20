#include <bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int N=35,M=105,mod=998244353;
int n,m,k,v[M],a[N],ans,tot,b[N];
int s[111];
bool check() {
	memset(s,0,sizeof s);
	for(int i=1;i<=n;++i) ++s[a[i]];
	int tot=0;
	for(int i=0;i<=106;++i) {
		s[i+1]+=(s[i]>>1);
		s[i]&=1;
		if(s[i]) ++tot;
	}
	return tot<=k;
}
void dfs(int x,int t) {
	if(t==n) {
		if(check()) {
			int tmp=1,tmp1=1;
			memset(b,0,sizeof b);
			tot=0;
			for(int i=1;i<=n;++i) {
				if(a[i]!=a[i-1]||i==1) b[++tot]=1;
				else ++b[tot];
			}
			for(int i=1;i<=n;++i) tmp=tmp*i;
			for(int i=1;i<=tot;++i)
			for(int j=2;j<=b[i];++j)
				tmp/=j;
			for(int i=1;i<=n;++i) tmp1=(tmp1*v[a[i]])%mod;
			ans=(ans+tmp*tmp1%mod)%mod;
		}
		return;
	}
	for(int i=x;i<=m;++i) {
		a[t+1]=i;
		dfs(i,t+1);
	}
}
void baoli() {
	dfs(0,0);
	write(ans);
}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;++i) v[i]=read();
	baoli();
	return 0;
}
/*
5 1 1
2 1

40

8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699

642171527
*/
