#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+101;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

int n,a[N],vis[N],k[N],ans=1e18;
void dfs(int num,int sum) {
	
	//int sum=0;
	//for(int i=1;i<=n;++i) sum+=a[i];
	int d=0;
	for(int i=1;i<=n;++i) d+=(a[i]*n-sum)*(a[i]*n-sum);
	d/=n;
	if(d<ans) ans=d;
	
	if(vis[d]) return ;
	vis[d]=1;
	//cout<<ans<<'\n';
	
	for(int i=2;i<=n-1;++i) {
		int w=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs(num+1,sum-w+a[i]);
		a[i]=w;
	}
}

signed main() {
	
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n=read();
	int sum=0;
	for(int i=1;i<=n;++i) {
		a[i]=read();
		sum+=a[i];
	}
	dfs(1,sum);
	printf("%lld",ans);
	return 0;
}
