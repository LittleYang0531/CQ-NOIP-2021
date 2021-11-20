#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 1e4+10,mod = 21348,base = 131;
int n,p,su,ans;
int a[MAX];
bool vis[mod];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int hs()
{
	int l = 0;
	for(int i = 1;i<=n;i++) 
	{
		l = (l*base+a[i])%mod;
	}
	return l;
}
void dfs()
{
	for(int i = 2;i<n;i++)
	{
		if(a[i]!=a[i+1]+a[i-1]-a[i])
		{
			int l = p,r = a[i],lr = su,ls;
			a[i] = a[i+1]+a[i-1]-a[i],p = p-r*r+a[i]*a[i],su = su-r+a[i];
			ls = hs();
			if(!vis[ls])
			{
				vis[ls] = 1;
				ans = min(ans,p*n-su*su);
//				for(int i = 1;i<=n;i++) cout<<a[i]<<" ";
//				cout<<p<<" "<<su<<endl;
				dfs();
//				cout<<"!";
			}
			p = l,a[i] = r,su = lr;
		}
	}
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n = read();
	for(int i = 1;i<=n;i++) a[i] = read(),p+=a[i]*a[i],su+=a[i];
	ans = p*n-su*su;
	dfs();
	printf("%lld",ans);
	return 0;
}
