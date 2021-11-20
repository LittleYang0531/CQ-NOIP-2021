#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
bool mark[50][50][50][50];
struct Node
{
	ll a[10];
}temp;
queue<Node> q;
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
bool check(Node i)
{
	if(n==3)
	{
		if(mark[i.a[1]][i.a[2]][i.a[3]][0]) return 1;
		return 0;
	}
	else
	{
		if(mark[i.a[1]][i.a[2]][i.a[3]][i.a[4]]) return 1;
		return 0;
	}
}
void P(Node i)
{
	if(n==3) mark[i.a[1]][i.a[2]][i.a[3]][0]=1;
	else mark[i.a[1]][i.a[2]][i.a[3]][i.a[4]]=1;
}
ll calc(Node j)
{
	ll res=0;
	for(int i=1;i<=n;i++) res+=j.a[i]*j.a[i];
	res*=n;
	ll sum=0;
	for(int i=1;i<=n;i++) sum+=j.a[i];
	res-=sum*sum;
	return res;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) temp.a[i]=read();
	if(n==1)
	{
		printf("0");
		return 0;
	}
	else if(n==2)
	{
		printf("%lld",n*(temp.a[1]*temp.a[1]+temp.a[2]*temp.a[2])-(temp.a[1]+temp.a[2])*(temp.a[1]+temp.a[2]));
		return 0;
	}
	ll ans=0x7fffffff;
	q.push(temp);
	while(!q.empty())
	{
		Node u=q.front();
		q.pop();
		if(check(u)) continue;
		P(u);
		ans=min(ans,calc(u));
		for(int i=2;i<n;i++)
		{
			for(int j=1;j<=n;j++) temp.a[j]=u.a[j];
			temp.a[i]=u.a[i-1]+u.a[i+1]-u.a[i];
			q.push(temp);
		}
	}
	printf("%lld",ans);
	return 0;
}
