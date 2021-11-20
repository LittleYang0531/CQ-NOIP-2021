#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 1e2+10,mod = 998244353;
int n,m,k,ans;
int v[MAX],s[MAX],a[MAX],b[MAX],ny[MAX];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int f(int x,int y)
{
	int l = 1;
	for(int i = 1;i<=y;i++)
	{
		l = (l*(x-i+1)/i)%mod;
	}
	return l;
}
int sol()
{
	int l = 1,r = n;
	for(int i = 0;i<=m;i++)
	{
		l = (l*b[r]%mod*ny[r-s[i]]%mod*ny[s[i]])%mod,r -= s[i];
	}
	return l;
}
int q_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int l = q_pow(x,y>>1);
	l = (l*l)%mod;
	if(y&1) return l*x%mod;
	return l;
}
void dfs(int x,int y,int vl)
{
	if(x==m)
	{
		s[x] = y,vl = (vl*q_pow(v[x],y))%mod;
//		cout<<vl<<endl;
//		cin>>x;
//		if(y!=0) return;
		int l=0;
		for(int i = 0;i<=m;i++) a[i] = s[i];
		for(int i = 0;i<=m;i++) 
			a[i+1]+=a[i]>>1,a[i]&=1,l+=a[i],a[i]=0;
		for(int i = m+1;a[i];i++) 
			a[i+1]+=a[i]>>1,a[i]&=1,l+=a[i],a[i]=0;
		if(l<=k) 
		{
//			for(int i = 0;i<=m;i++) cout<<s[i]<<" "; 
//			cout<<sol()<<" "<<endl;
//			cin>>x;
			if(sol()==0) cout<<sol()<<endl;
			ans = (ans+vl)%mod;
		}
		return;
	}
	for(int i = 0;i<=y;i++)
	{
		s[x] = i;
		dfs(x+1,y-i,(vl*q_pow(v[x],i)%mod)*(b[y]%mod*ny[y-i]%mod*ny[i]%mod)%mod);
	}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 0;i<=m;i++) v[i] = read();
	b[0]=ny[0]=1;
	for(int i = 1;i<=n;i++) b[i]=(b[i-1]*i)%mod,ny[i]=q_pow(b[i],mod-2);
	dfs(0,n,1);
	printf("%lld",ans);
	return 0;
}
