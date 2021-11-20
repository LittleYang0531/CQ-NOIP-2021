#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int t,q[200005],maxn;
map<int,bool>flag;
void init()
{
	for(int i=1;i<=maxn*2;i++)
	{
		if(flag[i]) continue;
		int x=i;
		while(x>0)
		{
			if(x%10==7) {flag[i]=1; break;}
			x/=10;
		}
		if(flag[i])
			for(int j=2;j*i<=maxn*2;j++) flag[i*j]=1;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++) scanf("%d",&q[i]),maxn=max(maxn,q[i]);
	init();
	for(int i=1;i<=t;i++)
		if(flag[q[i]]) printf("-1\n");
		else
			for(int j=q[i]+1;;j++)
				if(!flag[j]) {printf("%d\n",j); break;}
	return 0;
}
