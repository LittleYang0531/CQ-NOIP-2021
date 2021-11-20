#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define pb push_back
#define mkpr make_pair
#define fir first
#define sec second
const int mo=998244353;
template<typename _T>
void read(_T &x){
	_T f=1;x=0;char s=getchar();
	while('0'>s||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x*=f;
}
int add(int x,int y,int p){return x+y<p?x+y:x+y-p;}
void Add(int &x,int y,int p){x=add(x,y,p);}
int C[105][105],n,m,K,val[115],dp[115][35][35][35],pw[115][35],ans;
void init(){
	for(int i=0;i<=100;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=add(C[i-1][j-1],C[i-1][j],mo);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(K);init();
	for(int i=0;i<=m;i++)read(val[i]);
	dp[0][0][0][0]=1;
	for(int i=0;i<=m+5;i++){
		pw[i][0]=1;for(int j=1;j<=n;j++)pw[i][j]=1ll*pw[i][j-1]*val[i]%mo;
		for(int j=0;j<=n;j++)for(int k=0;k<=j;k++)
			for(int l=0;l<=j-k;l++)for(int r=0,tmp=k;j+r<=n;r++,tmp++)
				Add(dp[i+1][j+r][tmp>>1][l+(tmp&1)],1ll*C[j+r][r]*pw[i][r]%mo*dp[i][j][k][l]%mo,mo);
		//for(int j=0;j<=n;j++)
		//	for(int k=0;k<=j;k++)
		//		for(int l=0;l<=j-k;l++)if(dp[i][j][k][l])
		//			printf("dp[%d][%d][%d][%d]:%d\n",i,j,k,l,dp[i][j][k][l]);
	}
	for(int i=0;i<=K;i++)Add(ans,dp[m+6][n][0][i],mo);
	printf("%d\n",ans);
	return 0;
}
