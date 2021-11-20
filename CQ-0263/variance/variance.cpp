#include<bits/stdc++.h>
using namespace std;
int n,a[105],ans,b[105],ssum;
bool vis[45678];
int getnum(int *a)
{
	int bs=1,res=0;
	for(int i=4;i>=1;i--)
	res+=a[i]*bs,bs*=10;
	return res;
}
void dfs()
{
	int res=0;
	int xx=getnum(a);
	//cout<<"xx:"<<xx<<endl;
	vis[xx]=1;
	for(int i=2;i<=3;i++)
	{
		for(int j=1;j<=4;j++) b[j]=a[j];
		b[i]=b[i-1]+b[i+1]-b[i];
		
		if(vis[getnum(b)]) continue;
		int sum=0;//cout<<"xx:"<<getnum(b)<<endl;
		for(int j=1;j<=n;j++) sum+=b[j];
		for(int j=1;j<=n;j++)
		res+=(n*b[j]-2*sum)*b[j];
		res+=(sum*sum);//cout<<"res:"<<res<<endl;
		ans=min(ans,res);
		for(int j=1;j<=n;j++) a[j]=b[j];
		dfs();
	}
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int j=1;j<=n;j++) ssum+=a[j];
	for(int j=1;j<=n;j++)
	ans+=(n*a[j]-2*ssum)*a[j];
	ans+=(ssum*ssum);
	dfs();
	printf("%d",ans);
	return 0;
}
