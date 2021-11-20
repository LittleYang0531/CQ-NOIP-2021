//CJG生日快乐
//CJG一战成冥
//CJGYYDS 
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 10000100

void read (int &n) {
	n = 0;
	
	char c = getchar ();
	bool bl = 0;
	
	while (c < '0' || c > '9') {
		if (c == '-') {
			bl = 1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar ();
	}
	n = bl ? -n : n;
}
bool vis[MAXN + 5];
int s[MAXN + 5];
bool vis2[MAXN + 5];
int tot;
int snxt[MAXN + 5];

int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	
	int x = 0;
	
	for (int i1 = 0; i1 <= 9; i1 ++) {
		x |= ((i1 == 7) << 0);
		x &= (((1 << 7) - 1) - ((i1 != 7) << 0));
		for (int i2 = 0; i2 <= 9; i2 ++) {
			x |= ((i2 == 7) << 1);
			x &= (((1 << 7) - 1) - ((i2 != 7) << 1));
			for (int i3 = 0; i3 <= 9; i3 ++) {
				x |= ((i3 == 7) << 2);
				x &= (((1 << 7) - 1) - ((i3 != 7) << 2));
				for (int i4 = 0; i4 <= 9; i4 ++) {
					x |= ((i4 == 7) << 3);
					x &= (((1 << 7) - 1) - ((i4 != 7) << 3));
					for (int i5 = 0; i5 <= 9; i5 ++) {
						x |= ((i5 == 7) << 4);
						x &= (((1 << 7) - 1) - ((i5 != 7) << 4));
						for (int i6 = 0; i6 <= 9; i6 ++) {
							x |= ((i6 == 7) << 5);
							x &= (((1 << 7) - 1) - ((i6 != 7) << 5));
							for (int i7 = 0; i7 <= 9; i7 ++) {
								x |= ((i7 == 7) << 6);
								x &= (((1 << 7) - 1) - ((i7 != 7) << 6));
								if (x) {
									vis[i7 + i6 * 10 + i5 * 100 + i4 * 1000 + i3 * 10000 + i2 * 100000 + i1 * 1000000] = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	vis2[1] = 1;
	for (int i = 2; i <= MAXN; i ++) {
		if (!vis2[i]) {
			s[++tot] = i;
		}
		for (int j = 1; j <= tot && MAXN / i >= s[j]; j ++) {
			vis2[s[j] * i] = 1;
			if (i % s[j] == 0) {
				break;
			}
		}
	}
	for (int i = 1; i <= MAXN; i ++) {
		if (vis[i]) {
			for (int j = 1; j <= tot && MAXN / i >= s[j]; j ++) {
				vis[i * s[j]] = 1;
			}
		}
	}
	for (int i = 1; i <= MAXN; i ++) {
		if (vis[i]) {
			continue;
		}
		for (int j = i + 1; j <= MAXN; j ++) {
			if (vis[j] == 0) {
				snxt[i] = j;
				i = j - 1;
				
				break;
			}
		}
	}
	
	int t;
	
	read (t);
	//scanf ("%d", &t);
	while (t --) {
		int x;
		
		read (x);
		//scanf ("%d", &x);
		if (vis[x]) {
			printf ("-1\n");
			
			continue;
		}
		printf ("%d\n", snxt[x]);
	}
	
	return 0;
} 
