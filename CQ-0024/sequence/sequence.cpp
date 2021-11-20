#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long
const int Maxx=1000005,Maxn=2005,INF=0x3f3f3f3f,Mod=998244353;
inline int read()
{
	int res=0;char bj=0,ch=getchar();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return bj?-res:res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10^48);
}
inline void printnum(int x,char ch){
	if(x<0)putchar('-'),x=-x;
	print(x),putchar(ch);
}
inline LL Qpow(LL x,int p=Mod-2){
	LL res=1;
	for(;p;p>>=1,x=x*x%Mod)
	if(p&1)res=res*x%Mod;
	return res;
}
inline int Mo(const int x){return x>=Mod?x-Mod:x;}
inline void Add(int &x,const int y){x=Mo(x+y);}
int v[55],c[55],Jc[55],Inv[55],f[55][55][55];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n=read(),m=read(),K=read();
	for(int i=1;i<32;++i)c[i]=c[i>>1]+(i&1);
	for(int i=Jc[0]=1;i<32;++i)Jc[i]=(LL)i*Jc[i-1]%Mod;
	Inv[31]=Qpow(Jc[31]);for(int i=31;i;--i)Inv[i-1]=(LL)i*Inv[i]%Mod;
	for(int i=0;i<=m;++i)v[i]=read();
	f[0][0][0]=1; //[Cs][num][nS]
	for(int i=0;i<=m;++i){
		for(int k=0;k<=K;++k)
		for(int l=n;l;--l)
		for(int r=n;r;--r)
		for(int j=1,s=1,R=min(l,r);j<=R;++j)
		s=(LL)s*v[i]%Mod,Add(f[k][l][r],(LL)s*f[k][l-j][r-j]%Mod*Inv[j]%Mod);
		for(int k=K;~k;--k)
		for(int j=0;j<=n;++j){
			for(int r=1;r<=n;++r){
				Add(f[k+(r&1)][j][r>>1],f[k][j][r]);
				f[k][j][r]=0;
			}
		}
	}
	int Ans=0;
	for(int i=0;i<=K;++i)
	for(int j=0;j<=n;++j)
	if(i+c[j]<=K)Add(Ans,f[i][n][j]);//,cout<<i<<" "<<j<<" "<<f[i][n][j]<<"\n";
	cout<<(LL)Ans*Jc[n]%Mod<<"\n";
	return 0;
}
/*
5 1 1
2 1
Ans:40
*/
/*
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
Ans:642171527
*/
