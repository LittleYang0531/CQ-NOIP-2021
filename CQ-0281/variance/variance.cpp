// rand()%%%

#include <cstdio>
#include <windows.h>
#include <ctime>

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	srand(time(NULL));
	printf("%d", rand());
	return 0;
}
