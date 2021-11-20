#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
const int maxn = 10010;
int a[maxn],b[maxn],c[maxn],n,f[maxn];
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=a[i]-a[i-1];
	int res=1;ll aws=1e18;
	for(int i=1;i<n;i++) f[i]=i,res*=i;
	while(res--) {
		ll ans=0,S=0;
		for(int i=2;i<=n;i++) c[f[i-1]+1]=b[i];
		c[1]=b[1];
		for(int i=1;i<=n;i++) c[i]+=c[i-1],ans+=1ll*c[i]*c[i],S+=c[i];
		ans*=n;
		aws=min(aws,ans-S*S);
		next_permutation(f+1,f+n);
	}
	cout<<aws<<'\n';
	return 0;
}
