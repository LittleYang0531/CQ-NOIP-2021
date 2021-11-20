#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
template<typename F>inline void read(F &n){
	F w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch&15);ch=getchar();}
	n*=w;
}
typedef long long ll;
const int M=105,mo=998244353;
int n,m,K;ll v[M],fac[35],ifac[35],L,R,ans=0;
deque<pair<ll,int> >q;
ll ksm(ll a,int b){
	ll x=1;a%=mo;
	while(b){
		if(b&1)x=x*a%mo;
		a=a*a%mo;b>>=1;
	}
	return x;
}
ll C(int n,int m){
	if(n<m)return 0;
	return fac[n]*ifac[n-m]%mo*ifac[m]%mo;
}
ll lowbit(ll x){return x&(-x);}
ll highbit(ll x){
	for(int i=40;i>=0;--i)
	if((x>>i)&1)return i;
	return -1;
}
int ck(ll x){
	int cnt=0;
	while(x){cnt++;x-=lowbit(x);}
	return cnt;
}
ll solve(int n,ll x,int i){
	if(i>m)return (x!=0||n!=0)?0:1;
	if(n<ck(x))return 0;
	ll y=x&1,res=0;
	for(;y<=x&&y<=n;y+=2)
		res=(res+ksm(v[i],y)*solve(n-y,(x-y)>>1,i+1)%mo*C(n,y))%mo;
	return res;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=30;++i)fac[i]=fac[i-1]*i%mo;
	ifac[30]=ksm(fac[30],mo-2);
	for(int i=29;i>=0;--i)ifac[i]=ifac[i+1]*(i+1)%mo;
	
	read(n);read(m);read(K);L=n;R=n*(1ll<<m);
	for(int i=0;i<=m;++i)read(v[i]);
	while(!q.empty())q.pop_front();
	q.push_front(make_pair(0ll,0));
	pair<ll,int>t,tt;
	while(!q.empty()){
		t=q.front();q.pop_front();
		if(t.se>=K)break;
		for(int i=highbit(t.fi)+1;(1ll<<i)+t.fi<=R;++i)
		if(((t.fi>>i)&1)==0){
			tt.fi=t.fi|(1ll<<i);
			tt.se=t.se+1;
			if(tt.fi>=L)ans=(ans+solve(n,tt.fi,0))%mo;
			q.push_back(tt);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
