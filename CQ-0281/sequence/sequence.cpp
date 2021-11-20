// Ц��������һ�ֶ�û�� 
// ���ƺ����������ĵ�����
// ò�������������ĵ�һ�� CTSC ���⣬�̵��ߵ�ʲô����� 
// ֻ��ϧ�������� 

#include <cstdio>
#include <cmath>

const int mod = 998244353, maxn = 105;

int n, m, k, ans, v[maxn], a[maxn];

inline int f(unsigned long long x) {
	int sum = 0;
	while(x) {
		sum += (x & 1);
		x >>= 1;
	}
	return sum;
}

void dfs(int t) {
	if(t == n + 1) {
		unsigned long long q = 0;
		for(int i = 1; i <= n; i++)
			q += (unsigned long long) pow(2, a[i]);
		if(f(q) <= k) {
			unsigned long long u = 1ull;
			for(int i = 1; i <= n; i++)
				u = (u * v[a[i]]) % mod;
			ans = (ans + u) % mod;
		}
		return;
	}
	for(int i = 0; i <= m; i++) {
		a[t] = i;
		dfs(t + 1);
		a[t] = 0;
	}
	return;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i <= m; i++)
		scanf("%d", &v[i]);
	dfs(1);
	printf("%d", ans);
	return 0;
}
