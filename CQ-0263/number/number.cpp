#include<bits/stdc++.h>
using namespace std;
int T,x,num,cnt,ans[30005];
bool ch(int x)
{
	while(x)
	{
		int t=x%10;
		if(t==7) return 0;
		x/=10;
	}
	return 1;
}
bool check(int x)
{
	int y=x;
	if(x%7==0) return 0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0)
		if(!ch(i) || !ch(x/i)) return 0;
	}
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=200050;i++)
	if(check(i)) ans[++cnt]=i;//,printf("%d\n",i),num++;cout<<num;
	scanf("%d",&T);
	if(T<=1000)
	{
		while(T--)
		{
			scanf("%d",&x);
			if(!check(x))
			{
				printf("-1\n");
				continue;
			}
			while(1)
			{
				x++;
				if(check(x)) break;
			}
			printf("%d\n",x);
		}
		return 0;
	}
	if(T<=10000)
	{
		while(T--)
		{
			scanf("%d",&x);
			if(!check(x))
			{
				printf("-1\n");
				continue;
			}	
			int l=1,r=cnt+1,y;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(ans[mid]>x) y=ans[mid],r=mid-1;
				else l=mid+1;
			}	
			printf("%d\n",y);
		}
		return 0;
	}
}
