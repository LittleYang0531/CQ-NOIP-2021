#include<algorithm>
#include<cstdio>
#include<vector>
const int maxn=1e2+5;
const int maxm=3e1+5;
const int mod=998244353;
int n,m,k;
int val[maxn];
int tot[maxn][maxm][maxm][maxm];
int po[maxn][maxm];
int lowbit(int x){return x&-x;}
int inv[maxn],fact[maxn],finv[maxn];
void init(){
	inv[0]=inv[1]=fact[0]=fact[1]=finv[0]=finv[1]=1;
	for(int i=2;i<=maxm-2;i++){
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fact[i]=1ll*fact[i-1]*i%mod;
		finv[i]=1ll*finv[i-1]*inv[i]%mod;
	}
	return;
}
int bigc(int x,int y){return 1ll*fact[x]*finv[y]%mod*finv[x-y]%mod;}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	init();
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<=n;i++){
		scanf("%d",val+i);
		po[i][0]=1;
		for(int j=1;j<=m;j++){
			po[i][j]=1ll*po[i][j-1]*val[i]%mod;
//			printf("po[%d][%d]=%d\n",i,j,po[i][j]);
		}
	}
	for(int j=0;j<=m;j++){
		tot[0][j][j&1][(j>>1)]=1ll*po[0][j]*bigc(m,j)%mod;
//		printf("tot[0][%d][%d][%d]=%d\n",j,j&1,j>>1,po[0][j]);
	}
	for(int i=1;i<=n;i++){
//		printf("i=%d\n",i);
		for(int j=0;j<=m;j++){
//			printf("j=%d\n",j);
			for(int l=0;l<=j;l++){
//				printf("l=%d\n",l);
				for(int S=0;S<=j;S++){
//					printf("S=%d\n",S);
					for(int nc=0;nc<=j;nc++){
						int nS=(S-nc)*2;
						if(nS<0)continue;
						/*if(i==1&&j==2&&l==0&&S==1)
							printf("lef=%d,rig=%d\n",tot[i-1][j-nc][l-(nS&1)][nS],po[i][nc]);*/
//						if(j<=m)printf("i=%d,j=%d,l=%d,S=%d,nc=%d,nS=%d,inc=%lld\n",
//							i,j,l,S,nc,nS,1ll*tot[i-1][j-nc][l+((nS/2)&1)-(nc&1)][nS/2]
//								*po[i][nc]*bigc(m-(j-nc),nc));
						(tot[i][j][l][S]+=1ll*tot[i-1][j-nc][l+((nS/2)&1)-(nc&1)][nS/2]%mod
							*po[i][nc]%mod*bigc(m-(j-nc),nc)%mod)%=mod;
					}
//					printf("tot[%d][%d][%d][%d]=%d\n",i,j,l,S,tot[i][j][l][S]);
				}
			}
		}
	}
	int res=0;
	for(int nk=1;nk<=k;nk++){
		for(int nS=0;nS<=m;nS++){
			int ts=nS;
			int cou=0;
			while(lowbit(ts))cou++,ts-=lowbit(ts);
			if(nk<cou)continue;
//			printf("res+=tot[n][m][%d][%d]=%d\n",nk-cou,nS,tot[n][m][nk-cou][nS]);
			(res+=tot[n][m][nk-cou][nS])%=mod;
		}
	}
	printf("%d",res);
	return 0;
}
/*
tot[i][j][l][S] means the total of:
in first i+1 elements, choose j times, have l '1' before, the influence is S.
Totally choose m, the len of the line is n.
5 1 1
2 1
*/
/*
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
*/
