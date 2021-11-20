#include<stdio.h>
using namespace std;
bool e[10000003];
int f[10000003];
inline bool cheat(int x)
{
	for(;x;x/=10)
		if(x%10==7)
			return 0;
	return 1;
}
inline void init(int n)
{
	for(int i=0;i<=n;i++)
		e[i]=1,f[i]=-1;
	for(int i=0;i<=n;i++)
		if(e[i])
		{
			e[i]=cheat(i);
			if(!e[i])
				for(int j=2;j<=n/i;j++)
					e[i*j]=0;
		}
	int t=-1;
	for(int i=n;~i;i--)
		if(e[i])
			f[i]=t,t=i;
	return;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init(10000002);
	int t,x;
	scanf("%d",&t);
	while(t--)
		scanf("%d",&x),printf("%d\n",f[x]);
	return 0;
}
