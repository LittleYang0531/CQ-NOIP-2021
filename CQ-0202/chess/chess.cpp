#include <bits/stdc++.h>

using namespace std;



vector <vector <char> > vh, vz, emp1;
vector <char> ln, emp2;
vector <vector <int> > vi;
int T, n, m, p, a[200007], x, y, col, lv, ans;
int b[200007];

void solve(int x, int y, int w, int f) {
	if (a[(x - 1) * m + y] != 0) {
		if ((lv < 0 && a[(x - 1) * m + y] < 0) || ((lv > 0 && a[(x - 1) * m + y] > 0)) || (lv < 0 && a[(x - 1) * m + y] > 0 && a[(x - 1) * m + y] > abs(lv)) || (lv > 0 && a[(x - 1) * m + y] < 0 && abs(a[(x - 1) * m + y]) > lv))
			return;
		else {
			b[(x - 1) * m + y] = true;
			return;
		}
	}
	f -= '0';
	if (f == 3)
		b[(x - 1) * m + y] = 3;
	else
		b[(x - 1) * m + y] = 1;
	if (f == 4) {
		if (vz[x - 1][y] != '0')
			solve(x - 1, y, 1, vz[x - 1][y]);
			
		if (vz[x][y] != '0')
			solve(x + 1, y, 2, vz[x][y]);
			
		if (vh[x][y - 1] != '0')
			solve(x, y - 1, 3, vh[x][y - 1]);
			
		if (vh[x][y] != '0')
			solve(x, y + 1, 4, vh[x][y]);
			
	}
	if (f == 2) {
		if (w == 1)
			if (vz[x - 1][y] == '2') {
				solve(x - 1, y, 1, '2');
			}
		if (w == 2)
			if (vz[x][y] == '2') {
				solve(x + 1, y, 2, '2');
			}
		if (w == 3)
			if (vh[x][y - 1] == '2') {
				solve(x, y - 1, 3, '2');
			}
		if (w == 4)
			if (vh[x][y] == '2') {
				solve(x, y + 1, 4, '2');
			}
	}
	if (f == 1 || f == 0) {
		return;
	}
	if (f == 3) {
		if (vz[x - 1][y] == '3' && w != 2 && b[(x - 1 - 1) * m + y] != 3)
			solve(x - 1, y, 1, '3');
		if (vz[x][y] == '3' && w != 1 && b[(x + 1 - 1) * m + y] != 3)
			solve(x + 1, y, 2, '3');
		if (vh[x][y - 1] == '3' && w != 4 && b[(x - 1) * m + y - 1] != 3)
			solve(x, y - 1, 3, '3');
		if (vh[x][y] == '3' && w != 3 && b[(x - 1) * m + y + 1] != 3)
			solve(x, y + 1, 4, '3');
	}
}




int main () {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d\n", &n, &m, &p);
		for (register int i = 0; i <= m + 2; i ++) {
			ln.push_back('0');
		}
		vh.push_back(ln);
		for (register int i = 1; i <= n; i ++) {
			vh.push_back(ln);
			for (register int j = 1; j < m; j ++) {
				vh[i][j] = getchar();
			}
			getchar();
		}
		vh.push_back(ln);
		vz.push_back(ln);
		for (register int i = 1; i < n; i ++) {
			vz.push_back(ln);
			for (register int j = 1; j <= m; j ++) {
				vz[i][j] = getchar();
			}
			getchar();
		}
		vz.push_back(ln);
		for (register int i = 1; i <= p; i ++) {
			scanf("%d%d%d%d", &col, &lv, &x, &y);
			if (col == 0)
				lv = -lv;
			solve(x, y, 0, '4');
			a[(x - 1) * m + y] = lv;
			b[(x - 1) * m + y] = false;
			for (register int i = 1; i <= n * m; i ++) {
				ans += (b[i] > 0);
				b[i] = 0;
			}
			printf("%d\n", ans);
			ans = 0;
		}
		
		memset(a, 0, sizeof(a));
		vh = vz = emp1;
		ln = emp2;
	}
	return 0;
}
