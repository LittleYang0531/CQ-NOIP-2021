#include<bits/stdc++.h>
using namespace std;
inline int r()
{
	int s=0,k=1;char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')k=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return s*k;
}
int n,a[1000001],cnt,p[1000001];
int cz[10000001],ans;
void get_ans(int x)
{
	for(int i=1;i<=n;i++)p[i]=a[i];
	for(int i=1;i<=x;i++)
	{
		int pos=cz[i];
		p[pos]=p[pos-1]+p[pos+1]-p[pos];
	}
//	for(int i=1;i<=n;i++)cout<<p[i]<<' ';
//	cout<<endl;
	int now=0,sum=0;
	for(int i=1;i<=n;i++)now+=p[i];
	sum=-now*now;
	for(int i=1;i<=n;i++)sum+=n*p[i]*p[i];
	ans=min(ans,sum);
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ans=2e9;
	srand(time(0));
	n=r();
	for(int i=1;i<=n;i++)a[i]=r();
	
	for(int i=2;i<n;i++)
	for(int j=1;j<=40*n;j++)
	cz[++cnt]=i;
	
	for(int i=1;i<=2000;i++)
	{
		random_shuffle(cz+1,cz+cnt+1);
		for(int j=1;j<=30;j++)
		{
			int tmp=rand()%(cnt-1)+1;
			get_ans(tmp);
		}
	}
	cout<<ans;
}
