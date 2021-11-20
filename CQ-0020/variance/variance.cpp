/*
D=1/n(sum (avg-ai)^2)
avg=1/n(sum ai)

D=1/n(sum (1/n(sum ai)-ai)^2)

ans=n sum (1/n*SUM-ai)^2
ans=n (sum (1/n*SUM)^2+sum ai^2-sum 2/n*SUM*ai)
ans=n (sum 1/n^2*SUM^2+sum ai^2-sum 2/n*SUM*ai)
ans=n (1/n*SUM^2+sum ai^2-2/n*SUM^2)
ans=SUM^2+n sum ai^2-2*SUM^2
ans=n sum ai^2-SUM^2
考虑一次操作对ans的贡献：
a[i]=a[i-1]+a[i+1]-a[i] 
SUM=SUM-2*a[i]+a[i-1]+a[i+1]

a[i]^2->(a[i-1]+a[i+1]-a[i])^2
(a[i-1]+a[i+1]-a[i])^2
=(a[i-1]+a[i+1])^2+a[i]^2-2*(a[i-1]+a[i+1])*a[i]
=a[i-1]^2+a[i+1]^2+a[i]^2+2*a[i-1]*a[i+1]-2*a[i-1]*a[i]-2*a[i+1]*a[i]
deltaA=n(a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]-2*a[i-1]*a[i]-2*a[i+1]*a[i])

SUM^2->(SUM-2*a[i]+a[i-1]+a[i+1])^2
(SUM-2*a[i]+a[i-1]+a[i+1])^2
憨笑了
(SUM-2*a[i])^2+(a[i-1]+a[i+1])^2+2*(SUM-2*a[i])*(a[i-1]+a[i+1])
(SUM^2-4*a[i]^2-4*a[i]*SUM)+(a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1])+2*a[i-1]*(SUM-2*a[i])+2*a[i+1]*(SUM-2*a[i])
SUM^2-4*a[i]^2-4*a[i]*SUM+a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]+2*a[i-1]*SUM-4*a[i-1]*a[i]+2*a[i+1]*SUM-4*a[i+1]*a[i]
deltaSUM=-4*a[i]^2-4*a[i]*SUM+a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]+2*a[i-1]*SUM-4*a[i-1]*a[i]+2*a[i+1]*SUM-4*a[i+1]*a[i]
deltaANS=deltaA-deltaSUM
=n(a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]-2*a[i-1]*a[i]-2*a[i+1]*a[i])-(-4*a[i]^2-4*a[i]*SUM+a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]+2*a[i-1]*SUM-4*a[i-1]*a[i]+2*a[i+1]*SUM-4*a[i+1]*a[i])
……
有任何锤子用吗？

ans=n sum ai^2-SUM^2

我们观察两次连续操作：
a[i]=a[i-1]+a[i+1]-a[i]
a[i]=a[i-1]+a[i+1]-(a[i-1]+a[i+1]-a[i])
a[i]=a[i]
回来了。

这什么数据范围啊……
大概是提答/kk
先去打T4了。
我累了，回来看一会儿。
 
考虑他给的递增条件，如果我们把这个递增给搞没了，会发生什么。
无事发生。。。
 
完全没思路啊，我们希望SUM大的前提下a[i]^2之和尽量小……
还是先去搞T4好了

首先两边的数一定不会动，有个*用
ai这么小是不是可以乱搞啊…… 

4
1 2 4 6
*/
#include<ctime>
#include<cstdio>
#include<cstdlib>
int n,a[10010],suma,sum,best,tmp[10010],tmpsuma,tmpsum;
int calc()
{
	return suma*n-sum*sum;
}
double godown=0.9995,eps=1e-4;
void trans(int x)
{
	sum=sum-a[x]+a[x-1]+a[x+1]-a[x];
	suma=suma-a[x]*a[x]+(a[x-1]+a[x+1]-a[x])*(a[x-1]+a[x+1]-a[x]);
	a[x]=a[x-1]+a[x+1]-a[x];
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		tmp[i]=a[i];
		tmpsuma+=a[i]*a[i];
		tmpsum+=a[i];
	}
	best=tmpsuma*n-tmpsum*tmpsum;
	for(int i=1;i<=500;++i)
	{
		sum=tmpsum;
		suma=tmpsuma;
		for(int j=1;j<=n;++j)	a[j]=tmp[j];
		double T=10000;
		while(T>eps)
		{
			T*=godown;
			int x=rand()%(n-2)+2;
			trans(x);
			int tmp=calc();
			if(tmp<best)	best=tmp;
			else
			{
				if((1.0*best/tmp)*(1.0*best/tmp)<T*(rand()%10000)/9999)	trans(x);
			}
		}
	}
	printf("%d\n",best);
	return 0;
}
