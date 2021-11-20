#include <cstdio>
const int M = 35;
const int N = 155;
const int MOD = 998244353;
#define ll long long
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
ll n,m,k,ans,C[M][M],a[N],f[M][M][M],g[M][M][M];
void add(ll &x,ll y) {x=(x+y)%MOD;}
void init(ll n)
{
	for(ll i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(ll j=1;j<=i;j++)
			add(C[i][j],C[i-1][j-1]+C[i-1][j]);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();init(n);
	for(ll i=1;i<=m+1;i++) a[i]=read();
	f[0][0][0]=1;m+=10;
	for(ll i=1;i<=m;i++)
	{
		//copy and clear
		for(ll j=0;j<=k;j++)
		for(ll u=0;u<=n;u++)
		for(ll v=0;v<=n;v++)
			g[j][u][v]=f[j][u][v],f[j][u][v]=0;
		//dp
		for(ll j=0;j<=k;j++)
		for(ll u=0;u<=n;u++)
		for(ll v=0;v<=n;v++)
		for(ll x=0,y=1;x<=n-u;x++,y=y*a[i]%MOD)
		{
			add(f[j+((v+x)%2)][u+x][(v+x)/2]
			,g[j][u][v]*C[n-u][x]%MOD*y%MOD);
		}
	}
	for(ll i=0;i<=k;i++)
		add(ans,f[i][n][0]);
	printf("%lld\n",ans);
	return 0;
}
