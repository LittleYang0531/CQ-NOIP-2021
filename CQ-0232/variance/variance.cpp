#include<bits/stdc++.h>
using namespace std;
const double down=0.996;
int n,k=100;
long long sum=0;
int temp[10007],a[10007];
double tmp,ans;
void d()
{
	sum=0;
	double k=0;
	for(int i=1;i<=n;i++)	sum+=temp[i];
	tmp=(double)sum/n;
	for(int i=1;i<=n;i++)	k=k+(double)(temp[i]-tmp)*(temp[i]-tmp)*n;
	ans=min(ans,k);
}
double check()
{
	long long h=0;
	for(int i=1;i<=n;i++) h+=a[i]; 
	double site=(double)h/n,s=0;
	for(int i=1;i<=n;i++)
	{
		s=s+(double)(a[i]-site)*(a[i]-site)*n;
	}
	return s;
}

void fire()
{
	double t=100;
	while(t>=1e-8)
	{
		t=t*down;
		int x=rand()%(n-2)+2;
		int tot=a[x];
		a[x]=a[x+1]+a[x-1]-tot;
		if(a[x]==tot) continue;
		double nowans=check();
		if(nowans<ans) ans=nowans;
		else if(exp((ans-nowans)/t)<(double)rand()/RAND_MAX) a[x]=tot;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);		
		sum+=a[i];
	}
	tmp=(double)sum/n;
	for(int i=1;i<=n;i++)	ans=ans+(double)(a[i]-tmp)*(a[i]-tmp)*n;
	if(n<3)
	{
		printf("%lld",(long long)ans);
		return 0;
	}
	else if(n==3)
	{
		temp[1]=a[1],temp[3]=a[3],temp[2]=a[1]+a[3]-a[2];
		d();
		printf("%lld",(long long)ans);
		return 0;
	}
	else if(n==4)
	{
		temp[1]=a[1],temp[2]=a[1]+a[3]-a[2],temp[3]=a[3],temp[4]=a[4];
		d();
		temp[1]=a[1],temp[2]=a[2],temp[3]=a[2]+a[4]-a[3],temp[4]=a[4];
		d();
		temp[1]=a[1],temp[2]=a[1]+a[3]-a[2],temp[3]=a[1]-a[2]+a[4],temp[4]=a[4];
		d();
		printf("%lld",(long long)ans);
		return 0;
	}
	while(k--)	fire();
	printf("%lld",(long long)ans);
	return 0;
}
