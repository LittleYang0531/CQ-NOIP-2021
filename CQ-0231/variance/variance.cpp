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
const int N=10005;
int n,a[N],ans=1e18;
bool vis[N];
map<string,bool> mp;
string S() {
	string s="";
	for(int i=1;i<=n;++i) s+=(char)a[i],s+=' ';
	return s;
}
void dfs() {
	int sum=0,fc=0;
	for(int i=1;i<=n;++i) sum+=a[i];
	for(int i=1;i<=n;++i) fc+=(sum-a[i]*n)*(sum-a[i]*n);
	if(n>4&&fc>ans+ans/n) return;
	ans=min(ans,fc);
	string s;
	for(int i=2,tmp;i<n;++i) {
		if(a[i-1]+a[i+1]-a[i]!=a[i]) {
			tmp=a[i],a[i]=a[i-1]+a[i+1]-a[i];
			s=S();
			if(mp[s]) a[i]=tmp;
			else mp[s]=1,dfs(),a[i]=tmp;
		}
	}
}
void baoli() {
	dfs();
	write(ans/n);
}
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
//	if(n<=10) {
		baoli();
//		return 0;
//	}
	return 0;
}
/*
4
1 2 4 6

52

10
6 19 34 35 56 63 82 82 83 99

59865
*/
