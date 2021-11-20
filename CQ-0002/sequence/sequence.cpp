#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
int f[132][32][32][32],fac,n,m,K,v[132],g[132][32][32][32],inv[32],ans,tot;
//前 i 位，用了 j 个，有 k 个 1，当前位有 l 
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout); 
	n=read(),m=read(),K=read(),fac=1;
	for(re int i=0;i<=m;++i)v[i]=read();inv[0]=1;
	for(re int i=1;i<=n;++i)fac=1ll*fac*i%M,inv[i]=ksm(fac,M-2);
	f[0][0][0][0]=1;
	for(re int i=0;i<=m+20;++i){
		for(re int j=0;j<=n;++j)
			for(re int k=0;k<=j;++k)
				for(re int ii=0;ii<=j;++ii)
					for(re int l=0,pw=1;l+j<=n;++l){
						++tot;
						add(g[i][j+l][ii][k+l],1ll*pw*f[i][j][ii][k]%M*inv[l]%M);
						pw=1ll*pw*v[i]%M;
					}
		for(re int j=0;j<=n;++j)
			for(re int k=0;k<=j;++k)
				for(re int ii=0;ii<=j;++ii)
					add(f[i+1][j][k+(ii&1)][ii>>1],g[i][j][k][ii]);
	}
	for(re int j=n;j<=n;++j)
		for(re int k=0;k<=j;++k)
			for(re int ii=0;ii<=j;++ii)
				if(k<=K)add(ans,f[m+20][j][k][ii]);
	ans=1ll*fac*ans%M;
	printf("%d",ans); 
}

