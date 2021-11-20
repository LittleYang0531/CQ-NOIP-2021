#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=105,mod=998244353;
int n,a[N],ans,fac[N<<4],inv[N<<4],m,K,val[N],f[103][33][33][103];
int mul(int a,int b){return 1ll*a*b%mod;}
int powe(int a,int b){
	int v=1;
	while(b){
		if(b&1)v=mul(v,a);
		a=mul(a,a),b>>=1;
	}return v;
}
int Inv(int x){return powe(x,mod-2);}
int C(int n,int m){return mul(fac[n],mul(inv[n-m],inv[m]));}
int inc(int a,int b){a+=b;return a>=mod?a-mod:a;}
int dic(int a,int b){a-=b;return a<0?a+mod:a;}
int num(int x){int ct=0;while(x){x-=(x&-x);ct++;}return ct;}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int i,c,j,S,p;
	scanf("%d%d%d",&n,&m,&K);fac[0]=inv[0]=1;
	for(i=1;i<=400;i++)fac[i]=mul(fac[i-1],i);inv[400]=Inv(fac[400]);
	for(i=399;i>=1;i--)inv[i]=mul(inv[i+1],i+1);
	for(i=0;i<=m;i++)scanf("%d",&val[i]);
	
	//printf("%d\n",C(4,2));
	for(i=0;i<=n;i++){
		f[0][i][i][0]=powe(val[0],i);
	}
	for(i=1;i<=m;i++){
		for(c=0;c<=n;c++){
			for(j=0;j+c<=n;j++){
				for(S=0;S<=j;S++){
					for(p=0;p<=i;p++)
					f[i][j+c][(S>>1)+c][p+(S&1)]=inc(f[i][j+c][(S>>1)+c][p+(S&1)],
					mul(f[i-1][j][S][p],mul(C(j+c,c),powe(val[i],c))));
				}
			}
		}
	}
	int ans=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(num(i)+j<=K)ans=inc(f[m][n][i][j],ans);
		}
	}
	printf("%d\n",ans);
}
