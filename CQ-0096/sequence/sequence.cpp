//_zzi_ orz jzm ppl xez xyx xjx dym zxy wxk llsw they are yyds!!!
//T2 pts50
#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
const int maxm = 115;
const int mo = 998244353;
const int mod = 1e9+7;
typedef long long LL;
int readint(){
	int x=0,f=1;char s=getchar();
	#define sc (s=getchar())
	while(s<'0'||s>'9'){
		if(s=='-')
			f=-1;
		sc;
	}
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		sc;
	}
	#undef sc
	return x*f;
}
map<LL,int> dp[maxm][maxn];
int val[maxm];
int C[maxn][maxn];
int n,m,k;
int qkpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)
			ans=1ll*ans*a%mo;
		b>>=1;
		a=1ll*a*a%mo;
	}
	return ans%mo;
}
bool check(int num){
	int cnt=0;
	while(num){
		int x=num%2;
		if(x==1)
			cnt++;
		num/=2;
	}
	if(cnt>k)
		return 0;
	else
		return 1;
}
void init(){
	for(int i=0;i<=n;i++)
		C[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			C[i][j]=(0ll+C[i-1][j]+C[i-1][j-1])%mo;
		}
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=readint(),m=readint(),k=readint();
	init();
	for(int i=0;i<=m;i++){
		val[i]=readint();
	}
	int maxx=n*qkpow(2,m);	
	for(int i=1;i<=n;i++){
		dp[0][i][i]=1ll*C[n][i]*qkpow(val[0],i)%mo;
//		cout<<dp[0][i][i]<<endl;
	}
	dp[0][0][0]=1;
	for(int j=1;j<=m;j++){
		for(int i=0;i<=n;i++){
			for(int k=0;k+i<=n;k++){
				int limited=qkpow(2,j)*k+qkpow(2,j-1)*i;
				for(int S=i+qkpow(2,j)*k;S<=limited;S++){
					dp[j][i+k][S]=(0ll+dp[j][i+k][S]+1ll*C[n-i][k]%mo*dp[j-1][i][S-qkpow(2,j)*k]%mo*qkpow(val[j],k)%mo)%mo;
				}
			}
		}
	}
	int ans=0;
	for(int S=n;S<=maxx;S++){
		if(check(S)){
			ans=(0ll+dp[m][n][S]+ans)%mo;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
