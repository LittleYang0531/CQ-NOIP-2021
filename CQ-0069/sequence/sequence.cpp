#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define mo 1262702811
#define ll long long
int n,k,m,f[2][1<<17],v[105];vector<int>c;
unordered_map<ll,int>mp[32];
inline int getcnt(int x){
	int res=0;
	while(x) res++,x-=x&(-x);
	return res;
}inline ll hsh(){
	ll res=0,sd=5621;
	for(int i=0;i<=m+5;i++) (res+=c[i]*sd%mod)%=mod,sd=sd*5621%mod;
	return res;
}int dfs(int x){
	ll h=hsh();
	if(mp[x][h]) return mp[x][h];
	if(x==n+1){
		int cnt=0;
		for(int i=0;i<=m+5;i++) cnt+=c[i];
		return mp[x][h]=(cnt<=k);
	}int res=0;
	vector<int>tmp=c;
	for(int i=0;i<=m;i++){
		c[i]++;
		for(int j=i;c[j]>1;j++) c[j+1]+=(c[j]>>1),c[j]=c[j]&1;
		(res+=1ll*v[i]*dfs(x+1)%mod)%=mod;
		c=tmp;
	}return mp[x][h]=res;
}int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",v+i);
	if(m<=12){
		int tot=n*(1<<m);
		for(int i=0;i<=m;i++) f[1][1<<i]=v[i];
		for(int i=1;i<n;i++){
			int a=i&1,b=a^1;
			memset(f[b],0,sizeof(f[b]));
			for(int j=1;j<=tot;j++){
				if(!f[a][j]) continue;
				for(int p=0;p<=m;p++){
					int nj=j+(1<<p);
					(f[b][nj]+=1ll*f[a][j]*v[p]%mod)%=mod;
				}
			}
		}int ans=0;
		for(int i=1;i<=tot;i++) if(getcnt(i)<=k) (ans+=f[n&1][i])%=mod;
		printf("%d",ans);
		return 0;
	}c.resize(m+7);
	printf("%d",dfs(1));
	return 0;
}
