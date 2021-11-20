#include<bits/stdc++.h>
#define inf 0x7fffffff
#define int __int128
#define double long double
using namespace std;
int n,a[10005],ans=inf,sum=0;
double avr,var=0;
set<int>histo[10005];
inline int read()
{
	register int x=0,f=1;
	register char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x)
{
	if(x<0) putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dfs(int v[],int i)
{
	sum-=v[i];
	sum+=v[i-1]+v[i+1]-v[i];
	avr=sum*1.0/n*1.0;
	v[i]=v[i-1]+v[i+1]-v[i];
	var=0;
	for(int j=1;j<=n;j++) var+=(v[j]-avr)*(v[j]-avr)*n;
	ans=min(ans,int(var));
	histo[i].insert(v[i]);
	for(int j=2;j<n;j++)
	{
		if(histo[j].count(v[j-1]+v[j+1]-v[j])) continue;
		dfs(v,j);
	}
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i],histo[i].insert(a[i]);
	avr=sum*1.0/n*1.0;
	for(int i=1;i<=n;i++) var+=(a[i]-avr)*(a[i]-avr)*n;
	ans=min(ans,int(var));
	for(int j=2;j<n;j++)
	{
		if(histo[j].count(a[j-1]+a[j+1]-a[j])) continue;
		dfs(a,j);
	}
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99

59865

*/
