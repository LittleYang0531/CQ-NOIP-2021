#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6;
const int N=110;
const int mod=998244353;
int n,m,K,cnt,cntb,cntc,ans;
int cm[N],v[N],a[N],b[M][N],d[N],c[N],jc[N];

bool check(int x)
{
	int sum=0;
	while(x!=0)
	{
		int y=x&1;
		if(y==1) sum++;
		x>>=1;
	}
	if(sum>K) return false;
	else true;
}

int finallyucanknowccf(int x)
{
	for(int i=0;i<=32;i++)
	{
		if(cm[i]==x)
			return i;
	}
}

bool check1(int j)
{
	for(int i=1;i<=cnt;i++)
	{
		int ab=finallyucanknowccf(d[i]);
		if(ab!=b[j][i]) return false;
	}
	return true;
}

void dfs(int k)
{
	if(k==n)
	{
		int f=1,sum=1;
		for(int i=1;i<=cnt;i++)
		{
			int ab=finallyucanknowccf(a[i]);
			if(ab>m)
			{
				f=0;
				break;
			}
			sum=(sum*(v[ab]%mod))%mod;
		}
		if(f==1)
		{
			for(int i=1;i<=cnt;i++)
				d[i]=a[i];
			sort(d+1,d+1+cnt);
			int ff=1;
			for(int i=1;i<=cntb;i++)
			{
				if(check1(i))
				{
					ff=0;
					break;
				}
			}
			if(ff==1)
			{
				memset(c,0,sizeof(c));
				for(int i=1;i<=cnt;i++)
				{
					int ab=finallyucanknowccf(d[i]);
					c[ab]++;
				}
				int gs=1;
				for(int i=0;i<=32;i++)
				{
					if(c[i]!=0)
					{
						gs=gs*jc[c[i]];
					}
				}
				int ggs=jc[cnt]/gs;
				ans=(ans+(ggs*sum)%mod)%mod;
				cntb++;
				for(int i=1;i<=cnt;i++)
				{
					int ab=finallyucanknowccf(d[i]);
					b[cntb][i]=ab;
				}
			}
		}
		return ;
	}
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]<=1) continue;
		a[i]/=2; a[++cnt]=a[i];
		dfs(k+1);
		a[i]*=2; cnt--;
	}
}

signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cm[0]=1;
	for(int i=1;i<=N;i++)
		cm[i]=cm[i-1]*2%mod;
	jc[0]=1;
	for(int i=1;i<=N;i++)
		jc[i]=jc[i-1]*i%mod;
	scanf("%lld %lld %lld",&n,&m,&K);
	for(int i=0;i<=m;i++)
	{
		scanf("%lld",&v[i]);
		v[i]%=mod;
	}
	int mins=n,maxs=n*(1<<m);
	for(int i=mins;i<=maxs;i++)
	{
		if(check(i))
		{
			int x=i,j=0;
			memset(a,0,sizeof(a));
			cnt=0;
			while(x!=0)
			{
				if(x>=cm[j] && x<cm[j+1])
				{
					x-=cm[j];
					a[++cnt]=cm[j];
					j=0;
				}
				else j++;
			}
			dfs(cnt);
		}
	}
	printf("%lld",ans%mod);
	return 0;
}
