#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
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
int a[1000001],w[1000001],C[2005][2005],len,v[1000001],n,m,k,logs[1000001],p[105][105];
int ans=0;
int c(int n,int m)
{
	if(n<0||m<0||n<m)return 0;
	return C[n][m];
}
int pw(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a;a%=mod;
		b>>=1;
	}
	return ans;
}
void dfs(int now,int nowlen)
{
	if(nowlen==n)
	{
//		for(int i=0;i<=m;i++)cout<<a[i]<<' ';
//		cout<<endl;
		int sum=1,tmp=n;
		for(int i=0;i<=m;i++)
		{
			if(a[i]>0)
			{
				sum*=p[i][a[i]];sum%=mod;
				sum*=c(tmp,a[i]);sum%=mod;
				tmp-=a[i];
			}
		}
		ans+=sum;
		ans%=mod;
	}
	if(nowlen>=n)return;
	if(now==0)return;
	for(int i=0;i<=a[now]&&nowlen+i<=n;i++)
	{
		a[now]-=i;
		a[now-1]+=2*i;
		dfs(now-1,nowlen+i);
		a[now]+=i;
		a[now-1]-=2*i;
	}
}
void check()
{
//	cout<<"check:\n";
//	for(int i=len;i>=0;i--)cout<<w[i]<<' ';
//	cout<<endl; 
	for(int i=0;i<=len;i++)a[i]=w[i];
	
	for(int i=len;i>m;i--)
	{
		a[i-1]+=a[i]*2;
		a[i]=0;
		if(a[i-1]>n)return;
	}
	int nowlen=0;
	for(int i=0;i<=m;i++)nowlen+=a[i];
	if(nowlen>n)return;
	dfs(m,nowlen);
}
void bs(int now,int lim)
{
	if(now>lim+1)return;
	if(now==0)
	{
		check();
		return;
	}
	for(int i=lim;i>=0;i--)
	{
		w[i]=1;
		bs(now-1,i-1);
		w[i]=0;
	}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=2;i<=1000;i++)
	logs[i]=logs[i/2]+1;
	C[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(j)C[i][j]=C[i-1][j-1]+C[i-1][j];
			else C[i][j]=1;
			C[i][j]%=mod;
		}
	}
	n=r();m=r();k=r();
	len=m+logs[n];
//	cout<<len<<endl;
	for(int i=0;i<=m;i++)v[i]=r(),p[i][1]=v[i];
	for(int i=0;i<=m;i++)
	for(int j=2;j<=50;j++)p[i][j]=p[i][j-1]*p[i][1]%mod;
	for(int i=0;i<=k;i++)
	bs(i,len);
	cout<<ans;
}
