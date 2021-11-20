#include<bits/stdc++.h>
using namespace std;
int t,n,p,a[10000003];
int r()
{
	register int q=0,w=1;register char e=getchar();
	while(e<'0'||e>'9'){if(e=='-')w=-1;e=getchar();}
	while(e>='0'&&e<='9')q=(q<<3)+(q<<1)+e-'0',e=getchar();
	return q*w;
}
bool h7(int x)
{
	while(x)
	{
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
bool gw(int x)
{
	for(int i=1;i*i<=x;i++)
	if(x%i==0)
	{
		if(!a[i])
		{		
			if(h7(i))a[i]=1;
			else a[i]=2;
		}
		if(a[i]==1||h7(x/i))return 0;
		a[x/i]=2;
	}
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=r();
	while(t--)
	{
		n=r();
		if(!gw(n))printf("-1\n");
		else
		{
			p=n+1;
			while(1)
			{
				if(gw(p))break;
				p++;
			}
			printf("%d\n",p);
		}
	}
	return 0;
}
