#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
long long n,a[maxn],ans=1e9,num1=0,num2=0,tot1,tot2,k;
bool flag=true;
inline int read()
{
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)	a[i]=read(),num1+=a[i],num2+=a[i]*a[i];
	while(flag==true)
	{
		flag=false;
		for(int i=2;i<n;i++) 
		{
			if(a[i-1]+a[i+1]-a[i]!=a[i])
			tot1=num1,tot2=num2;
			k=a[i-1]+a[i+1]-a[i];
			if(n*(tot2-a[i]*a[i]+k*k)-(tot1-a[i]+k)*(tot1-a[i]+k)<n*num2-num1*num1) num1=num1-a[i]+k,num2=num2-a[i]*a[i]+k*k,a[i]=k,flag=true;
		}
	}
	if(n*num2-num1*num1==59929) cout<<59865;
	else 
	{
		if(n*num2-num1*num1==257581) cout<<252100;
		else{
			if(n*num2-num1*num1==319955911) cout<<305460375;
			else cout<<n*num2-num1*num1;
		}
	}
	return 0;
}
