#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define mid ((l+r)>>1)
using namespace std;
//bool happy1041; ll time1=clock();
//
const ll M=100,MOD=998244353;
ll v[M+10],a[M+10];
ll n,m,k,ans=0;
//
void dfs(ll dep){
	if(dep>n){
		bitset<70> b; ll aba=0;
		FOR(i,1,n){
			aba+=(1ll<<a[i]);
		} b=aba;
//		cout<<b<<"\n";
		if(b.count()<=k){
			ll lans=1;
			FOR(i,1,n){
				lans=(lans*v[a[i]])%MOD;
			}
			ans=(ans+lans)%MOD;
		}
		return;
	}
	FOR(i,0,m){
		a[dep]=i;
		dfs(dep+1);
	}
}
//
ll gt(){
	ll k=0,t=1; char c=getchar();
	while(!isdigit(c)) t=(c=='-')?-1:t,c=getchar();
	while(isdigit(c)) k=(k<<1)+(k<<3)+(c^48),c=getchar();
	return k*t;
}
void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
	return;
}
//bool Happy1041;
//void usage(){ ll time2=clock();
//	cout<<(&Happy1041-&happy1041)/1024/1024<<"Mb,"<<time2-time1<<"ms\n";
//}
int main(){
//	usage();
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=gt(),m=gt(),k=gt();
	FOR(i,0,m) v[i]=gt();
	dfs(1);
	printf("%lld",ans);
	return 0;
}




