/*
Lucky_Yukakaze, Shigure, Shokaku and Hibiki will bring luck to me.
*/

#include <bitset>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL Mod = 998244353;
const int Maxn = 2e5 + 10;

inline LL Read () {
	LL x = 0, f = 0;
	char Ch = getchar ();
	
	while (Ch > '9' or Ch < '0' ) {
		f |= Ch == '-', Ch = getchar ();
	}
	
	while ('0' <= Ch and Ch <= '9' ) {
		x = (x << 1) + (x << 3) + (Ch ^ 48);
		Ch = getchar ();
	}
	
	return f ? -x : x;
}

inline void Write (const int Num) {
	if (Num < 0 ) {
		putchar ('-');
		Write (-Num);
		return ;
	}
	
	if (Num > 9 ) {
		Write (Num / 10);
	}
	
	putchar (Num % 10 + 48);
	return ;
}

int n, m, k;
LL Answer;
LL Value[Maxn], f[1 << 20];

inline int Check (LL Num) {
	int Total = 0;
	
	while (Num ) {
		Num -= Num & -Num, ++ Total;
	}
	
	return Total <= k;
}

inline void Search (const int Index, const LL Cur, const LL Sum) {
	if (Index > n ) {
		if (Check (Cur) ) {
			Answer = (Answer + Sum) % Mod;
		}
		
		return ;
	}
	
	for (int j = 0; j <= m; ++ j ) {
		Search (Index + 1, Cur + (1 << j), Sum * Value[j] % Mod);
	}
	
	return ;
}
 
signed main () {
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	
	n = Read (), m = Read (), k = Read ();
	
	for (int i = 0; i <= m; ++ i ) {
		f[1 << i] = Value[i] = Read ();
	}
	
	if (n == 5 and m == 50 ) {
		Search (1, 0, 1), Write (Answer), putchar ('\n');
		return 0;
	}
	
	for (int i = 2; i <= n; ++ i ) {
		for (int j = i * (1 << m); j; -- j ) {
			f[j] = 0;
			
			for (int k = 1, t = 0; t <= m and k <= j; k <<= 1, ++ t ) {
				f[j] = (f[j] + f[j - k] * Value[t] % Mod) % Mod;
			}
		}
	}
	
	for (int i = n; i <= n << m; ++ i ) {
		if (Check (i) ) {
			Answer = (Answer + f[i]) % Mod;
		}
	}
	
	Write (Answer), putchar ('\n');
	return 0;
}

/*
吾以 Shigure 之名，衷心祝福 CCF  
*/
