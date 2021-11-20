#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 1000000007
#define ll long long
#define N 200005
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char _st;
int n,a[N];
const double T = 1e14,T0 = 1,dlt = 0.997;
int random(int n){return rand()%n;}
ll minn = 1ll<<60;
void SA() {
	ll ans = 0,sum = 0;
	for(int i=1; i<=n; ++i)sum += a[i];
	for(int i=1; i<=n; ++i)ans += a[i]*a[i];
	ans = n*ans-sum*sum;
	double t = T;
	while(t > T0) {
		minn = min(minn,ans);
		int p = random(n-2)+2,x = a[p-1]+a[p+1]-a[p];
		ll res = ans-n*a[p]*a[p]+n*x*x+sum*sum-(sum-a[p]+x)*(sum-a[p]+x);
		ll delta = res-ans;
		if(delta <= 0)ans = res,sum = sum-a[p]+x,a[p] = x;
		else if(exp(-delta/t)*RAND_MAX > rand())ans = res,sum = sum-a[p]+x,a[p] = x;
		t *= dlt;
	}
}
ll Calc() {
	ll res = 0,sum = 0;
	for(int i=1; i<=n; ++i)sum += a[i];
	for(int i=1; i<=n; ++i)res += a[i]*a[i];
	return n*res-sum*sum;
}
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	file("variance");
	srand(time(0));
	read(n);
	for(int i=1; i<=n; ++i)read(a[i]);
	if(n == 2)cout << Calc()<< '\n',exit(0);
	for(int i=1; i<=500; ++i)SA();
	cout << minn << '\n';
}
