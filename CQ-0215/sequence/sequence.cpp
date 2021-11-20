#include<bits/stdc++.h>
using namespace std;
const int N=110;
const long long p=998244353;
int n,m,k;
long long v[N],ans;
bool check(long x)
{
	int cnt=0;
	while(x)
	{
		if(x%2==1)cnt++;
		x/=2;
	}
	return cnt<=k;
}
void dfs(long long x,int d,long long z)
{
	if(x<0)return;
	if(d==0)
	{
		if(x==0)
			ans=(ans+z)%p;
		return;
	}
	for(long long i=0;i<=m;i++)
		dfs(x-(1<<i),d-1,z*v[i]%p);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>v[i];
	for(long long i=n;i<=n*(2<<(m-1));i++)
	if(check(i))
	{
//		cout<<i<<" ";
		dfs(i,n,1);
	}
	cout<<ans;
	return 0;
}

