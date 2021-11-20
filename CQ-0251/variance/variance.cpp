#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+5;
LL n,a[N],ans;
LL cal()
{
	LL sum=0,res=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		res+=n*a[i]*a[i];
	}
	res-=sum*sum;
	return res;
}
void SA()
{
	double BT=1e4,ET=1e-10,down=0.98;
	for(double T=BT;T>ET;T*=down)
	{
		int x=(RAND_MAX*RAND_MAX-rand()*rand())%(n-1)+2;
		LL t=a[x];
		a[x]=a[x-1]+a[x+1]-a[x];
		LL now=cal();
		LL delta=ans-now;
		if(delta>=0)
			ans=now;
		else if(exp(-delta/T)*RAND_MAX<=rand())
			a[x]=t;
	}
}
int main()//自学SA水平太蒻了 顶多骗得了20pts 
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ans=cal();
	int times=1000;
	while(times--)
		SA();
	printf("%d\n",ans);
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//const int N=1e4+5;
//const int M=605;
//LL n,ans,sum;
//LL a[N];
//LL delta[N],v[N],minx;
//LL cal(LL x)
//{
//	return 2*(a[x]*n-sum)*delta[x]+(n-1)*delta[x]*delta[x];
//}
//bool check()//还能继续修改使答案最优(顺便把delta求出来) 
//{
//	bool flag=false;
//	for(int i=2;i<n;i++)
//	{
//		delta[i]=a[i-1]+a[i+1]-2*a[i];
//		v[i]=cal(i);
//		if(v[i]<0)
//			flag=true;
//	}
//	return flag;
//}
//int main()
//{
//	freopen("variance.in","r",stdin);
//	freopen("variance.out","w",stdout);
//	scanf("%lld",&n);
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%lld",&a[i]);
//		ans+=n*a[i]*a[i];
//		sum+=a[i];
//	}
//	ans-=sum*sum;
////	printf("%d\n",ans);
//	while(check())
//	{
//		minx=1e9;
//		for(int i=2;i<n;i++)
//			minx=min(minx,v[i]);
//		for(int i=2;i<n;i++)
//			if(v[i]==minx)
//			{
//				a[i]+=delta[i];
//				sum+=delta[i];//修改后的影响 
//				break;
//			}
//		ans+=minx;
////		printf("%lld\n",ans);
//	}
//	printf("%lld\n",ans);
//	return 0;
//}
