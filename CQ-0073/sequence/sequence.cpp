#include<bits/stdc++.h>
using namespace std;
typedef long long van;
template<typename T> inline
void read(T& x) {
	T f=1,b=0;char ch=getchar();
	while (!isdigit(ch)) {
		if (ch=='-') f=-1;
		ch=getchar();
	} while (isdigit(ch))
		b*=10,b+=ch^'0',ch=getchar();
	x=f*b;return;
}
template<typename T> inline
void print(T x) {
	if (x<0) putchar('-'),x=-x;
	if (x>9) print(x/10);putchar(x%10^'0');
}
const van MaxN=30+10;
const van MaxM=100+10;
const van MaxS=1<<13;
const van mod=998244353;
van n,m,K,v[MaxM];
van power(van a,van b=mod-2) {
	van base=a,ans=1;
	while (b) {
		if (b&1) ans*=base,ans%=mod;
		base*=base,base%=mod,b>>=1;
	} return ans;
}
van C(van a,van b) {
	van ans=1;for (int i=a,j=b;i>0;i--,j--) 
	ans*=j,ans%=mod,ans*=power(i),ans%=mod; return ans;
}
van count(van x) {
	van ans=0;while (x) {
		if (x&1) ans++;
		x>>=1;
	} return ans;
}
van dp[MaxM][MaxN][MaxS];
van c[MaxM][MaxM];
van p[MaxM][MaxN];
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m),read(K);
	for (int i=0;i<=m;i++) read(v[i]);
	for (int i=0;i<=m;i++) for (int j=0;j<=n;j++) p[i][j]=power(v[i],j);
	for (int i=0;i<=n;i++) for (int j=i;j<=n;j++) c[j][i]=C(i,j);
//	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++) cout<<c[j][i]<<" ";
	dp[0][0][0]=1;for (int i=1;i<=m+1;i++) {
		for (int j=0;j<=n;j++) {
			for (int s=0;s<=n*(1<<m);s++) {
				for (int addj=0;addj<=n-j;addj++) {
					van tos=s+(1<<(i-1))*addj,toj=j+addj;
					dp[i][toj][tos]+=
					dp[i-1][j][s]*c[n-j][addj]%mod*p[i-1][addj]%mod;
					dp[i][toj][tos]%=mod;
//					cout<<dp[i-1][j][s]<<" "<<c[n-j][addj]<<" "<<p[i-1][addj]<<endl;
				} 
			}
		} 
	} van ans=0;
	for (int s=n;s<=n*(1<<m);s++) {
		if (count(s)<=K) ans+=dp[m+1][n][s],ans%=mod;
	} print(ans);
	return 0;
}

