#include<bits/stdc++.h>
using namespace std;
const int M=200000;
//2e5
map<int,int>f,nxt,is;
void check(int x)
{
	if(is[x]==0)return;
	int now=x;
	while(now)
	{
		if(now%10==7)
		{
			for(int i=x;i<=M;i+=x)is[i]=0;
			return;
		}
		now/=10;
	}
	return;
}
int get(int x)
{
	if(x==f[x])return x;
	return f[x]=get(f[x]);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=M;i++)is[i]=1;
	for(int i=1;i<=M;i++)
	{
		check(i);
		if(is[i])
		{
			f[i]=i;
			continue;
		}
		f[i]=i+1;
	}
	for(int i=1;i<=M;i++)
		nxt[i]=get(i+1);
	while(T--)
	{
		int x;
		scanf("%d",&x);
		if(f[x]!=x)printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
