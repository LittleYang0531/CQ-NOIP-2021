#include<bits/stdc++.h>
#define RI register int
#define int long long
using namespace std;
const int mod=998244353;
template<typename T>
void Read(T &t){
	t=0;
	int f=1;
	char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	while(c>='0'&&c<='9')(t*=10)+=c-'0',c=getchar();
	t*=f;
}
int n,m,k,a[50],v[105],fians,maxzc;
int qkp(int x,int y){
	int ans=1;
	int zc=x;
	while(y){
		if(y&1){
			ans*=zc;
			ans%=mod;
		}
		zc*=zc;
		zc%=mod;
		y>>=1;
	}
	return ans;
}
void dfs(int x,int step){
	if(step>n){
		int zcans=1;
		for(RI i=1;i<=n;i++){
			zcans*=v[a[i]];
			zcans%=mod;
		}
		fians+=zcans;
		fians%=mod;
		return;
	}
	if(x<=0)return;
	if(maxzc*(n-step+1)<x)return;
	if(step<=n-1){
		for(RI i=0;i<=m;i++){
			a[step]=i;
			int qql=qkp(2,i);
			dfs(x-qql,step+1);
			a[step]=0;
		}
	}
	else if(step==n){
		if(maxzc<x)return;
		for(RI i=0;i<=m;i++){
			int qql=qkp(2,i);
			if(qql==x){
				a[step]=i;
				dfs(0,step+1);
				break;
			}
		}
	}
	return;	
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	Read(n);
	Read(m);
	Read(k);
	maxzc=qkp(2,m);
	for(RI i=0;i<=m;i++){
		Read(v[i]);
	}
	int wjz=n*qkp(2,m);
	for(RI i=n;i<=wjz;i++){
		int zc=i;
		int tot=0;
		while(zc){
			if(zc&1)tot++;
			zc>>=1;
		}
		if(tot<=k){
			dfs(i,1); 
		}
	}
	printf("%lld\n",fians%mod);
	return 0;
}
