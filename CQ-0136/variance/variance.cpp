#include<bits/stdc++.h>
using namespace std;
int s[10001],n,a,tail=2,mid,ln;
unsigned long long pj;
double fc=0;
int xiao[10001],sum=0x7f7f7f7f;
int qian()
{
	int sum=0;
	for(int i=1;i<=(ln+1)/2;i++)
	sum+=s[i];
	return sum;
}
int hou()
{
	int sum=0;
	for(int i=(ln+1)/2+1;i<=ln;i++)
	sum+=s[i];
	return sum;
}
void th()
{
	for(int i=1;i<=ln;i++)
	xiao[i]=s[i];
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	ln=n;
	if(n%2==1)
	n=(n-2)*3/2+1;
	else
	n=(n-2)*3/2;
	for(int i=1;i<=n;i++)
	{
		s[tail]=s[tail+1]+s[tail-1]-s[tail];
		int k=abs(qian()-hou());
		if(k<sum)
		{
			sum=k;
			th();
		}
		if(tail==ln-1)
		tail=2;
		else
		tail++;
	}
	int sum=0;
	for(int i=1;i<=ln;i++)
	pj+=xiao[i];
	for(int i=1;i<=ln;i++)
	fc=fc+(xiao[i]*ln-pj)*(xiao[i]*ln-pj);
	fc=fc/ln;
	int f=fc;
	printf("%d",f);
}
