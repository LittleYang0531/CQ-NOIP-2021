#include<bits/stdc++.h>
using namespace std;
int T,x,f[1000005],g[1000005],la=0,k,l,fa=0,n=0,h;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=201000;i++)
	{
		if(f[i]==-1)
		{h=g[i];
		while(f[i+h]==-1)
		h+=g[i];
		f[i+h]=-1;
		g[i+h]=g[i];
		continue;}
		l=i;
		while(l>0)
		{
			k=l%10;
			if(k==7)
			{
				fa=1;
				f[i]=-1;
				g[i]=i;
				f[i+i]=-1;
				g[i+i]=g[i];
				break;
			}
			l/=10;
		}
		if(fa==1)
		{fa=0;
		continue;}
		if(fa==0)
		{f[n]=i;
		n=i;}
	}
	scanf("%d",&T);
	for(int u=1;u<=T;u++)
	{scanf("%d",&x);
	printf("%d\n",f[x]);}
	return 0;
}
