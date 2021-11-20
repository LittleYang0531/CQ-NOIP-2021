#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,a[10009],b[10009];
bool vis[10009];
double ans;
double js()
{
	double pj=0,fc=0;
	for(int i=1;i<=n;i++) pj+=1.0*b[i];
	pj/=n;
	for(int i=1;i<=n;i++) fc+=1.0*(b[i]-pj)*(b[i]-pj);
	fc/=n;
	return fc;
}
void dfs(int x)
{
	ans=min(ans,js());	
	for(int i=2;i<n;i++)
	{
		if(!vis[i]&&i!=x)
		{
			vis[i]=1;
			b[i]=b[i+1]+b[i-1]-b[i];
			dfs(i);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	memcpy(b,a,sizeof b);
	ans=js();
	for(int i=1;i<=n;i++) 
	{
		memset(vis,0,sizeof vis);
		dfs(i);
	}
	printf("%.lf",ans*n*n);
	return 0;
}
