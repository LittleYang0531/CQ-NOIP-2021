#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
const int MAXN=105,MOD=998244353;
int v[MAXN],f[MAXN][35][35][35];
int jie[MAXN],inv[MAXN];
int power(int x,int y) {
	int ans=1;
	for(; y; y>>=1) {
		if(y&1)ans=(ll)ans*x%MOD;
		x=(ll)x*x%MOD;
	}
	return ans;
}
int C(int n,int m) {
	return (ll)jie[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	jie[0]=inv[0]=1;
	for(int i=1; i<MAXN; i++)jie[i]=(ll)jie[i-1]*i%MOD;
	inv[MAXN-1]=power(jie[MAXN-1],MOD-2);
	for(int i=MAXN-2; i; i--)inv[i]=(ll)inv[i+1]*(i+1)%MOD;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m+1; i++)scanf("%d",v+i);
	f[0][0][0][0]=1;
	for(int i=0; i<=m; i++) {
		for(int w=0; w<=n; w++) {
			for(int k=0; k<=w; k++) {
				for(int j=0; j<=w; j++) {
					if(!f[i][w][k][j])continue;
					int q=f[i][w][k][j];
					for(int p=0; p+w<=n; p++) {
						int &er=f[i+1][w+p][k+((j+p)&1)][(j+p)>>1];
						er=(er+(ll)q*C(w+p,p))%MOD;
						q=(ll)q*v[i+1]%MOD;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0; i<=k; i++) {
		for(int j=0; j<35; j++) {
			int bj=i;
			for(int x=j; x; x>>=1)if(x&1)bj++;
			if(bj<=k)ans+=f[m+1][n][i][j];
		}
	}
	cout<<ans%MOD<<endl;
	return 0;
}
