#include<bits/stdc++.h>
#define maxn 105
#define int long long
#define mod 998244353
using namespace std;
inline int read(){
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
int n,m,k;
int ans;
int v[maxn],a[maxn];
int two(int n){
	int cnt=0;
	while(n){
		cnt+=(n%2);
		n/=2;
	}
	return cnt;
}
void dfs(int x){
	if(x==n+1){
		int sum=0;
		for(int i=1;i<=n;i++) sum+=pow(2,a[i]);
		if(two(sum)<=k){
			sum=1;
			for(int i=1;i<=n;i++) sum*=v[a[i]],sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		a[x]=i;
		dfs(x+1);
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=0;i<=m;i++) v[i]=read();
	dfs(1);
	printf("%lld",ans);
	return 0;
}
