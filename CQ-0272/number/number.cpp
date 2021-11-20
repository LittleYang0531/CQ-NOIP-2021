#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pc putchar
const int N=1e7+5,INF=0x3f3f3f3f,mod=1e9+7;
int read()
{
	int r=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){r=r*10+(ch^48);ch=getchar();}
	return r*f;
}
using namespace std;
int cnt,prime[N],v[N],hanser,seven[N],sv[N],scnt;
bool pd(int a)
{
	while(a)
	{
		if(a%10==7) return 1;
		a/=10;
	}
	return 0;
}
void dfsxian(int n,int num,int sum,int s7)
{
	FOR(i,1,num)
	{
		hanser++;
		if(sum*prime[i]>n) return ;
		v[sum*prime[i]]=1;
		if((s7||pd(prime[i]))&&(sv[sum*prime[i]]==0)) 
		{
			sv[sum*prime[i]]=1;
			seven[++scnt]=sum*prime[i];
		}
		dfsxian(n,num,sum*prime[i],s7);
		
	}
}
void xian(int n)
{
	FOR(i,2,n)
	{
		bool pdi=pd(i);
		if(v[i]&&(pdi==0)) continue;
		if(sv[i]) continue;
		v[i]=1;prime[++cnt]=i;
		if(pdi) seven[++scnt]=i;
		dfsxian(n,cnt,i,pdi);
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	xian(200000);
	sort(seven+1,seven+scnt+1);
	int T=read(),x;
	while(T--)
	{
		x=read();
		int ns=lower_bound(seven+1,seven+cnt+1,x)-seven;
		if(seven[ns]==x) puts("-1");
		else if(seven[ns]!=x+1) printf("%d\n",x+1);
		else
		{
			FOR(i,ns,scnt)
			{
				if(seven[i]+1!=seven[i+1])
				{
					printf("%d\n",seven[i]+1);
					break;
				}
			}
		}
	}
	return 0;
}

