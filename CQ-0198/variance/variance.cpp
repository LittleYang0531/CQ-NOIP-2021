#include<bits/stdc++.h>
#include<set>
using namespace std;
#define ll long long
#define il inline

ll min(ll a, ll b){
	return a<b?a:b;
}
il void read(int &x) {
	x=0;
	int f=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=-1;
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	c*=f;
}
il void write(ll x) {
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int a[10005];
set<string> se;
ll ANS=INT_MAX;
int n;
void tos(int x, string &k) {
	if(x>=10) tos(x/10, k);
	k=k+char(x%10+'0');
}
void js(){
	int pj=0;
	ll ans=0;
	for(int i=1; i<=n; ++i){
		pj+=a[i];
	}
	for(int i=1; i<=n; ++i){
		ans+=(a[i]*n-pj)*(a[i]*n-pj);
	}
	ANS=min(ANS, ans/n);
//	cout << ans/n << " ";
}
bool ins() {
	string k="";
	for(int i=2; i<n; ++i) {
		tos(a[i], k);
		if(i!=n-1) k=k+'-';
	}
//	for(int i=1; i<=n; ++i) cout << a[i] << " ";
//	if(se.size()%10000==0)cout << k << endl;
	int len=se.size();
	se.insert(k);
	if(se.size()==len) return 0;
	return 1;
}
void dfs() {
	for(int i=2; i<n; ++i) {
		if(a[i]!=a[i-1]+a[i+1]-a[i]) {
			a[i]=a[i-1]+a[i+1]-a[i];
			if(ins()){
				js();
				dfs();
			} 
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);

	read(n);
	for(int i=1; i<=n; ++i) {
		read(a[i]);
	}
	ins();
	js();
	dfs();
	printf("%lld\n", ANS);
	return 0;
}
