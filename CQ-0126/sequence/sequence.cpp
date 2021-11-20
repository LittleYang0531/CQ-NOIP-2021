#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[105],an[50],minn,ans;
unsigned long long maxx;
int check(unsigned long long x)
{
	int sum=0;
	while(x>0)
	{
		unsigned long long y=x%2;
		if(y==1) sum++;
		x/=2;
	}
	if(sum<=k) return 1;
	else return 0;
}
void dfs(int a,int cnt)
{
	if(cnt==n){
		int t=0;
		for(int i=0;i<n;i++)
			t+=pow(2,an[i]);
		if(t==a&&check(t)){
			int ans1=1;
			for(int i=0;i<n;i++)
				ans1*=(v[an[i]]%998244353);
			ans=(ans+ans1)%998244353;
			return;
		}
		return;
	}
	for(int i=0;i<=m;i++)
	{
		an[cnt]=i;
		dfs(a,cnt+1);
	}
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>v[i];
	if(m<=50)
	{
		minn=n;
		maxx=n*pow(2,m);
		for(int i=minn;i<=maxx;i++)
		{
			dfs(i,0);
		}
	}
	cout<<ans;
	return 0;
}
