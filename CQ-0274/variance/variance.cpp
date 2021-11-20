#include<bits/stdc++.h>
#define int long long
#define N ((int)1e5+2)
#define INF ((int)1e18+2)
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1),s+=(ch-'0'),ch=getchar();
	return s*t;
}
inline void freo(){freopen("variance.in","r",stdin),freopen("variance.out","w",stdout);}
int n,a[N];
inline int gcd(int a,int b){return ((b)?gcd(b,a%b):a);}
struct Frac{
	int fr,sc;
	inline void pre(int x,int y){fr=x,sc=y;}
	Frac operator + (const Frac x) const{
		int lcm=x.sc*sc/gcd(x.sc,sc);
		return (Frac){fr*(lcm/sc)+x.fr*(lcm/x.sc),lcm};
	}
	Frac operator - (const Frac x) const{
		int lcm=x.sc*sc/gcd(x.sc,sc);
		return (Frac){fr*(lcm/sc)-x.fr*(lcm/x.sc),lcm};
	}
	Frac operator * (const Frac x) const{
		return (Frac){fr*x.fr,sc*x.sc};
	}
	inline int change(){return fr/sc;}
};
inline int calc(){
	int sum=0;
	for(int i=1;i<=n;++i) sum+=a[i];
	Frac s,ans;
	s.pre(sum,n),ans.pre(0,1);
	for(int i=1;i<=n;++i) ans=ans+((Frac){a[i],1}-s)*((Frac){a[i],1}-s);
	ans=ans*(Frac){1,n};
	ans=ans*(Frac){n*n,1};
	return ans.change();
}
int ans=INF,tim;
inline void dfs(){
	int now=calc();
	ans=min(ans,now);
	for(int i=2;i<n;++i){
		int tmp=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		if(a[i]==tmp) continue;
		if(calc()<=now) dfs();
		a[i]=tmp;
	}
}
inline void solve(){
	for(int i=1;i<=n;++i) a[i]=i;
	cout<<calc()<<'\n';
	exit(0);
}
signed main(){
	freo();
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	if(n>=20) solve();
	dfs();
	cout<<ans<<'\n';
return 0;
}
