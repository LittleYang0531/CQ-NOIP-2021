#include<bits/stdc++.h>
#define ll long long
#define Re register
using namespace std;

const int N = 10005;

int n;
ll a[N], sum = 0;

inline ll Min(ll A,ll B){
	if(A < B) return A;
	return B;
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	srand( time(NULL) );
	
	scanf("%d",&n);
	
	for(Re int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	
	ll ans = 0, pt1 = a[1] * a[1] + a[n] * a[n];
	sum = a[1] + a[n];
	for(Re int i=2;i<n;++i){
		if(a[i] - (a[i-1]+a[i+1])/2 > (a[i-1]+a[i+1]-a[i]) - (a[i-1]+a[i+1])/2 )
			a[i] = a[i-1] + a[i+1] - a[i];
		pt1 += a[i] * a[i];
		sum += a[i];
	}
	ans = pt1 * n - sum * sum;
	
	int tmp = CLOCKS_PER_SEC;
	while( 1.0 * clock() / tmp < 0.9 ){
		int t = rand() % (n-2) + 2;
		pt1 -= a[t] * a[t]; sum -= a[t];
		a[t] = a[t+1] + a[t-1] - a[t];
		pt1 += a[t] * a[t]; sum += a[t];
		ans = Min(ans , pt1 * n - sum * sum);
	}
	
	printf("%lld",ans);
	
	return 0;
}
