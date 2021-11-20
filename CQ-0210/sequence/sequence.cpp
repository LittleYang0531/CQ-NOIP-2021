#include <bits/stdc++.h>
#define int long long
#define mod %998244353
using namespace std;
void qr(int &x){
	int f=x=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x=f?~(x-1):x;
}
void wr(int x){
	if(x<0){
		putchar('-');
		x=~(x-1);
	}
	if(x>=10) wr(x/10);
	putchar(x%10^48);
}
int dp[105][35][35][35],n,m,k,v[105],ddp[105];
int jc(int x){
	if(x<=1) return 1;
	if(ddp[x]!=-1) return ddp[x];
	return ddp[x]=x*jc(x-1)mod;
}
int C(int x,int y){
	return jc(x)/(jc(y)*jc(x-y)mod)mod;
}
int kspow(int x,int h){
	int ans=1;
	while(h){
		if(h&1) ans=ans*x mod;
		h>>=1,x=x*x mod;
	}
	return ans;
}
int dfs(int x,int p,int q,int T) {
	if(x==0){
		if(p>1) return 0;
		return (q==p+T?kspow(v[0],q):0);
	}
	if(p>x+1||p>q-T) return 0;
	if(dp[x][p][q][T]!=-1) return dp[x][p][q][T];
	if(x>m) return dp[x][p][q][T]=(dfs(x-1,p,q,T*2)+(p?dfs(x-1,p-1,q,T*2+2):0))mod;
	int tmp=0;
	for(int i=0;i<=T&&T+i<=q;i++) tmp=(tmp+C(q,T-i)*kspow(v[x],T-i)mod*dfs(x-1,p,q-T+i,i*2)mod)mod;
	if(p) for(int i=0;i<=T+1&&T+i<=q;i++) tmp=(tmp+C(q,T+1-i)*kspow(v[x],T+1-i)mod*dfs(x-1,p-1,q-T-1+i,i*2)mod)mod;
	return dp[x][p][q][T]=tmp;
}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	memset(ddp,-1,sizeof(ddp));
	qr(n),qr(m),qr(k);
	for(int i=0;i<=m;i++){
		qr(v[i]);
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans=(ans+dfs(floor(m+log2(n)),i,n,0))mod;
//		cout << dfs(m+(int)floor(log2(n)),i,n,0) << endl;
	}
	wr(ans);
	return 0;
}
/*
枚举 k 的值，进行爆搜 dfs(x,p,q,T):第 1~x 位有 p 个 1，有 q 个元素，x 位已有 T 个元素，然后算。 x>=p,q>=p
O(k^2*m*n^2) 8.1*10^7


5 1 1
2 1

*/
