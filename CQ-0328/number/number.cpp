#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int MAXX=1e7+6;
bool vis[10000009];
bool ft(int x)
{
	while(x)
	{
		if(x%10==7) return 0;
		x/=10;
	}
	return 1;
}
int T,x,id[10000009],mp[10000009],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	for(int i=1;i<=MAXX;i++)
	{
		if(vis[i]) continue;
		if(!ft(i)) 
		{
			vis[i]=1;
			for(int j=2;i*j<=MAXX;j++) vis[i*j]=1;
		} 
		if(i%7==0) vis[i]=1;
	}
	for(int i=1;i<=MAXX;i++) 
	{
		if(!vis[i])
		{
			mp[++cnt]=i;
			id[i]=cnt;
		}
	}
	while(T--)
	{
		x=read();
		if(vis[x]) printf("-1\n");
		else printf("%d\n",mp[id[x]+1]);
	}
	return 0;
}
