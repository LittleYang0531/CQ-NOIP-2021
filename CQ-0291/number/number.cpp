#include <bits/stdc++.h>

using namespace std;

int t, x;
int ans[10000002];
bool mark[10000002];
string ANS;

bool check(int n) {
	while (n) {
		if (n % 10 == 7) return true;
		n /= 10;
	}
	return false;
}

string STR (int n) {
	string s = "";
	while (n) {
		s = char(n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= 10000001; i ++)
		if (!mark[i] && check(i))
			for (int j = 1; i * j <= 10000001; j ++)
				mark[i * j] = true;
	for (int i = 1, j = 0; i <= 10000001; i ++) {
		if (mark[i] && !j) j = i;
		else if (!mark[i] && j) {
			for (int k = j; k < i; k ++) ans[k] = i;
			j = 0;
		}
	}
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &x);
		if (mark[x]) ANS += "-1\n";
		else if (mark[x + 1]) ANS += STR(ans[x + 1]) + "\n";
		else ANS += STR(x + 1) + "\n";
	}
	cout << ANS;
	return 0;
}
