#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110000] , ans , b[110000];
long long pfh()
{
	long long ans = 0;
	for(int i = 1 ; i <= n ; i++ ) ans += a[i] * a[i];
	return ans;
}
int main()
{
	freopen("variance.in" , "r" , stdin);
	freopen("variance.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &a[i]) , b[i] = a[i];
	if(n == 1)
	{
		printf("0");
		return 0;
	}
	if(n == 2)
	{
		long long s = (a[1] + a[2]);
		printf("%lld" , pfh() * n - s * s);
		return 0;
	}
	if(n == 3)
	{
		long long s = (a[1] + a[2] + a[3]);
		ans = pfh() * n - s * s;
		a[2] = a[1] + a[3] - a[2];
		s = (a[1] + a[2] + a[3]);
		ans = min(ans , pfh() * n - s * s);
		cout << ans;
		return 0;
	}
	if(n == 4)
	{
		long long s = (a[1] + a[2] + a[3] + a[4]);
		ans = pfh() * n - s * s;
		
		memcpy(a , b , sizeof(a));
		a[2] = b[1] + b[3] - b[2];
		s = (a[1] + a[2] + a[3] + a[4]);
		ans = min(ans , pfh() * n - s * s);
		
		memcpy(a , b , sizeof(a));
		a[3] = b[2] + b[4] - b[3];
		s = (a[1] + a[2] + a[3] + a[4]);
		ans = min(ans , pfh() * n - s * s);
		
		memcpy(a , b , sizeof(a));
		a[2] = b[1] + b[3] - b[2];
		a[3] = b[2] + b[4] - b[3];
		s = (a[1] + a[2] + a[3] + a[4]);
		ans = min(ans , pfh() * n - s * s);
		
		memcpy(a , b , sizeof(a));
		a[2] = b[1] + b[3] - b[2];
		a[3] = b[1] + b[4] - b[2];
		s = (a[1] + a[2] + a[3] + a[4]);
		ans = min(ans , pfh() * n - s * s);
		
		memcpy(a , b , sizeof(a));
		a[2] = b[1] + b[4] - b[3];
		a[3] = b[1] + b[4] - b[2];
		s = (a[1] + a[2] + a[3] + a[4]);
		ans = min(ans , pfh() * n - s * s);
		cout << ans;
		return 0;
	}
	long long s = 0;
	for(int i = 1 ; i <= n ; i++ ) s += a[i];
	printf("%lld" , pfh() * n - s * s);
	return 0;
}
/*
Goodbye, NOI2022.
Ô¸¶Ä·þÊä. 
*/
