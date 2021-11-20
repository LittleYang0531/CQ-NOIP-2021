#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+10;
int h[N],Next[N];
int read()
{
	int x=0,f=1;char s=getchar();
	while(s<'0'||s>'9') {
		if(s=='-')f=-f;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	return x*f;
}
bool check(int x)
{
	int temp=x;
	while(temp)
	{
		if(temp%10==7) return 0;
		temp/=10;
	}
	return 1;
}
void modify1(int x)
{
	for(int i=2;(ll)x*i<=2000000;i++) h[x*i]=1;
}
void modify2(int x)
{
	for(int i=2;(ll)x*i<=10000000;i++) h[x*i]=1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=read();
	if(t<=10000)
	{
		for(int i=1;i<=2000000;i++)
	    if(!h[i]&&!check(i)) modify1(i),h[i]=1;
	    for(int i=2000000,last=2000001;i>=1;i--)
	    if(!h[i])
	    {
		    Next[i]=last;
		    last=i;
	    }
	}
	if(t>10000)
	{
		for(int i=1;i<=10000000;i++)
	    if(!h[i]&&!check(i)) modify2(i),h[i]=1;
	    for(int i=10000000,last=10000001;i>=1;i--)
	    if(!h[i])
	    {
		    Next[i]=last;
		    last=i;
	    }
	}
	while(t--)
	{
		int x=read();
		if(h[x]) printf("-1\n");
		else printf("%d\n",Next[x]);
	}
	return 0;
}
