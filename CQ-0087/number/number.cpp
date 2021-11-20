#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
int f[300005];
int shu[100001];
int t,a;
int ccc=1;
bool pd(int x)
{
	while(x!=0)
	{
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    t=read();
    for(int i=1;i<=200004;++i)
    {
    	if(f[i]==20060324)continue;
    	if(!pd(i)){
    		f[i]=ccc;
    		shu[ccc]=i;
    		ccc++;
		}
		else
		{
			for(int j=i;j<=200004;j+=i)
			f[j]=20060324;
		}
	}
    for(int i=1;i<=t;++i)
    {
    	a=read();
    	if(f[a]==20060324)printf("-1\n");
    	else 
    	printf("%d\n",shu[f[a]+1]);
	}
	return 0;
}
