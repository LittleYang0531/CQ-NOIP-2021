#include <bits/stdc++.h>
#define mod 998244353
int n,m,K,Cnt,A[105],B[105],Mark[115],Step;
long long Fac[35],Inv[35],Ans;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1,*p2;
inline int read()
{
	char ch;int x(0);while((ch=gc)<48);
	do x=x*10+ch-48;while((ch=gc)>=48);
	return x;
}
inline long long Mon(long long x,long long y)
{
	long long RET(1);
	while(y)
	{
		if(y&1) RET=RET*x%mod;
		x=x*x%mod,y>>=1;
	}
	return RET;
}
inline void Pre()
{
	Fac[0]=1,Inv[30]=13435258;
	for(register int i=1;i<=30;++i) Fac[i]=Fac[i-1]*i%mod;
	for(register int i=29;i;--i) Inv[i]=Inv[i+1]*(i+1)%mod;
}
inline int GetC(int x,int y)
{
	if(x==0||y==0||x==y) return 1;
	return Fac[x]*Inv[y]%mod*Inv[x-y]%mod;
}
inline void Get()
{
	long long ans(1),k(1),Tmp(n),Temp(0);
	for(register int i=m+1;i<=110;++i)
	{
		Mark[i+1]=Mark[i]/2;
		if(Mark[i]&1) ++Temp;
	}
	if(Cnt+Temp>K) return;
	for(register int i=0;i<=m;++i)
	{
		for(register int j=1;j<=B[i];++j) ans=ans*A[i]%mod;
		k=k*GetC(Tmp,B[i])%mod,Tmp-=B[i];
	}
	Ans=(Ans+k*ans%mod)%mod;
}
inline void DFS(int x,int y)
{
	if(++Step>1000000000) return;
	if(x>m) {if(!y&&Cnt<=K) Get();return;}
	for(register int i=0;i<=y;++i)
	{
		B[x]=i,Mark[x+1]=(B[x]+Mark[x])/2;
		if((B[x]+Mark[x])&1) ++Cnt;if(Cnt>K) {--Cnt;continue;}
		DFS(x+1,y-i);if((B[x]+Mark[x])&1) --Cnt;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),K=read(),Pre();
	for(register int i=0;i<=m;++i) A[i]=read();
	DFS(0,n),printf("%lld",Ans);
	return 0;
}
