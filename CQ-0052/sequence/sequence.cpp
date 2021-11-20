#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10, M = 1e2 + 10, MOD = 998244353;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
struct node{
	int val, num, a[M];
}g[M][N];
struct BIT{
	int v; //ʣ���û��ʹ�õ� 1 ������ 
	int sum; //Ȩֵ 
	int b;
	int a[M];
}sck[2][N];
int tem[M];
int n, m, k, cnt[M], mx, ans, top[2];
int v[M], w[M], fac[M*M];
inline int power(int x, int k)
{
	int res = 1;
	while(k){
		if(k & 1) res = res * x % MOD;
		k >>= 1, x = x * x % MOD;
	}
	return res;
}
inline void DFS(int p, int x, int y, int z, int rt) //Ŀǰ�ڶ������е�λ�ã���ǰλ����Ҫ���ٸ�Ԫ�أ��Ѿ����˶��ٸ�Ԫ�أ��� 
{
//	cout << p << " " << x << " " << y << " " << z << "\n";
	if(x + y > n) return;
	if(p <= m && p <= m){
		tem[p] += x;
		g[rt][++cnt[rt]].val = z * power(v[p], x) % MOD;
		g[rt][cnt[rt]].num = x + y; //ֱ��ѡ��
		for(register int i = 0; i <= m; i++) g[rt][cnt[rt]].a[i] = tem[i];
		tem[p] -= x;
	}
	if(!p) return;
	if(p > m) DFS(p - 1, 2 * x, y, z, rt);
	else{
		for(register int i = 0; i < x; i++){ //ö�ٵ�ǰλ��ѡ����ٸ�ֵ
			tem[p] += i;
			DFS(p - 1, 2 * (x - i), y + i, z * power(v[p], i) % MOD, rt);
			tem[p] -= i;
		}
	}
}
signed main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), m = read(), k = read();
	fac[0] = 1;
	for(register int i = 1; i <= n; i++) fac[i] = fac[i-1] * i % MOD;
	for(register int i = 0; i <= m; i++) v[i] = read();
	for(register int i = 0; ; i++){
		memset(tem, 0, sizeof(tem));
		DFS(i, 1, 0, 1, i);
		if(!cnt[i]) break;
	//	cerr << cnt[i] << "\n";
		mx = i;
	}
	if(k == 1){
		for(register int i = 0; i <= mx; i++){
			for(register int j = 1; j <= cnt[i]; j++){
				if(g[i][j].num == n){
					int res = g[i][j].val * fac[n] % MOD, inc = 1;
					for(register int t = 0; t <= m; t++)
						inc = inc * fac[g[i][j].a[t]] % MOD;
					if(inc != fac[n]) res = res * power(inc, MOD - 2) % MOD; 
					ans = (ans + res) % MOD;
				}
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
//	cout << mx << "\n";
	w[0] = 1;
	for(register int i = 1; i <= mx; i++) w[i] = w[i-1] * 2;
	int opt = 1;
	sck[0][++top[0]].v = n, sck[0][top[0]].b = 0, sck[0][top[0]].sum = 1;
	for(register int i = 1; i <= k; i++){
		for(register int j = 1; j <= top[opt ^ 1]; j++){
			if(!sck[opt ^ 1][j].v) continue;
			for(register int t = 0; t <= mx; t++){ //ö�� 1 ��λ��
				if(sck[opt ^ 1][j].b & w[t]) continue; //���λ������1
				//û��1������ֱ�ӽ��в���
				for(register int x = 1; x <= cnt[t]; x++){
					if(sck[opt ^ 1][j].v < g[t][x].num) continue; //ʣ�µ�λ�ò�������
					BIT to = sck[opt ^ 1][j];
					to.b |= w[t], to.v -= g[t][x].num, to.sum = to.sum * g[t][x].val % MOD;
					for(register int y = 0; y <= m; y++) to.a[y] += g[t][x].a[y];
					sck[opt][++top[opt]] = to; //���� 
				}
			}
		}
		//cerr << k << "\n";
		for(register int j = 1; j <= top[opt]; j++){
			if(!sck[opt][j].v){
				int res = sck[opt][j].sum * fac[n] % MOD, inc = 1;
				for(register int t = 0; t <= m; t++)
					inc = inc * fac[sck[opt][j].a[t]] % MOD;
				if(inc != fac[n]) res = res * power(inc, MOD - 2) % MOD; 
				ans = (ans + res) % MOD;
			}
		}
		opt ^= 1;
	}
	printf("%lld\n", ans);
	return 0;
}
