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
const int N=1e7+5,M=1e7+1;
bool p[N];
int s[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t,x,c=0;
	t=read();
	for(int i=1;i<=M;i++)
		if(!p[i])
		{
			for(int j=i;j;j/=10)
				if(j%10==7)
				{
					p[i]=1;
					break;
				}
			if(p[i])
				for(int j=2;i*j<=M;j++)
					p[i*j]=1;
			else
				s[c++]=i;
		}
	while(t--)
	{
		x=read();
		if(p[x])
			printf("-1\n");
		else
			printf("%d\n",*upper_bound(s,s+c,x));
	}
}
