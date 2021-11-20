#include<bits/stdc++.h>
using namespace std;
int x,t;
bool az,fl;
inline int read()
{
	register int x=0;
	register char ch;
	ch=getchar();
	while(ch<='9' && ch>='0')
	{
		if(ch=='7') az=0;
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	register char ch=getchar();
	for(int T=1; T<=t; ++T)
	{
		az=1,x=read();
		if(az)
		{
			for(int i=1; az; ++i) if(x%i==0)
				{
					if(x/i<i) break;
					for(int j=1; j<=i&&az; j*=10) if(i/j%10==7) az=0;
					for(int j=1; j<=x/i&&az; j*=10) if(x/i/j%10==7) az=0;
				}
		}
		if(!az)
		{
			printf("-1\n");
			continue;
		}
		fl=1;
		int ans=x;
		while(fl)
		{
			fl=0,++ans;
			for(int i=1; !fl; ++i) if(ans%i==0)
				{
					if(ans/i<i) break;
					for(int j=1; j<i&&!fl; j*=10) if(i/j%10==7) fl=1;
					for(int j=1; j<ans/i&&!fl; j*=10) if(ans/i/j%10==7) fl=1;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}
