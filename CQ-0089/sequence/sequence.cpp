#include<iostream>
#include<stdio.h>
#define ll long long
using namespace std;
const ll M=200,N=50,p=998244353;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;(ch>'9'||ch<'0');ch=getchar()) if(ch=='-') f=-1;
	for(;(ch>='0'&&ch<='9');ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
ll n,m,k;
long long ans;
long double fl;
ll v[M];
ll qc[M];
ll qu[M*M],l;
inline long long calc(){
	long long ac=1;
	for(ll i=0;i<=m;++i){
		for(ll t=qc[i];t>1;--t){
			qu[++l]=t;
		}
	}
	for(ll i=n;i>0;--i){
		ac*=i;
		if(qu[l]!=0){
			while(ac%qu[l]==0){
				ac/=qu[l];
				--l;
				if(l==0) break;
			}
		}
	}
	return ac;
}
inline long long pwo(long long sse,long long ti){
	if(ti==0) return 0;
	long long ret=1;
	while(ti){
		if(ti&1) ret=(ret*sse)%p;
		ti>>=1;
		sse=(sse*sse)%p;
	}
	return ret;
}
inline ll check(){
	ll cnt=0;
	ll oo=fl;
	if(oo<n||(double)(oo/n)>pwo(2,m)) {
		return 0;
	}
	while(oo){
		if(oo&1) ++cnt;
		oo>>=1;
		if(cnt>k) return 0;
	}
	return 1;
}
inline long long ppc(){
	long long ac=1;
	for(ll i=0;i<=m;++i){
		ac=(ac*pwo(v[i],qc[i]))%p;
	}
	return ac;
}
inline void dfs(ll now,ll ab){
	if(ab==0){
		if(check()){
			ans=(ans+(calc()%p)*ppc()%p)%p;
		}
		return;
	}
	if(now>m) return;
	for(ll i=0;i<=ab;++i){
		qc[now]=i;
		fl=fl+(i<<now);
		dfs(now+1,ab-i);
		fl=fl-(i<<now);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=0;i<=m;++i) v[i]=read();
	dfs(0,n);
	printf("%lld",ans);
	return 0;
}
