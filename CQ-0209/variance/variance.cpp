#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<stack>
#include<algorithm>
//!BN PION
using namespace std;
int a[10005];
int b[10005];
struct node
{
	int pos,v;
	bool operator < (const node &T) const
	{
		return T.v>v;
	}
}lower[10005];
int sum[10005];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int rp=0x7fffffff; 
	int n;
	scanf("%d",&n);
	double cnt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		if(i>1)
		{
			lower[i-1].v=a[i]-a[i-1];
			lower[i-1].pos=i-1;
		}
	}
	sort(lower+1,lower+n);
	int l=n/2,r=n/2+1,i=1;
	if(n%2==0) b[l--]=lower[i++].v;
	while(i<n)
	{
		if(l & 1)//Ìý Ìì ÓÉ Ãü 
		{
			if(r<n) b[r++]=lower[i++].v;
			if(l>=1) b[l--]=lower[i++].v;
		}
		else
		{
			if(l>=1) b[l--]=lower[i++].v;
			if(r<n) b[r++]=lower[i++].v;
		}
		
	}
	//for(int i=1;i<n;i++) printf("%d ",b[i]);
	//puts("");
	for(int i=2;i<=n;i++) a[i]=b[i-1]+a[i-1];
	int ans=0,anss=0;
	//for(int i=1;i<=n;i++) printf("%d ",a[i]);
	for(int i=1;i<=n;i++) ans+=a[i];
	for(int i=1;i<=n;i++) 
	{
		anss+=n*a[i]*a[i]-2*ans*a[i]+ans*ans/n;
	}
	printf("%d",anss);
}
