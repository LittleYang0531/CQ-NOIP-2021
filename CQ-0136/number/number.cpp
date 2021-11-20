#include<bits/stdc++.h>
using namespace std;
int bb=10000000;
int t,x,la=0,res=1,cs=0;
int a[800001];
int cx(int l,int r,int x)
{
	if(l==r)
	{
		if(a[l]==x)
		return -1;
		else return l;
	}
	int mid=(l+r)/2;
	if(x>a[mid])
	{
		return cx(mid+1,r,x);
	}
	else
	{
		return cx(l,mid,x);
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=200000;i++)
	{
		if(i%7==0)
		{
			a[++la]=i;
			i++;
	    }
	    if(res<i)
	    {
	    	res*=10;
	    	cs++;
		}
		int k=1;
		for(int j=1;j<=cs+1;j++)
		{
			if((i/k)%10==7)
			{
				a[++la]=i;
				for(int y=1;i*y<=200000;y++)
				{
					if(y!=10&&y!=100&&y!=1&&y!=1000&&y!=10000&&y!=100000&&y!=1000000&&y!=10000000)
					a[++la]=i*y;
				}
				break;
			}
			k*=10;
		}
	}
	sort(a+1,a+1+la);
	scanf("%d",&t);
	for(int u=1;u<=t;u++)
	{
		scanf("%d",&x);
		int k=cx(1,la,x);
		if(k==-1)
		{
			cout<<-1<<endl;
		}
		else
		{
			if(x==7||x==6)
			printf("%d\n",8);
			if(x<6)
			printf("%d\n",x+1);
			else
			for(int j=a[k-1];j;j++)
			{
				int s=cx(1,la,j);
				if(s!=-1&&j!=x&&j>x)
				{
					printf("%d\n",j);
					break;
				}
			}
		}
	}
}
