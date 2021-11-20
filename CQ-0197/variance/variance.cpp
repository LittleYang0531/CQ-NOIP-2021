#include <bits/stdc++.h>

typedef long long ll;

const int siz_1 = 1e4 + 10;

int n;
int a[siz_1];
ll sum;

int main () {
	freopen ("variance.in","r",stdin);	
	freopen ("variance.out","w",stdout);
    
    scanf ("%d",&n);
    for (int i = 1;i <= n;++ i) scanf ("%d",a + i),sum += a[i];
    
    ll sum_ = a[1] + a[n];
    for (int i = 2;i < n;++ i) {
		if ((ll) a[i] * n < sum) a[i] = a[i - 1] + a[i + 1] - 1;
		sum_ += a[i];
	}
    
    ll ans = 0;
    for (int i = 1;i <= n;++ i) ans += pow ((ll) n * a[i] - sum_,2);
    
    printf ("%lld",ans / n);
    
	return 0; 
}

