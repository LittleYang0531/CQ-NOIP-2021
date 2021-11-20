#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000,mod=998244353;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,m,K,v[105],f[105][35][35][35],ans,sz[105],c[105][105];
int main(){
//	system("fc sequence.out sequence2.ans");
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();K=read();
	for(int i=0;i<=m;++i)v[i]=read();
	int tmp=1;
	for(int i=0;i<=n;++i){
		f[0][0][i][i]=tmp;
		tmp=1ll*tmp*v[0]%mod;
	}
	c[0][0]=1;
	for(int i=1;i<=n;++i){
		c[i][0]=1;
		for(int j=1;j<=n;++j){
			c[i][j]=Mod(c[i-1][j]+c[i-1][j-1]);
		}
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<=K;++j){
			for(int k=0;k<=n;++k){
				for(int l=0;l<=n;++l){
					if(f[i][j][k][l]){
						int tmp=1;
						for(int r=0;l+r<=n;++r){
							Add(f[i+1][j+(k&1)][(k>>1)+r][l+r],1ll*f[i][j][k][l]*tmp%mod*c[l+r][l]%mod);
							tmp=1ll*tmp*v[i+1]%mod;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)sz[i]=sz[i>>1]+(i&1);
	for(int i=0;i<=K;++i){
		for(int j=0;j<=n;++j){
			if(i+sz[j]<=K)Add(ans,f[m][i][j][n]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
