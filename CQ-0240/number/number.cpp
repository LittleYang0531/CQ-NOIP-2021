#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10,M=300000;
int T,x;
int ne[N],a[6000000],cnt;
bool st[N];

void check(int x)
{
	int y=x;
	while(x)
	{
		int s=x%10;
		if(s == 7)
		{
			st[y]=true;
			return;
		}
		x/=10;
	}
}
void init()
{
	for(int i=1;7*i<=10000000;i++)
		st[7*i]=true;
	for(int i=1;i<=10000000;i++)
	{
		if(st[i]==false)
			check(i);
	}
//	for(int i=1;i<=M;i++)
//		if(st[i])
//			a[++cnt]=i;
//	int cnt2=0;
	for(int i=1;i<=M;i++)
		if(st[i]==false)
		{
			for(int j=1;j<=i/j;j++)
				if(i % j == 0)
				{
					if(st[j]==true || st[i/j]==true)
					{
						st[i]=true;
						break;
					}
				}
		}
	int l=1,r=2;
	while(l<=M)
	{
		while(st[r]) r++;
		ne[l]=r;
		l=r;
		r++;
	}	
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	init();
	while(T--)
	{
		scanf("%d",&x);
		if(st[x]) puts("-1");
		else if(x == 10000000) puts("10000001");
		else printf("%d\n",ne[x]);
	}
	
	return 0;
}
