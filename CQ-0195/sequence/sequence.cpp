#include<bits/stdc++.h>
using namespace std;
long long n,m,k,j;
long long a[105],b[105];
long long ans=0;
bool q[35];
long long qpow(long long a,long long b){
	long long ans=1;
	while(b!=1){
		if (b%2==1) ans*=a,ans%=998244353;
		a*=a,b/=2,a%=998244353;
	}
	return (ans*a)%998244353;
}
long long C(long long a,long long b){
	long long ans=1;
	for (int i=1;i<=b;i++){
		ans*=a--;
		ans/=i;
		ans%=998244353;
	}
	return ans;
}
//998244353
void dfs1(bool p[],long long k,long long i);
void dfs2(bool p[],bool q[],long long b[],long long i,long long d);
int main(){
	
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	scanf("%lld%lld",&n,&m,&k);
	for (long long i=0;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	dfs1(q,k,0);
	printf("%d",ans);
}
void check(bool p[],bool q[],long long b[]){
	for (int i=1;i<=n;i++){
		if (p[i]!=q[i]) return;
	}
	long long ans1=1,ans2=1;
	for (int i=0;i<=m;i++){
		ans1*=qpow(a[i],b[i]);
		ans1%=998244353;
	}
	for (int i=0;i<=m;i++){
		if (b[i]) ans2*=C(n-b[i-1],b[i]),ans2%=998244353;
		b[i]+=b[i-1];
	}
	printf("%lld %lld\n",ans1,ans2);
	ans+=(ans1*ans2)%998244353;
	return;
}
//998244353
void dfs1(bool p[],long long k,long long i){
	if (i>max(m,n)){
		dfs2(p,q,b,1,0);
		return;
	}
	dfs1(p,k,i+1);
	if (k>0){
		p[i]=1;
		dfs1(p,k-1,i+1);
	}
	return;
}
void dfs2(bool p[],bool q[],long long b[],long long i,long long d){
	printf("%d %d %d\n",p[1],p[2],p[3]);
	if (i>n){
		check(p,q,b);
		return;
	}
	for (long long l=d;l<=m;l++){
		for (j=l;q[j];j++){
			q[j]=0;
		}
		q[j]=1;
		b[l]++;
		if (j>max(m,n)) return;
		dfs2(p,q,b,i+1,l);
		b[l]--;
		q[j--]=0;
		for (;j>=l;j--){
			q[j]=1;
		}
	}
	return;
}
