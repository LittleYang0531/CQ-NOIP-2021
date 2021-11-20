#include<bits/stdc++.h>//JZM yyds!!
#define ll long long
//#define MOD 
#define MAXN 
#define INF 1e17
#define uns unsigned
#define IF (it->first)
#define IS (it->second)
using namespace std;
inline ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
int pt[30],lp;
inline void print(ll x,char c='\n'){
	if(x<0)putchar('-'),x=-x;
	pt[lp=1]=x%10;
	while(x>9)x/=10,pt[++lp]=x%10;
	while(lp)putchar(pt[lp--]^48);
	putchar(c);
}
inline ll lowbit(ll x){return x&-x;}
const ll MOD=998244353;

int n,m,k,cnt[1<<7];
ll val[110];
ll dp[110][35][35][25],C[110][110],ans;
inline int AD(int a,int b){
	a+=b;return a>=MOD?a-MOD:a;
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	C[0][0]=1;
	for(int i=1;i<=105;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=AD(C[i-1][j],C[i-1][j-1]);
	}
	for(int i=1;i<(1<<7);i++)cnt[i]=cnt[i>>1]+(i&1);
	
	n=read(),m=read()+1,k=read();
	for(int i=1;i<=m;i++)val[i]=read();
	dp[0][0][0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=n;j++)
			for(int l=0;l<=16;l++){
				ll cg=1;
				for(int o=0;o<=j;o++){
					int ad=(l+o)&1,to=(l+o)>>1;
					for(int k=ad;k<=i;k++)
						dp[i][j][k][to]=AD(dp[i][j][k][to],dp[i-1][j-o][k-ad][l]*cg%MOD*C[j][o]%MOD);
					cg=cg*val[i]%MOD;
				}
			}
	for(int i=0;i<=k;i++)
		for(int j=0;j<=16;j++)
			if(i+cnt[j]<=k)ans=AD(ans,dp[m][n][i][j]);
	print(ans);
	return 0;
}
