#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
void put(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) put(x/10);
	putchar(x%10+'0');
}
const int Maxn=10001;
int n,a[Maxn],res=1e9,ha=37;
map<int,bool> mp;

int solve() {
	long double ans=0,k=0;
	for(int i=1;i<=n;++i) k+=a[i];
	k/=n;
	for(int i=1;i<=n;++i) ans+=(a[i]-k)*(a[i]-k);
	return (int)(n*ans);
}
int hash() {
	int res=0;
	for(int i=1;i<=n;++i) res=res*ha+a[i];
	return res;
}
void dfs() {
	int k=hash();
	if(mp.find(k)==mp.end()) mp[k]=1,res=min(res,solve());
	else return;
	for(int i=2; i<n; ++i) a[i]=a[i-1]+a[i+1]-a[i],dfs(),a[i]=a[i-1]+a[i+1]-a[i];
}
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	dfs(),put(res);
	return 0;
}
