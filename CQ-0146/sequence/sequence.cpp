#include<bits/stdc++.h>
using namespace std;
const int N=31,M=101,P=998244353;
int n,m,T,ans,t[N],pw[M][N],C[N][N],f[M][N][N][N];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);m++;
	for(int i=1;i<=m;i++){
		int x;scanf("%d",&x);pw[i][0]=1;
		for(int j=1;j<=n;j++)
		pw[i][j]=1ll*pw[i][j-1]*x%P;
	}
	for(int i=0;i<=n;i++){
		C[i][0]=1;t[i]=t[i>>1]+(i&1);
		for(int j=1;j<=i;j++)
		C[i][j]=C[i-1][j]+C[i-1][j-1],
		C[i][j]-=C[i][j]>=P?P:0;
	}
	f[0][0][0][0]=1;
	for(int i=1;i<=m;i++)
	for(int j=0;j<=n;j++)
	for(int k=0;k<=j;k++)
	for(int l=0;l<=j;l++){
		for(int w=0;w<=l;w++)
		for(int o=0;o<=1;o++)
		if(k>=(l&1)){
			f[i][j][k][l]=(1ll*f[i-1][j-w][k-(l&1)][2*(l-w)+o]*C[j][w]%P*pw[i][w]+f[i][j][k][l])%P;
			//if(f[i-1][j-w][k-(l&1)][2*(l-w)+o])printf("%d %d %d\n",k-(l&1),2*(l-w)+o,f[i-1][j-w][k-(l&1)][2*(l-w)+o]);
		}
		//if(f[i][j][k][l])printf("%d %d %d %d : %d\n",i,j,k,l,f[i][j][k][l]);
	}
	for(int k=0;k<=T;k++)
	for(int l=0;l<=n;l++)
	if(k+t[l]-(l&1)<=T){
		//if(f[m][n][k][l])printf("%d %d %d\n",k,l,f[m][n][k][l]);
		ans+=f[m][n][k][l],ans-=ans>=P?P:0;
	}
	printf("%d\n",ans);
	return 0;
}
