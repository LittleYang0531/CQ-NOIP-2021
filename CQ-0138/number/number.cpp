#include <bits/stdc++.h>

using namespace std;

int T;
bool avail[10000000] = {0};
bool avail_i[10000000] = {0};

bool jmark[10000000] = {0};
bool jmark_i[10000000] = {0};

int solve(int r, bool f)
{
	if (!avail_i[r]){
		for (int j = 7; j < 20000; j++) {
			if (!jmark_i[j]) {
				int tmp = j;
				bool res = false;
				while (tmp >= 7) {
					if ((tmp - 7) % 10 == 0) {
						res = true;
						break;
					} else {
						tmp /= 10;
					}
				}
				jmark_i[j] = true;
				jmark[j] = res;
			}
			if (!jmark[j])
				continue;
			if (r % j == 0) {
				avail_i[r] = true;
				avail[r] = false;
				break;
			}
		}
		if (!avail_i[r]) {
			avail_i[r] = true;
			avail[r] = true;
		}
	}
	if (avail[r]) {
		if (f)
			return solve(r + 1, false);
		else
			return r;
	} else {
		if (f)
			return -1;
		else
			return solve(r + 1, false);
	}
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> T;
	int r;
	for (int i = 0; i < T; i++) {
		scanf("%d", &r);
		printf("%d\n", solve(r, true));
	}
	return 0;
}

