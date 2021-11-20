#include<bits/stdc++.h>
#define ll long long
#define getchar gc
using namespace std;
const int Mxdt=1e5;
inline char gc() {
	static char buf[Mxdt+5],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}

inline int Rd() {
	int s=0; char fl=0,c=getchar();
	while(c<'0'||c>'9') fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s;
}

const int N=1e4+5,M=605;
int n,mx,a[N],c[N],lbot[M],rbot[M];

inline ll Getans() {
	int val=a[1]; ll sum1=a[1],sum2=1ll*a[1]*a[1];
//	b[1]=a[1]; int num=1;
	for(int i=mx; ~i; --i) {
		for(int j=1; j<=lbot[i]; ++j) {
			val+=i;// b[++num]=val;
			sum1+=val;
			sum2+=1ll*val*val;
		}
	}
	for(int i=0; i<=mx; ++i) {
		for(int j=1; j<=rbot[i]; ++j) {
			val+=i;// b[++num]=val;
			sum1+=val;
			sum2+=1ll*val*val;
		}
	}
//	int ave=0; ll sum=0;
//	for(int i=1; i<=n; ++i) ave+=b[i];
//	for(int i=1; i<=n; ++i) sum+=(1ll*n*b[i]-ave)*(1ll*n*b[i]-ave);
//	sum/=n;
//	return sum;
//	puts("");
//	cout<<sum1<<' '<<sum2<<'\n';
	return sum2*n-sum1*sum1;
}

int main() {
//	system("fc variance.out variance3.ans");
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=Rd();
	for(int i=1; i<=n; ++i) a[i]=Rd(); mx=a[n]-a[1];
	for(int i=1; i<n; ++i) c[i]=a[i+1]-a[i],++rbot[c[i]];//,cout<<c[i]<<' '; puts("");
	
	ll ans=Getans();
	for(int mid=1; mid<n; ++mid) {
		--rbot[c[mid]],++lbot[c[mid]];
		ans=min(ans,Getans());
	}
	printf("%lld\n",ans);
	return 0;
}


