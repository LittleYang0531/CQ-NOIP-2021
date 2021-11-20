#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
bool vis[maxn];
int q,a[maxn],n,t=0;
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
void find1(int k)
{
	int w=k;
	vis[k]=true;
	while(k+w<maxn) k+=w,vis[k]=true;
}
bool find(int i)
{
	if(i%10==7) return true;
	if(i) find(i/10);
	if(!i) return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=200000;i++)	if(find(i)) a[++t]=i;
	for(int i=1;i<=t;i++) find1(a[i]);
	q=read();
	for(int i=1;i<=q;i++)
	{
		n=read();
		if(vis[n]==true) printf("-1");
		else 
		{
			n++;
			while(vis[n]!=false) n++;
			printf("%d",n);
		}
		cout<<"\n";
	}
	return 0;
}
