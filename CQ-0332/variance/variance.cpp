#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=10005;
inline int read(int &x){
	int s=0, f=1; char c=getchar();
	while(c < '0' || c > '9'){ if(c == '-') f=-1; c=getchar(); }
	while(c >= '0' && c <= '9') s=(s<<3)+(s<<1)+c-'0', c=getchar(); x=s*f;
}
int n, a[MAX];
double e = 0.988654212, D = 1e-6;
struct ouo{
	int a, b;
}ans;
ouo qwq(){
	int sum=0, b=0;
	for(int i = 1; i <= n; ++i) sum+=a[i], b+=a[i]*a[i];
	return (ouo) {sum, b};
}
void SA(){
	srand(rand());
	srand(rand());
	srand(rand());
	double T=100000.0;
	ouo c=ans;
	while(T > D){
		int x=rand()%n+1;
		if(x == 1 || x == n) continue;
		int QAQ = a[x];
		a[x]=a[x+1]+a[x-1]-a[x];
		ouo d=qwq();
//		cout<<(d.b*n-d.a*d.a)<<":\n";
//		for(int i = 1; i <= n; ++i)
//			cout<<a[i]<<" ";
//			cout<<"\n";
		if((d.b*n-d.a*d.a) <= (c.b*n-c.a*c.a)){
			c = d;
			if((c.b*n-c.a*c.a) <= (ans.b*n-ans.a*ans.a))
				ans = c;
		}
		else{
//			cout<<exp(((c.b*n-c.a*c.a)-(d.b*n-d.a*d.a))*1.0/(c.b*n-c.a*c.a))<<"\n";
			if(exp(((c.b*n-c.a*c.a)-(d.b*n-d.a*d.a))*1.0/(c.b*n-c.a*c.a)) < rand()*1.0/RAND_MAX)
				c=d;
			else a[x]=QAQ;
		}
		T*=e;
	}
}
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(rand()*rand());
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	ans = qwq();
//	cout<<(ans.b*n-ans.a*ans.a)<<"\n";
	for(int i = 1; i <= 80; ++i) SA();
	cout<<(ans.b*n-ans.a*ans.a)<<"\n";
	return 0;
}
