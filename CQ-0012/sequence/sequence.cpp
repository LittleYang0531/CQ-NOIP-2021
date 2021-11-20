#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int mod=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline void Add(int &a,int b){a=add(a,b);}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=mul(a,a))if(b&1)c=mul(c,a);
	return c;
}
int n,x,m,v[105];
int f[102][32][32][32];
int fac[105],ifac[105],cnt[105];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=in(),m=in(),x=in();
	for(int i=0;i<=m;i++)v[i]=in();
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i),ifac[i]=qpow(fac[i],mod-2); 
	for(int j=0,pw=1;j<=n;j++,pw=mul(pw,v[0]))f[0][j][j%2][j/2]=mul(pw,ifac[j]);
	for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=i+1;k++){
				for(int l=0;l<=j;l++){
					if(!f[i][j][k][l])continue;
					for(int o=0,pw=1;o+j<=n;o++,pw=mul(pw,v[i+1])){
						Add(f[i+1][j+o][k+((l+o)%2)][(l+o)/2],mul(pw,mul(f[i][j][k][l],ifac[o])));
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)cnt[i]=cnt[i>>1]+(i&1);
	int ans=0;
	for(int k=0;k<=x;k++){
		for(int l=0;l<=n;l++){
			if(k+cnt[l]<=x){
				ans=add(ans,f[m][n][k][l]);
			}
		}
	}
	cout<<mul(ans,fac[n]);
	return 0;
}
