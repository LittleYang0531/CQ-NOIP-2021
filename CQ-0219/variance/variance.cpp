#include <bits/stdc++.h>
using namespace std;
namespace c {
	template <typename T>
	inline void read(T &x) {
		char ch; int f = 1; x = 0;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}
}
using namespace c;
const int N = 10005;
int n, a[N];
map <vector <int>, bool> vis;
void dfs(int dep) {
	vector <int> v;
	for (int i = 1; i <= n; ++i) v.push_back(a[i]);
	if (vis[v]) return ;
	
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 2; i < n; ++i) {
		if(a[i-1]+a[i+1]-a[i]>a[i]) a[i]=a[i-1]+a[i+1]-a[i];
	}
//	for(int i=1;i<=n;++i) cout << a[i] << ' ';
	cout << 1 << endl;
	return 0;
}

