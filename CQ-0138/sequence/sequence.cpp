#include <bits/stdc++.h>

using namespace std;

int n, m, k, v[105] = {0};

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i <= m; i++) {
		scanf("%d", v + i);
	}
	int res = pow(v[0], 2) * pow(v[1], (n - 2));
	printf("%d\n", res);
	return 0;
}

