#include<bits/stdc++.h>
using namespace std;
int v[105];
int b[105];
int n,m,l;
long long int ans;
int d;
bool add()
{
	int maxn=0;
	for(int i=0;i<=m;i++)
	{
		if(b[i]==0)
		{
			continue;
		}
		for(int j=b[i];j>0;j--)
		{
			maxn+=pow(2,i);
		}
	}
	int idx=0;
	while(maxn!=0)
	{
		if(maxn%2==1)
		{
			idx++;
		}
		maxn/=2;
	}
	if(idx<=l)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int maxs(int k)
{
	if(k==-1)
	{
		return 1;
	}
	for(int i=0;i<=m;i++)
	{
		if(b[i]!=0)
		{
			b[i]--;
			d+=maxs(k-1);
			b[i]++;
		}
	}
}
void find(int k,int total)
{
	if(k==m)
	{
		b[k]=total;
		if(add())
		{
			int idx=0;
			for(int i=0;i<=m;i++)
			{
				idx+=pow(v[i],b[i]);
			}
			d=0;
			maxs(m);
			ans+=idx*d;
			ans%=998244353;
		}
		return;
	}
	for(int i=0;i<=total;i++)
	{
		b[k]=i;
		find(k+1,total-i);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    cin>>n>>m>>l;
    for(int i=0;i<=m;i++)
    {
    	cin>>v[i];
	}
	find(0,m);
	cout<<ans*4;
	return 0;
}
