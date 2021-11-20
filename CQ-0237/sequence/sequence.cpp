#include <cstdio>
#define ll long long
using namespace std;
const ll mod=998244353;
inline ll read(){
	ll x=0;
	char p=getchar();
	while (p<'0'||p>'9')p=getchar();
	while(p>='0'&&p<='9')x=(x<<3)+(x<<1)+(p^48),p=getchar();
	return x;
}
inline void print(ll x){
	if (x>9)print(x/10);
	putchar(x%10+'0');
}
ll n,m,k,v[101],a[101],ans,f[31];
inline bool jz1(){
	int an=0,sy=0;
	for (ll i=0;i<=m;i++){
		sy+=a[i];
		an+=sy&1;
		sy>>=1;
	}
	while (sy)an+=sy&1,sy>>=1;
	return an>k;
}
inline ll q_pow(ll q,ll b){
	ll ret=1;
	for (;b;q=q*q%mod,b>>=1)if (b&1)ret=ret*q%mod;
	return (ret+mod)%mod;
}
inline ll jg(){
	ll an=1;
	for (ll i=0;i<=m;i++){
		an=an*q_pow(v[i],a[i])%mod;
	}
	return an;
}
inline ll inv(ll x){
	return !x?1:q_pow(x,mod-2);
}
inline ll c(ll q,ll b){
	return !q?1:f[b]*inv(f[b-q])%mod*inv(f[q])%mod;
}
inline ll cs(){
	ll an=1;
	for (ll i=1,last=n;i<=m;i++){
		an=an*c(a[i],last)%mod,last=n-a[i];
	}
	return an;
}
inline void ss(ll las,ll dep){
	if (dep==m){
		a[dep]=las;
		if (jz1()){a[dep]=0;return;}
		ans=(ans+jg()*cs())%mod;
		a[dep]=0;
		return;
	}
	for (ll i=0;i<=las;i++){
		a[dep]=i;
		ss(las-i,dep+1);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	f[1]=1;
	for (ll i=0;i<=m;i++)v[i]=read();
	for (ll i=2;i<=n*2;i++)f[i]=f[i-1]*i%mod;
	ss(n,0);
	print(ans);
	return 0;
}
