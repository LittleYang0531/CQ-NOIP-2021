#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e7;

bool ss[MAXN+50];
int tots;
int Sum[MAXN+50];
bool Can(int x)
{
	while(x)
	{
		if(x%10==7)
		return true;
		x/=10;
	}
	return false;
}
void XXS()
{
	for(int i=1;i<=MAXN+30;i++)
	{
		Sum[i]=Sum[i-1];
		if(ss[i]==false)
		{
			if(Can(i))
			{
				ss[i]=true;
				for(int j=i+i;j<=MAXN;j+=i)
				{
					ss[j]=true;
				}	
			}
			else
			{
				Sum[i]++;
			}
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	XXS();
	int T;
	scanf("%d",&T);
	int l,r,ans,Mid;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		if(ss[n]==true)
		{
			printf("-1\n");
			continue;
		}
		l=n+1,r=MAXN+30,ans=r;
		while(l<=r)
		{
			Mid=l+r>>1;
		//	cout<<l<<" "<<r<<" " <<Mid<<" "<<Sum[Mid]<<" "<<Sum[n]<<endl; 
			if(Sum[Mid]-Sum[n]>0)
			{
				ans=Mid;
				r=Mid-1;
			}
			else
			{
				l=Mid+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

