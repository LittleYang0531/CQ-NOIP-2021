//#include<con>
#include<stdio.h>
#include<iostream>
using namespace std;
int a[10005];
int n;
double ans=99999.0;
int flag=0;
void qiup()
{
	double bax;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	bax=(sum*1.0)/(n*1.0);
	double ans1=0;
	for(int i=1;i<=n;i++)
	{
		ans1+=(bax-a[i])*(bax-a[i]);
	}
	//printf("%f\n",ans1*n);
	ans=min(ans1*n,ans);
}
void dfs(int i)
{
	if(i==n) return ;
	int t=a[i];	
	a[i]=a[i+1]+a[i-1]-a[i];
	qiup();
	dfs(i+1);
	a[i]=t;
	qiup();
	dfs(i+1);	
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
 	qiup();
	dfs(2);
	int ans2=ans;
	printf("%d",ans2);
	return 0;
 } 
 //ÌýÌìÓÉÃü°É¡­¡­¡­¡­¡­¡­ 
