#include<bits/stdc++.h>
using namespace std;
int ans=1e9;
inline int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
int n,a[10005];
bool pd[11][11];
void dfs()
{
//	for(int i=1;i<=n;++i)
//	cout<<a[i]<<" ";
//	cout<<endl;
	int cheng=0,he=0;
	for(int i=1;i<=n;++i)
	{
		cheng+=a[i]*a[i];
		he+=a[i];
	}
	ans=min(ans,n*cheng-he*he);
	int a2=a[2],a3=a[3];
	if(!pd[a[1]+a3-a2][a3])
	{
		pd[a[1]+a3-a2][a[3]]=1;
		a[2]=a[1]+a3-a2;
		dfs();
	}
	if(!pd[a2][a2+a[4]-a3])
	{
		pd[a2][a2+a[4]-a3]=1;
		a[3]=a2+a[4]-a3;
		dfs();
	}
	return;
}
void dfs10()
{
	for(int i=1;i<=n;++i)
	cout<<a[i]<<" ";
	cout<<endl;
	int cheng=0,he=0;
	for(int i=1;i<=n;++i)
	{
		cheng+=a[i]*a[i];
		he+=a[i];
	}
	ans=min(ans,n*cheng-he*he);
	int ti[12];
	for(int i=1;i<=n;++i)
	ti[i]=a[i];
	for(int i=2;i<=n-1;++i)
	{
		a[i]=ti[i+1]+ti[i-1]-ti[i];
		dfs10();
	}
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	a[i]=read();
	if(n==2)
	printf("%d",2*(a[1]*a[1]+a[2]*a[2])-(a[1]+a[2])*(a[1]+a[2]));
	else if(n==3)
	{
		ans=min(3*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]),
		3*(a[1]*a[1]+(a[1]+a[3]-a[2])*(a[1]+a[3]-a[2])+a[3]*a[3])-(a[1]+(a[1]+a[3]-a[2])+a[3])*(a[1]+(a[1]+a[3]-a[2])+a[3]));
		printf("%d",ans);
	}
	else if(n==4)
	{
		pd[a[2]][a[3]]=1;
		dfs();
		printf("%d",ans);
	}
	else if(n==10)
	{
		dfs10();
		printf("%d",ans);
	}
	else
	{	
		long long cheng=0,he=0;
	    for(int i=1;i<=n;++i)
	    {
		    cheng+=a[i]*a[i];
		    he+=a[i];
	    }
	    printf("%lld",n*cheng-he*he);
	}
	return 0;
}
