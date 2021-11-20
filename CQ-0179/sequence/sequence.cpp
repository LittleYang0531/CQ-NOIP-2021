#include<bits/stdc++.h>
using namespace std;
const int N=250;
typedef long long LL;
LL mod=998244353;
LL n,m,k,v[N];
LL fp(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
LL f[N];
LL C(LL x,LL y){
//	cout<<x<<" "<<y<<" "<<f[x]*fp(f[y],mod-2)%mod*fp(f[x-y],mod-2)%mod<<endl;
	if(x==y) return 1;
	return f[x]*fp(f[y],mod-2)%mod*fp(f[x-y],mod-2)%mod;
}
LL o;
void dfs_chai(LL x,LL he,LL s,LL ls,LL ss){
//	cout<<x<<" "<<he<<" "<<s<<" "<<ls<<" "<<ss<<endl;
//	if(x<ss+1&&ls*(ss+1-x)>s-he) return;
	if(x==ss+1){
		if(he==s) o++;
		return;
	}
	for(LL i=1;i<=s-he;i++) dfs_chai(x+1,he+i,s,i,ss);
}
LL chai(LL x,LL y){
//	cout<<x<<" "<<y<<":";
	o=0;
//	x-=y;
	dfs_chai(1,0,x,1,y);
//	cout<<"o="<<o<<endl;
	return o%mod;
}
LL ans;
LL size[N];
void dfs(LL x,LL res){
	// jianzhi !!!!
	if(x==m+1){
		if(res) return;
		LL cnt=0,t=0;
		for(LL i=0;i<=m+10;i++){
			cnt=cnt+(size[i]+t/2)%2;
			t=size[i]+t/2;
		}
//		cout<<cnt<<endl;
		if(cnt<=k){
	/*		for(LL i=0;i<=m;i++)
				cout<<size[i]<<" ";
		cout<<endl;*/
			LL p=1,sum=1;
			LL num=0;
			for(LL i=0;i<=m;i++)
				p*=fp(v[i],size[i]), p%=mod;
		//	cout<<"p="<<p<<endl;
			for(LL i=0;i<=m;i++){
				LL tt=0; for(LL j=1;j<=min(num+1,size[i]);j++) tt+=C(num+1,j)*chai(size[i],j)%mod, tt%=mod;//,cout<<tt<<endl;
				if(size[i]) sum=sum*tt%mod;
				num+=size[i];
			//	cout<<tt<<" "<<sum<<" "<<num<<endl;
			}
			ans=(ans+sum*p%mod)%mod;
		}
		return;
	}
	for(LL i=0;i<=res;i++){
		size[x]=i;
		dfs(x+1,res-i);
	}
}
LL a[N];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k); f[0]=1;
	for(LL i=0;i<=m;i++) scanf("%lld",&v[i]);
	for(LL i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
	dfs(0,n);
	printf("%lld",ans);
	return 0;
}
/*
*/
