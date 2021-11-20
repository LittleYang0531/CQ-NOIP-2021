#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
ll e[1000001],f[1000001],g[1000001],lg,h[1000001],lh,t,tt;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ll n;
	scanf("%lld%lld",&n,e);
	for(ll i=1ll;i<n;i++)
		scanf("%lld",e+i),f[i-1]=e[i]-e[i-1];
	sort(f,f+n-1),reverse(f,f+n-1),t=(e[0]+e[n-1])/2ll,tt=e[0];
	for(ll i=0ll;i*2ll<n-2ll;i++)
		if(f[i<<1]==f[i<<1|1])
			f[i<<1|1]^=f[(i+1)<<1]^=f[i<<1|1]^=f[(i+1)<<1];
	for(ll i=0ll;i*2ll<n-2ll;i++)
		if(tt+f[i<<1]<=t)
			tt+=f[i<<1],g[lg++]=f[i<<1],h[lh++]=f[i<<1|1];
		else if(tt+f[i<<1|1]<=t)
			tt+=f[i<<1|1],h[lh++]=f[i<<1],g[lg++]=f[i<<1|1];
		else
			h[lh++]=f[i<<1],h[lh++]=f[i<<1|1];
	if((n-1ll)&1ll)
		if(tt+f[n-2]<=t)
			tt+=f[n-2],g[lg++]=f[n-2];
		else
			h[lh++]=f[n-2];
	sort(g,g+lg),sort(h,h+lh);
	for(ll i=0ll;i<lg;i++)
		e[i+1]=e[i]+g[lg-1-i];
	for(ll i=lg;i<lg+lh;i++)
		e[i+1]=e[i]+h[i-lg];
	t=tt=0ll;
	for(ll i=0ll;i<n;i++)
		t+=e[i],tt+=n*e[i]*e[i];
	printf("%lld",tt-t*t);
	return 0;
}
