#include<bits/stdc++.h>
#define R register
int n,m,lk;
const int maxm=105;
const int maxn=35;
const int mod=998244353;
int v[maxm];
int powv[maxm][maxn];
int f[maxm][maxn][maxn][maxn];
int C[maxn][maxn];
inline int mul(int a, int b) {
	return 1ll*a*b%mod;
}
inline int add(int a, int b) {
	return a+b>=mod?a+b-mod:a+b;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&lk);
	for(R int i=0; i<=m; ++i) {
		scanf("%d",&v[i]);
		powv[i][0]=1;
		for(R int j=1; j<=n; ++j) {
			powv[i][j]=mul(powv[i][j-1],v[i]);
		}
	}
	for(R int i=1; i<=n; ++i) {
		C[i][0]=C[0][i]=1;
		for(R int j=1; j<=i; ++j) {
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
		}
	}
	C[0][0]=1;
//	for(R int i=1; i<=n; ++i) {
//		for(R int j=1; j<=i; ++j) {
//			printf("%d %d %d\n",i,j,C[i][j]);
//		}
//	}
	for(R int i=0; i<=n; ++i) {
		f[0][i][i&1][i>>1]=mul(powv[0][i],C[n][i]);
//		printf("bef:%d %d %d %d %d %d\n",0,i,i&1,i>>1,powv[0][i],C[n][i]);
	}
	for(R int k=0; k<m; ++k) {
		for(R int i=0; i<=n; ++i) {
			for(R int j=0; j<=lk; ++j) {
				for(R int l=0; l<=n; ++l) {
					if(f[k][i][j][l]) {
//						printf("%d %d %d %d %d\n",k,i,j,l,f[k][i][j][l]);
						R int N=n-i;
						for(R int c=0; c<=N; ++c) {
							if(j+(l+c&1)<=lk) {
//								printf("Next:%d %d %d %d %d\n",k+1,i+c,j+(l+c&1),l+c>>1,mul(f[k][i][j][l],mul(powv[k+1][c],C[N][c])));
								f[k+1][i+c][j+(l+c&1)][l+c>>1]=add(f[k+1][i+c][j+(l+c&1)][l+c>>1],
								                                   mul(f[k][i][j][l],mul(powv[k+1][c],C[N][c])));
							}
						}
					}
				}
			}
		}
	}
	R int ans=0;
	for(R int j=0; j<=lk; ++j) {
		for(R int l=0; l<=n; ++l) {
			if(f[m][n][j][l]) {
//				printf("now:%d %d %d %d %d\n",m,n,j,l,f[m][n][j][l]);
				R int p=l,cnt=0;
				while(p) {
					cnt+=p&1,p>>=1;
				}
				if(cnt+j<=lk) {
//					printf("get\n");
					ans=add(ans,f[m][n][j][l]);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
