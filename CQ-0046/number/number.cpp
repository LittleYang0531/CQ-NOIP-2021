#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define mid ((l+r)>>1)
using namespace std;
//bool happy1041; ll time1=clock();
//
const ll N=3e7,MT=1e7;
bool vis[N+10];
ll que[MT+10],ans[N+10];
ll mmax=0;
//
void dfs2(ll dep,ll dnum,ll bj,ll num){
//	printf("%lld:\n",num);
	if(dnum>mmax){
		if(vis[num]||num>mmax) return;
		for(ll i=num; i<=mmax; i+=num){
//			if(num>=1e6) printf("%lld\n",i);
			vis[i]=1;
		}
		return;
	}
	if(dep<bj){
		FOR(i,0,9){
			if(i==7) continue;
			dfs2(dep+1,dnum*10,bj,num+i*dnum);
		}
	}
	else if(dep==bj) dfs2(dep+1,dnum*10,bj,num+7*dnum);
	else{
		FOR(i,0,9){
			dfs2(dep+1,dnum*10,bj,num+i*dnum);
		}
	}
}
void dfs(ll dep,ll dnum){
	if(dnum>mmax) return;
	dfs2(1,1,dep,0);
	dfs(dep+1,dnum*10);
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
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ll T=gt();
	FOR(i,1,T){
		que[i]=gt();
		mmax=max(que[i],mmax);
	}
	ll ababa=1e7+5;
	mmax=min(ababa,mmax*2+10000);
	dfs(1,1);
	ll to=0;
	ROF(i,mmax,1){
		if(!vis[i]) to=i;
		ans[i]=to;
	}
	ll mmax1=0,mto=0;
	FOR(i,1,T){
		if(vis[que[i]]){
			putchar('-'); wr(1); puts("");
		}
		else{
			wr(ans[que[i]+1]); puts("");
		}
	}
	return 0;
}


