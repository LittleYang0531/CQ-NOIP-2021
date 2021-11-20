#include<bits/stdc++.h>
using namespace std;
int n,a[400],num=1,ans=INT_MAX;
struct asd
{
	int q[55];
}b[100000];

int judge(int x)
{
	for(int i=1;i<num;i++)
	{
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			if(b[i].q[j]!=b[x].q[j]) {flag=1;break;}
		} 
		if(flag==0) return 1;
	}
	return 0;
}

void fang(int x)
{
	double pp=0,f;
	for(int i=1;i<=n;i++) pp+=b[x].q[i];
	pp/=n;
	
	for(int i=1;i<=n;i++)
	{
		f+=n*pow(b[x].q[i]-pp,2);
	}
	
	ans=min(ans,int(f));
}

void dfs(int x,int m)
{
	
	for(int i=2;i<n;i++)
	{
		if(i==x) continue;
		for(int j=1;j<=n;j++)
		{
			if(j==i)
			{
				b[num].q[i]=b[m].q[i-1]+b[m].q[i+1]-b[m].q[i];
			}
			else b[num].q[j]=b[m].q[j];
		}
		
		if(judge(num)==1)
		{
			continue;
		}
		num++;
		fang(num-1);
		dfs(i,num-1);
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[num].q[i]=a[i];
	}
	
	num++;
	fang(1);
	dfs(0,1);
	
	
	cout<<ans;
	return 0;
}


