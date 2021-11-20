#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=1;
int v[105];
int zh(int x)
{
	int sum=0;
	while(x>=2)
	{
		sum+=x%2;
		x/=2;
	}
	sum+=x;
	return sum;
}
void dfs(int x)
{
	if(x==0) return;
	for(int k=1;k<=n;k++)
	{
		for(int i=0;i<=m;i++)
		{
			x-=pow(2,i);
			ans*=v[i];
			dfs(x);
			x+=pow(2,i);
			ans/=v[i];
		}
	}

}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) cin>>v[i];
	for(int i=n;i<=n*pow(2,m);i++)
	{
		if(zh(i)<=k)
		{
			dfs(i);
		}
	}
	cout<<ans;
	return 0;
}
