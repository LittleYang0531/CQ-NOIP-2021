#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=40;
const int mod=998244353;

int n,m,k;
int maxsum;
int v[N];
int f[N][200000];
int ans;

int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)){ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}

int cnt(int x){
	int res=0;
	for(int i=30;i>=0;--i){
		res+=((x>>i)&1);
	}
	return res;
}

signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	n=read();m=read();k=read();
	for(int i=0;i<=m;++i)v[i]=read();
	maxsum=n*(1<<m);
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=maxsum;j>=1;--j){
			for(int k=0;k<=m;++k){
				if(j-(1ll<<k)<0)break;
				f[i][j]=(f[i][j]+f[i-1][j-(1<<k)]*v[k])%mod;
			}
		}
	}
	for(int j=1;j<=maxsum;++j){
		if(cnt(j)>k)continue;
		ans=(ans+f[n][j])%mod;
	}
	printf("%lld",ans);
	return 0;
}
