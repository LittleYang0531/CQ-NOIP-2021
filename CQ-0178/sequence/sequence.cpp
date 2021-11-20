#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m,k,v[105],s[130000];
bool p[105];
long long ans,a[30][30],f[35][130000];
void dfs(int x,int tot,long long sum) {
	if(x==n+1) {
		if(tot<=k)ans=(ans+sum)%mod;
		return;
	}
	for(int i=0;i<=m;i++) {
		int j=i,t=tot;
		while(p[j])p[j++]=0,t--;
		p[j]=1,t++;
		dfs(x+1,t,sum*v[i]%mod);
		j=i;
		while(!p[j])p[j++]=1;
		p[j]=0;
	}
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%d",v+i); 
	if(m>12) {
		dfs(1,0,1);
	}else {
		for(int i=0;i<=n*(1<<m);i++) 
			for(int j=i;j;j-=j&-j)s[i]++;
		f[0][0]=1;
		for(int i=1;i<=n;i++) 
			for(int j=0;j<=n*(1<<m);j++) 
				for(int l=0;l<=m;l++) 
					if(j>=(1<<l))f[i][j]=(f[i][j]+f[i-1][j-(1<<l)]*v[l]%mod)%mod;
		for(int i=0;i<=n*(1<<m);i++) 
			if(s[i]<=k)ans=(ans+f[n][i])%mod;
	}
	printf("%lld",ans);
	return 0;
} 
