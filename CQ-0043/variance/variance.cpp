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
const int N=1e4;
int a[N],b[N];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n=read(),s=0,h=0,t,g=0;
	bool w=1;
	for(int i=0;i<n;i++)
		b[i]=a[i]=read(),s+=a[i];
	t=s;
	while(w)
	{
		w=0;
		for(int i=0;i+3<n;i++)
			if(((s-a[i+1])<<1)<(a[i]+a[i+2])*(n-1)&&
			a[i]+a[i+2]<(a[i+1]<<1))
			{
				w=1;
				s-=a[i+1];
				a[i+1]=a[i]+a[i+2]-a[i+1];
				s+=a[i+1];
			}
	}
	w=1;
	while(w)
	{
		w=0;
		for(int i=0;i+3<n;i++)
			if(((s-a[i+1])<<1)>(a[i]+a[i+2])*(n-1)&&
			a[i]+a[i+2]>(a[i+1]<<1))
			{
				w=1;
				s-=a[i+1];
				a[i+1]=a[i]+a[i+2]-a[i+1];
				s+=a[i+1];
			}
	}
	w=1;
	while(w)
	{
		w=0;
		for(int i=0;i+3<n;i++)
			if(((s-b[i+1])<<1)>(b[i]+b[i+2])*(n-1)&&
			b[i]+b[i+2]>(b[i+1]<<1))
			{
				w=1;
				t-=b[i+1];
				b[i+1]=b[i]+b[i+2]-b[i+1];
				t+=b[i+1];
			}
	}
	w=1;
	while(w)
	{
		w=0;
		for(int i=0;i+3<n;i++)
			if(((s-b[i+1])<<1)<(b[i]+b[i+2])*(n-1)&&
			b[i]+b[i+2]<(b[i+1]<<1))
			{
				w=1;
				t-=b[i+1];
				b[i+1]=b[i]+b[i+2]-b[i+1];
				t+=b[i+1];
			}
	}
	for(int i=0;i<n;i++)
		h+=1ll*a[i]*a[i];
	for(int i=0;i<n;i++)
		g+=1ll*b[i]*b[i];
	printf("%lld",min(1ll*h*n-1ll*s*s,1ll*g*n-1ll*t*t));
}
