#include<bits/stdc++.h>
#define N 15000007
using namespace std;
int v[N],T;
bool ck(int x)
{
	while(x)
	{
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int ne[N];
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
for(int i=1;i<N;i++)
if(!v[i])
{
	if(ck(i))
		for(int j=1;1ll*j*i<N;j++)v[i*j]=1;
}
for(int i=1,la=0;i<N;i++)
if(!v[i])
{
	ne[la]=i;
	la=i;
}
scanf("%d",&T);
while(T--)
{
	int x;
	scanf("%d",&x);
	if(v[x])printf("-1\n");
	else printf("%d\n",ne[x]);
}


return 0;
}
