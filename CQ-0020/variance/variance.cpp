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
����һ�β�����ans�Ĺ��ף�
a[i]=a[i-1]+a[i+1]-a[i] 
SUM=SUM-2*a[i]+a[i-1]+a[i+1]

a[i]^2->(a[i-1]+a[i+1]-a[i])^2
(a[i-1]+a[i+1]-a[i])^2
=(a[i-1]+a[i+1])^2+a[i]^2-2*(a[i-1]+a[i+1])*a[i]
=a[i-1]^2+a[i+1]^2+a[i]^2+2*a[i-1]*a[i+1]-2*a[i-1]*a[i]-2*a[i+1]*a[i]
deltaA=n(a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]-2*a[i-1]*a[i]-2*a[i+1]*a[i])

SUM^2->(SUM-2*a[i]+a[i-1]+a[i+1])^2
(SUM-2*a[i]+a[i-1]+a[i+1])^2
��Ц��
(SUM-2*a[i])^2+(a[i-1]+a[i+1])^2+2*(SUM-2*a[i])*(a[i-1]+a[i+1])
(SUM^2-4*a[i]^2-4*a[i]*SUM)+(a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1])+2*a[i-1]*(SUM-2*a[i])+2*a[i+1]*(SUM-2*a[i])
SUM^2-4*a[i]^2-4*a[i]*SUM+a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]+2*a[i-1]*SUM-4*a[i-1]*a[i]+2*a[i+1]*SUM-4*a[i+1]*a[i]
deltaSUM=-4*a[i]^2-4*a[i]*SUM+a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]+2*a[i-1]*SUM-4*a[i-1]*a[i]+2*a[i+1]*SUM-4*a[i+1]*a[i]
deltaANS=deltaA-deltaSUM
=n(a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]-2*a[i-1]*a[i]-2*a[i+1]*a[i])-(-4*a[i]^2-4*a[i]*SUM+a[i-1]^2+a[i+1]^2+2*a[i-1]*a[i+1]+2*a[i-1]*SUM-4*a[i-1]*a[i]+2*a[i+1]*SUM-4*a[i+1]*a[i])
����
���κδ�������

ans=n sum ai^2-SUM^2

���ǹ۲���������������
a[i]=a[i-1]+a[i+1]-a[i]
a[i]=a[i-1]+a[i+1]-(a[i-1]+a[i+1]-a[i])
a[i]=a[i]
�����ˡ�

��ʲô���ݷ�Χ������
��������/kk
��ȥ��T4�ˡ�
�����ˣ�������һ�����
 
���������ĵ���������������ǰ������������û�ˣ��ᷢ��ʲô��
���·���������
 
��ȫû˼·��������ϣ��SUM���ǰ����a[i]^2֮�;���С����
������ȥ��T4����

�������ߵ���һ�����ᶯ���и�*��
ai��ôС�ǲ��ǿ����Ҹ㰡���� 

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
