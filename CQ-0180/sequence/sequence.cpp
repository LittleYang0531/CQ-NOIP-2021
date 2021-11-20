#include<bits/stdc++.h>
using namespace std;
int n,m,k,choose[105],u,t;
long long x[105],mo=998244353,ans,tot;
int pd(int x)
{
	int ans=0;
	while(x>0)
	{
		if(x%2==1) ans++;
		x/=2;
	}
	return ans;
}
void search(int h,int tar,int tot)
{
	if(u==1) return;
	if(tot>tar) return;
	if(h>n)
	{
		if(tot==tar) u=1;
		return;
	}
	for(int a=0;a<=m;a++)
	{
		choose[a]++;
		search(h+1,tar,tot+int(pow(2,a)));
		if(u==1) return;
		choose[a]--;
	}
}
long long ksm(long long a,int b)
{
	long long ans=1;
	while(b>0)
	{
		if(a%2==1) a=a*a%mo;
		ans=ans*a%mo;
		b/=2;
	}
	return ans;
}
long long C(long long a,int b)
{
	long long ans=1;
	for(long long c=b+1;c<=a;c++) ans=ans*c;
	for(long long c=1;c<=a-b;c++) ans=ans/c;
	return ans;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int a=0;a<=m;a++) scanf("%lld",&x[a]);
	int n2=n+int(pow(2,m+1));
	for(int a=n;a<=n2;a++)
	{
		if(pd(a)<=k)
		{
			memset(choose,0,sizeof(choose));
			u=0,t=n,tot=0;
			long long q=1;
			search(1,a,0);
			for(int a=0;a<=m;a++)
			{
				if(C(t,choose[a])!=1) tot=(tot+C(t,choose[a]))%mo;
				q=(q*ksm(x[a],choose[a]))%mo;
				t-=choose[a];
			}
			ans=(ans+tot*q)%mo;
		}
	}
	printf("%lld",ans);
	return 0;
}
