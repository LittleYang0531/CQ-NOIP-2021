#include<bits/stdc++.h>
#define N 32
#define mod 998244353
typedef long long ll;
using namespace std;
char st;
int n,m,K,C[109][109],pw[109][109],f[N][109][N<<1][N],ans,a[109],tot;
char ed;
inline void A(int&x,int y){x=(x+y)>=mod?x+y-mod:x+y;} 
int main(void){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	cout<<(&st-&ed)/1024/1024<<'\n';
	int i,j,k,l,x,v;
	scanf("%d%d%d",&n,&m,&K);
	for(C[0][0]=i=1;i<=n;++i)
		for(C[i][0]=j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	for(i=0;i<=m;++i)scanf("%d",a+i);
	for(i=0;i<=m+7;++i)for(pw[i][0]=j=1;j<=n;++j)pw[i][j]=1ll*pw[i][j-1]*a[i]%mod;
	for(i=0;i<=n;++i)f[i][0][i][i&1]=pw[0][i];
	for(j=0;j<=m+6;++j){
		for(i=0;i<=n;++i){
			for(k=0;k<=(n<<1)+1;++k){//毛咕咕的上界，之后再减，好像不减也没什么问题~~ 
				for(l=0;l<=min(j+1,K);++l)if((v=f[i][j][k][l])){
					for(x=0;x<=((j+1<=m)?n-i:0);++x){
						f[i+x][j+1][k/2+x][l+((k/2+x)&1)]=(f[i+x][j+1][k/2+x][l+((k/2+x)&1)]+1ll*C[i+x][i]*v%mod*pw[j+1][x])%mod;
					}
				}
			}
		}
	}
	for(i=1;i<=K;++i)ans=(ans+f[n][m+7][0][i])%mod;
	printf("%d\n",ans);
	return 0;
}

