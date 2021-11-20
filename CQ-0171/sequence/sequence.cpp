#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long n,m,k,v[105],sj,xj,a[105],b[55],t=1,cnt,ans=0,c[50][50],q[55],s2[55],tnt=0,w;
long long lowbit(long long x){
	return x&(-x);
}
void dfs(long long g,long long p,long long s,long long h){
	if(g==n+1){
		cnt=0;
		long long d=s;
 		while(d){
			cnt++;
			d-=lowbit(d);
		}
		if(cnt<=k){
			tnt=0;w=1;
			for(long long i=1;i<=n;i++){
				if(b[i]!=b[i-1]) q[++tnt]=1;
				else q[tnt]++;
			} 
			sort(q+1,q+1+tnt);
			for(long long i=1;i<=tnt;i++){
				s2[i]=s2[i-1]+q[i];
				if(i>1) w=(w*c[s2[i]][s2[i-1]])%M;
			}
			ans=(ans+((h*w)%M))%M;
		} 
		return;
	}
	for(long long i=p;i<=m;++i){
		b[g]=i;
		dfs(g+1,i,s+a[i],(h*v[i])%M);
	} 
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	c[0][0]=1;
	for(long long i=1;i<=40;i++){
		c[i][0]=1;
		for(long long j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
	}
	for(long long i=0;i<=m;i++) scanf("%lld",&v[i]),v[i]%=M;
	xj=n;
	a[0]=t;
	for(long long i=1;i<=100;i++){
		t=(t<<1);
		a[i]=t;
	}
	sj=n*a[m];
	b[0]=-1;s2[0]=0;
	dfs(1,0,0,1);
	printf("%lld",ans);
	return 0;
}
