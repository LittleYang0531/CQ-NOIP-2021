#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char c;
	do
		c=getchar();
	while(c<'0'||'9'<c);
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x;
}
const int O=105,N=12300,L=35,M=998244353;
int v[O],d[N][L],c[L],y[L];
int ksm(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1)
			c=1ll*c*a%M;
		a=1ll*a*a%M;
		b>>=1;
	}
	return c;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n=read(),m=read(),k=read(),s,a=0;
	for(int i=0;i<=m;i++)
		v[i]=read();
	c[0]=1;
	for(int i=0;i<n;i++)
		c[i+1]=1ll*c[i]*(i+1)%M;
	y[n]=ksm(c[n],M-2);
	for(int i=n;i;i--)
		y[i-1]=1ll*y[i]*i%M;
	d[0][0]=1;
	for(int i=0;i<=m;i++)
		for(int j=(1<<m)*n;j;j--)
			for(int k=(j+(1<<m)-1)/(1<<m);k<=j&&k<=n;k++)
				for(int l=1;(1<<i)*l<=j&&l<=k;l++)
					d[j][k]=(d[j][k]+1ll*d[j-(1<<i)*l][k-l]*
					ksm(v[i],l)%M*y[l])%M;
	for(int i=n;i<=(1<<m)*n;i++)
	{
		s=0;
		for(int j=0;j<17;j++)
			if(i>>j&1)
				s++;
		if(s<=k)
			a=(a+d[i][n])%M;
	}
	printf("%lld",1ll*a*c[n]%M);
}
