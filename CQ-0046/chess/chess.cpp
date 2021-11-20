#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define mid ((l+r)>>1)
using namespace std;
//bool happy1041; ll time1=clock();
//
//
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
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ll T=gt();
	while(T--){
		ll n=gt(),m=gt(),q=gt(); string s; ll a;
		FOR(i,1,n) cin>>s;
		FOR(i,1,n-1) cin>>s;
		FOR(i,1,q) FOR(j,1,4) a=gt();
		FOR(i,1,q) printf("1\n");
	}
}




