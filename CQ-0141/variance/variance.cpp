#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[10005];
ll ansz=0x3fffffff,ansm,sz,sm;
ll gcd(ll m,ll n)
{
	if(n==0) return m;
	return gcd(n,m%n);
}
void zfc(int b[10005],int c,int d,int bo)
{
	if(d>n-1) return;
	ll pjm=1,pjz=0;
	sz=0,sm=1;
	for(int i=1;i<=n;i++)
	{	
//		cout<<b[i]<<" "; 
		pjz+=b[i];
	}
//	cout<<endl;
	pjm=n;
	ll sum=gcd(pjz,pjm);
	pjz/=sum;
	pjm/=sum;
	//cout<<pjz<<"/"<<pjm<<endl; 
	sm=pjm*pjm;
	for(int i=1;i<=n;i++)
	{
		ll bz=pjm*b[i],bm=pjm*pjm;
		sz+=(bz-pjz)*(bz-pjz);
		
	}
	sm*=4;
	sum=gcd(sz,sm);
	sz/=sum;
	sm/=sum;
	//cout<<sz<<"/"<<sm; 
	sum=ansm/gcd(sm,ansm);
	if(sum*sz<ansz)	ansz=sum*sz;
	if(bo)
	{
		for(int i=c;i<=n-1;i++)
		{
			zfc(b,i+1,d+1,1);
		}
		for(int i=c;i<=n-1;i++)
		{
			b[d]=b[d-1]+b[d+1]-b[d];
			zfc(b,i+1,d+1,1);
		}
	}
	else
	{
		for(int i=c;i<=n-1;i++)
		{
			b[d]=b[d-1]+b[d+1]-b[d];
			zfc(b,i+1,d+1,0);
		}
		for(int i=c;i<=n-1;i++)
		{
			zfc(b,i+1,d+1,0);
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	ansm=pow(n,2);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	zfc(a,2,2,1);
	zfc(a,2,2,0);
	cout<<ansz;
	return 0;
}
