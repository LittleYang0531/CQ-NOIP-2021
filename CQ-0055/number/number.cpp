#include <bits/stdc++.h>



using namespace std;
const int N = 1e7 + 10;
const int M = 2e5 + 10;
int n,m;
int p[N],cnt = 0;
int ex[N],tot = 0;
int fi[N],num = 0;
int ava[N],num1 = 0;
int vis[N];
struct qu {
	int x,pos;
	bool operator < (const qu &X) const {
		return x < X.x;
	}
}a[M];
int ans[M];
inline void Pre() {
	for(int i = 1;i <= N - 10;i++) {
		int s = i;
		while(s) {
			if(s % 10 == 7) p[++cnt] = i,vis[i] = true;
			s /= 10;
		}
	}
	for(int i = 2;i <= N - 10;i++) {
		if(vis[i]) ex[++tot] = i;
		for(int j = 1;j <= cnt && 1ll * p[j] * i <=  N - 10;j++) {
			vis[p[j] * i] = true;
			if(i % p[j] == 0) break;
		}
	}
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Pre();
	int times;
	cin >> times;
	for(int t = 1;t <= times;t++) {
		cin >> a[t].x;
		a[t].pos = t;
	}
	sort(a + 1,a + times + 1);
	memset(vis,0,sizeof vis);
	int poi1 = 1,poi2 = 1;
	while(poi1 <= cnt || poi2 <= tot) {
		if(poi1 > cnt) {
			if(vis[ex[poi2]]) {
				poi2++;
				continue;
			} 
			fi[++num] = ex[poi2++];
		} else if(poi2 > tot) {
			if(vis[p[poi1]]) {
				poi1++;
				continue;
			} 
			fi[++num] = p[poi1++];
		} else {
			if(p[poi1] < ex[poi2]) {
				if(vis[p[poi1]]) {
					poi1++;
					continue;
				}
				fi[++num] = p[poi1++];
			} else {
				if(vis[ex[poi2]]) {
					poi2++;
					continue;
				}
				fi[++num] = ex[poi2++];
			}
		}
		vis[fi[num]] = true;
	}
	int j = 1;
	for(int i = 1;i <= num;i++) {
		for(;j < fi[i];j++) ava[++num1] = j;
		j = fi[i] + 1;
	}
	for(;j <= N - 10;j++) ava[++num1] = j;
	ava[++num1] = 10000001;
	int poi = 1; poi1 = 1;
	for(int i = 1;i <= times;i++) {
		while(fi[poi] < a[i].x && poi <= num) poi++;
		while(ava[poi1] < a[i].x && poi1 <= num1) poi1++;
		if(fi[poi] == a[i].x) ans[a[i].pos] = -1;
		else ans[a[i].pos] = ava[poi1 + 1];
	}
	for(int i = 1;i <= times;i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
