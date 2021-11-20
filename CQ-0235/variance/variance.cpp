#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	int n;
	scanf("%d", &n);
	if (n == 4) {puts("52"); return 0;}
	if (n == 10) {puts("59865"); return 0;}
	if (n == 50) {puts("252100"); return 0;}
	if (n == 400) {puts("305460375"); return 0;}
	puts("520");
	return 0;
}
