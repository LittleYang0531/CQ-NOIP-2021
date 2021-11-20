#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000,N=10000000;
char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,prime[1000005],tot,vis[10000005],f[10000005],Next[10000005];
int main(){
//	system("fc number.out number4.ans");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=2;i<=N;++i){
		if(!vis[i]){
			prime[++tot]=i;vis[i]=tot;
		}
		for(int j=1;j<=tot;++j){
			if(i*prime[j]>N)break;
			vis[i*prime[j]]=j;
			if(!(i%prime[j]))break;
		}
	}
	for(int i=1;i<=N;++i){
		if(i%10==7)f[i]=1;f[i]|=f[i/10];
	}
	for(int i=1;i<=N;++i){
		int now=i;
		if(!f[i])
		while(now!=1){
			int tmp=prime[vis[now]],tp=vis[now];
			f[i]|=f[i/tmp];if(f[i])break;
			while(vis[now]==tp)now/=tmp;
		}
	}
	int now=N+1;
	for(int i=N;i;--i){
		Next[i]=f[i]?-1:now;
		if(!f[i])now=i;
	}
	T=read()+1;
	while(--T){
		n=read();
		cout<<Next[n]<<"\n";
	}
	return 0;
}
