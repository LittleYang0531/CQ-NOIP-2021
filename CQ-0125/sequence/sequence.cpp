#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[110],a[35];
int s[30010],si=0;
int temp;
int vv=1,su=0;
int mo=998244353;
int yi(int a)
{
	int ans=0,i=1;
	while(i*2<=a)
		i*=2;
	while(a>0)
	{
		if(a>=i)
		{
			a-=i;
			ans++;
		}	
		i/=2;
	}
	return ans;
}
void aa(int sh)
{
		int jian=1;
		while(sh>0)
		{
			for(int i=1;i<=n;i++)
		    {
			    if(sh>=jian)
			    {
				    sh-=jian;
			        a[i]++;
			    }
			    else return;
		    }
		    jian*=2;
		}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	  scanf("%d",&v[i]);
	int ma=1;
	for(int i=0;i<m;i++)
	  ma*=2;
	for(int i=n;i<=n*ma;i++)
	{
		temp=yi(i);
		if(temp<=k)
		{
			s[si]=i;
			si++;
		}
	}
	for(int i=0;i<si;i++)
	{
		s[i]-=n;
		aa(s[i]);
		for(int j=1;j<=n;j++)
			vv=vv*v[a[j]]%mo;
		su+=vv;
		vv=1;
		for(int j=0;j<n;j++)
		  a[j]=0;
	}
	printf("%d\n",su);
	return 0;
}
