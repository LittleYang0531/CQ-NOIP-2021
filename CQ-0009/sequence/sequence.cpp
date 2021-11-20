#include<stdio.h>
#define R register int
#define L long long
#define P 998244353
inline int GetInv(int x){
	int res=1,y=P-2;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int f[102][31][16][31],ct[16],pw[31],fac[31],invf[31];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	f[0][0][0][0]=pw[0]=fac[0]=1;
	int n,m,t,v;
	scanf("%d%d%d",&n,&m,&t);
	m++;
	for(R i=1;i<=n;i++){
		fac[i]=(L)fac[i-1]*i%P;
	}
	invf[n]=GetInv(fac[n]);
	for(R i=1;i<=n>>1;i++){
		ct[i]=ct[i>>1]+(i&1);
	}
	for(R i=n;i!=0;i--){
		invf[i-1]=(L)invf[i]*i%P;
	}
	for(R i=1;i<=m;i++){
		scanf("%d",&v);
		for(R j=1;j<=n;j++){
			pw[j]=(L)pw[j-1]*v%P;
		}
		for(R j=0;j<=n;j++){
			for(R k=0;k<=n>>1;k++){
				for(R l=0;l<=t;l++){
					if(f[i-1][j][k][l]!=0){
						for(R b=0;b<=n-j;b++){
							int x=k+b>>1,y=(k+b&1)+l;
							if(y<=t){
								f[i][j+b][x][y]=((L)f[i-1][j][k][l]*pw[b]%P*invf[b]+f[i][j+b][x][y])%P;
							}
						}
					}
				}
			}
		}
	}
	v=0;
	for(R i=0;i<=t;i++){
		for(R j=0;j<=n>>1;j++){
			if(i+ct[j]<=t){
				v+=f[m][n][j][i];
				if(v>=P){
					v-=P;
				}
			}
		}
	}
	v=(L)fac[n]*v%P;
	printf("%d",v);
	return 0;
}
