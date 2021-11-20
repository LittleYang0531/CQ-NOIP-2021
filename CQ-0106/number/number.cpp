#include<bits/stdc++.h>
using namespace std;

const int MAXN= 10005;
const int MAXN1=1000005;
int T;
int a[MAXN1];
int fa[MAXN1];
int cnt[MAXN1];
int vis[MAXN1];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	memset(fa,0,sizeof fa);
	memset(vis,0,sizeof vis);
	cin>>T;
	for(int i=1;i<=MAXN;i++)
	{
		int x=i;
		while(x)
		{
			if(x%10==7)
			{
				vis[i]=1;
				fa[i]=i;
				cnt[i]=2;
			}
			x/=10;
		}
	}
	for(int i=1;i<=MAXN;i++)
	{
		if(vis[i]==1)
		{
			int k=fa[i]*cnt[fa[i]];
			vis[k]=1;
			fa[fa[i]*cnt[fa[i]]]=fa[i];
			cnt[fa[i]]++;
		}
	}
	for(int i=1;i<=MAXN;i++)
	{
		if(vis[i]!=1)
		{
			for(int j=i+1;j<=MAXN;j++)
			{
				if(vis[j]!=1)
				{
					a[i]=j;
					break;
				}
			}
		}
	}
	for(int i=1;i<=T;i++)
	{
		int x;
		cin>>x;
		if(vis[x]==1)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<a[x]<<endl;
		}
	}
	return 0;
}
