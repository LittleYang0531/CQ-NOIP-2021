#include<bits/stdc++.h>
using namespace std;
int n,a[102][20000],top,mda,p[10000],f[10000];
int r()
{
	register int q=0,w=1;register char e=getchar();
	while(e<'0'||e>'9'){if(e=='-')w=-1;e=getchar();}
	while(e>='0'&&e<='9')q=(q<<3)+(q<<1)+e-'0',e=getchar();
	return q*w;
}
void dfs()
{
	top++;
	for(int i=0;i<n;i++)a[i][top]=a[i][top-1],p[top]+=a[i][top];
	for(int i=1;i<n-1;i++)
	{
		bool t=0;
		p[top]-=a[i][top];
		a[i][top]=a[i-1][top]+a[i+1][top]-a[i][top];
		p[top]+=a[i][top];
		for(int j=0;j<top;j++)
		{
			t=1;
			for(int l=0;l<n;l++)if(a[l][j]!=a[l][top])t=0;
			if(t)break;
		}
		if(!t)
		{
			for(int j=0;j<n;j++)f[top]+=pow(a[j][top]*n-p[top],2);
			f[top]/=n;
			mda=min(mda,f[top]);
			dfs();
		}
		p[top]-=a[i][top];
		a[i][top]=a[i-1][top]+a[i+1][top]-a[i][top];
		p[top]+=a[i][top];
	}
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=r();
	for(int i=0;i<n;i++)a[i][top]=r(),p[top]+=a[i][top];
	for(int j=0;j<n;j++)f[top]+=pow(a[j][top]*n-p[top],2);
	f[top]/=n;
	mda=f[top];
	dfs();
	printf("%d",mda);
	return 0;
}
