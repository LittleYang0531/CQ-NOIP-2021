#include<bits/stdc++.h>
using namespace std;
int n;
double a[10005];
double ans=1e8;
void dfs(int x,double sum)
{
	if(x>n)
	{
		double tot=0;
		for(int i=1;i<=n;++i)
		{
			tot+=(a[i]-sum/(n*1.0))*(a[i]-sum/(n*1.0));
		}
		ans=min(ans,tot*(n*1.0));
		return;
	}
	int p=a[x];
	if(x==1||x==n)
	{
		dfs(x+1,sum+a[x]);
	}
	else
	{
		a[x]=a[x-1]+a[x+1]-a[x];
		dfs(x+1,sum+a[x]);
		a[x]=p;
		dfs(x+1,sum+a[x]);
	}
}
int main()
{
	freopen("variance.in","r",stdin);		
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	dfs(1,0);
	printf("%d",int(ans));
	return 0;
}
/*
 cc   cc  fffff  y   y  y   y  dd      ss
c    c    f       y y    y y   d d    s  s
c    c    fffff    y      y    d d     s
c    c    f        y      y    d d   s  s
 cc   cc  f        y      y    dd     ss
*/
