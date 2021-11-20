#include<bits/stdc++.h>
using namespace std;
const int N=40,M=110,mod=998244353;
typedef long long LL;
int n,m,k;
int v[M],a[N],c[M][M];
int ans;
void init()
{
	for(int i=0;i<=M;i++)
		for(int j=0;j<=i;j++)
		{
			if(j == 0) c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
}
LL lowbit(LL x)
{
	return x&-x;
}
bool check()
{
	LL S=0;
	for(int i=1;i<=n;i++)
		S=S+(1<<a[i]);
	int cnt=0;
	while(S)
	{
		cnt++;
		S-=lowbit(S);
	}
	return cnt<=k;
}
void dfs(int u,int s,int sum)
{
	if(u == n+1)
	{
		if(check())
		{
			int cnt=0,res=1;
			for(int i=1;i<=n;i++)
			{
				int j=i+1;
				while(j<=n&&a[j]==a[i])
					j++;
				j--;
				res=(LL)res*c[n-cnt][j-i+1]%mod;
				cnt+=j-i+1;
				i=j;
			}
			ans=(ans+(LL)res*sum%mod)%mod;
		}
		return;
	}
	for(int i=s;i<=m;i++)
		a[u]=i,dfs(u+1,i,(LL)sum*v[i]%mod);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	init();
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		scanf("%d",&v[i]);
	dfs(1,0,1);
	cout<<ans<<endl;
	
	return 0;
}
