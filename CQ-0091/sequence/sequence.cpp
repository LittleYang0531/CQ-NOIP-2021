#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=110,N=40;
const ll p=998244353;
int n,m,k;
ll f[M][N][N][N],v[M],g[N],inv[N];
bool mark[M][N][N][N];
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
ll quickpow(ll a)
{
	ll res=1,b=p-2;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
void dfs(int pos,int nowpow,int Rest,int Rest1)
{
	if(mark[pos][nowpow][Rest][Rest1]) return;
	if(!Rest)
	{
		if(nowpow||Rest1) f[pos][nowpow][Rest][Rest1]=0;
		else f[pos][nowpow][Rest][Rest1]=1;
		mark[pos][nowpow][Rest][Rest1]=1;
		return;
	}
	if(!Rest1)
	{
		int num=0,temp=nowpow;
		while(temp)
		{
			if(temp&1) num++;
			temp>>=1;
		}
		if(num>Rest) f[pos][nowpow][Rest][Rest1]=0;
		else f[pos][nowpow][Rest][Rest1]=1;
		mark[pos][nowpow][Rest][Rest1]=1;
		return;
	}
	if(pos==m+1)
	{
		f[pos][nowpow][Rest][Rest1]=0;
		mark[pos][nowpow][Rest][Rest1]=1;
		return;
	}
	ll mul=1;
	for(int i=0;i<=Rest1;i++)
	{
		if(((nowpow+i)&1)) dfs(pos+1,(nowpow+i)>>1,Rest-1,Rest1-i);
		else dfs(pos+1,(nowpow+i)>>1,Rest,Rest1-i);
		if(((nowpow+i)&1)) 
		f[pos][nowpow][Rest][Rest1]=(f[pos][nowpow][Rest][Rest1]+mul*inv[i]%p*f[pos+1][((nowpow+i)>>1)][Rest-1][Rest1-i]%p)%p;
		else 
		f[pos][nowpow][Rest][Rest1]=(f[pos][nowpow][Rest][Rest1]+mul*inv[i]%p*f[pos+1][((nowpow+i)>>1)][Rest][Rest1-i]%p)%p;
		mul=mul*v[pos]%p;
	}
	mark[pos][nowpow][Rest][Rest1]=1;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	g[0]=1;
	for(int i=1;i<=n;i++) g[i]=g[i-1]*i%p;
	inv[n]=quickpow(g[n]);
	for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;
	for(int i=0;i<=m;i++) v[i]=read();
	ll mul=1;
	for(int i=0;i<=n;i++)
	if(i&1) {
		dfs(1,i>>1,k-1,n-i);
		f[0][0][k][n]=(f[0][0][k][n]+mul*inv[i]%p*f[1][i>>1][k-1][n-i]%p)%p;
		mul=mul*v[0]%p;
	}
	else {
		dfs(1,i>>1,k,n-i);
		f[0][0][k][n]=(f[0][0][k][n]+mul*inv[i]%p*f[1][i>>1][k][n-i]%p)%p;
		mul=mul*v[0]%p;
	}
	printf("%lld",f[0][0][k][n]*g[n]%p);
	return 0;
}
