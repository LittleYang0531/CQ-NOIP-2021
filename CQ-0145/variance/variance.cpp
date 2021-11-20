#include<bits/stdc++.h>
using namespace std;
int a[240000];
int n;
int pan[605];
int hand,end;
int b[405];
int c[405];
int d[10000][405];
int fill()
{
	for(int i=1;i<=n;i++)
	{
		d[end%10000][i]=c[i];
	}
	return 0;
}
int e[405];
int D()
{
	int total=0;
	for(int i=1;i<=n;i++)
	{
		total+=c[i];
		e[i]=c[i]*n;
	}
	int totalb=0;
	for(int i=1;i<=n;i++)
	{
		totalb+=pow(e[i]-total,2);
	}
	return totalb/n;
}
int check()
{
	int total=0;
	for(int i=1;i<n;i++)
	{
		if(c[i]==c[i+1])
		{
			total++;
		}
	}
	if(c[n]==c[n-1])
	{
		total++;
	}
	return total;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	int minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		c[i]=b[i];		
	}
	end++;
	fill();
	minn=min(minn,D());
	a[D()]++;
	pan[check()]++;
	hand++;
	while(hand<=end)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=d[hand%10000][i];
		}
		for(int i=2;i<n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					c[j]=b[j];
				}
				else
				{
					c[j]=b[j+1]+b[j-1]-b[j];
				}
			}
			if(!(a[D()]!=0&&pan[check()]!=0))
			{
				end++;
				fill();
				minn=min(minn,D());
				a[D()]++;
				pan[check()]++;
			}
		}
		hand++;
	}
	cout<<minn;
	return 0;
}
