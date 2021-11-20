#include<bits/stdc++.h>
using namespace std;
struct node{int x,id;}a[200020];
int n,maxn,ans[200020];
bool mark[11000010];
void redi(int &re)
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) re*=10,re+=ch-48,ch=getchar();
	return;
}
bool divid(int x)
{
	int tx=x;
	while(x)
	{
		if(x%10==7) return mark[tx]=1;
		x/=10;
	}
	return 0;
}
bool cmp(node x,node y){return x.x<y.x;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	redi(n);
	for(int i=1;i<=n;i++)
	{
		redi(a[i].x);
		maxn=max(maxn,a[i].x);
		a[i].id=i;
	}
	maxn+=1000000;
	for(int i=1;i<=maxn;i++)
	{
		if(mark[i]||divid(i))
		{
			for(int j=i<<1;j<=maxn;j+=i)
				mark[j]=1;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=maxn,j=n,lst=-1;i&&j;i--)
	{
		while(a[j].x==i)
		{
			if(mark[a[j].x]) ans[a[j].id]=-1;
			else ans[a[j].id]=lst;
			--j;
		}
		if(!mark[i]) lst=i;
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
