#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
//D=n*(a1^2+a2^2+...+an^2)-(a1+a2+...+an)^2
long long n, a[N], b[N], s1, s2, ans1, ans2;
int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)	
	{
		cin >> a[i];
		b[i] = a[i];
		s1 = s2 = s1 + a[i];
	}
	for(int j = 1; j <= n; j++)
		for(int i = 2; i < n; i++)
			if(n * (a[i - 1] + a[i + 1]) * (2 * a[i] - a[i - 1] - a[i + 1]) > (2 * s1 + a[i - 1] + a[i + 1] - 2 * a[i]) * (2 * a[i] - a[i - 1] - a[i + 1]))
			{
				s1 -= a[i];
				a[i] = a[i - 1] + a[i + 1] - a[i];
				s1 += a[i];
			}
	for(int i = 1; i <= n; i++)
		ans1 += a[i] * a[i];
	ans1 = n * ans1 - s1 * s1;
	for(int j = 1; j <= n; j++)
		for(int i = n - 1; i >= 2; i--)
			if(n * (b[i - 1] + b[i + 1]) * (2 * b[i] - b[i - 1] - b[i + 1]) > (2 * s2 + b[i - 1] + b[i + 1] - 2 * b[i]) * (2 * b[i] - b[i - 1] - b[i + 1]))
			{
				s2 -= b[i];
				b[i] = b[i - 1] + b[i + 1] - b[i];
				s2 += b[i];
			}
	for(int i = 1; i <= n; i++)
		ans2 += b[i] * b[i];
	ans2 = n * ans2 - s2 * s2;
	cout << min(ans1, ans2) << endl;
	return 0;
}

