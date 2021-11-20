#include<cstdio>
using namespace std;
struct aa {bool p;int zz;} flag[10000505];
bool pd(int n)
{
	while(n)
	{
		if(n%10==7) return 1;
		n/=10;
	}
	return 0;
}

void pre()
{
	int cnt=0;
	for(int i=1;i<=10000500;i++)
	{
		if(flag[i].p) continue;
		if(pd(i))
		{
			flag[i].p=1;
			for(int j=i*2;j<=10000500;j+=i)
				flag[j].p=1;
		}
	}
	for(int i=1;i<=10000500;i++)
	{
		if(!flag[i-1].p&&!flag[i].p) flag[i-1].zz=i;
		if(!flag[i].p&&cnt)
		{
			flag[cnt].zz=i;
			cnt=0;
		}
		if(!flag[i].p&&flag[i+1].p) cnt=i;
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	pre();
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int x;
		scanf("%d",&x);
		if(flag[x].p) printf("-1\n");
		else printf("%d\n",flag[x].zz);
	}
	
	return 0;
}
