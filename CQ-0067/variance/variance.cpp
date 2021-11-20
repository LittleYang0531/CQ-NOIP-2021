/*
Lucky_Yukakaze, Shigure, Shokaku and Hibiki will bring luck to me.
*/

#include <bitset>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

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

int n;
LL Answer = 1ll << 60;
LL Value[Maxn];

inline void Clac () {
	LL Sum1 = 0, Sum2 = 0;
	
	for (int i = 1; i <= n; ++ i ) {
		Sum1 += n * Value[i] * Value[i];
		Sum2 += Value[i];
//		printf ("%lld ", Value[i]);
	}
	
//	putchar ('\n');
	
	Answer = min (Answer, Sum1 - Sum2 * Sum2);
	return ;
}

signed main () {
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	
	n = Read ();
	
	for (int i = 1; i <= n; ++ i ) {
		Value[i] = Read ();
	}
	
	if (n == 4 ) {
		for (int i = 1; i <= 3; ++ i ) {
			Value[2] = Value[1] + Value[3] - Value[2], Clac ();
			Value[3] = Value[2] + Value[4] - Value[3], Clac ();
		}
		
		for (int i = 1; i <= 3; ++ i ) {
			Value[3] = Value[2] + Value[4] - Value[3], Clac ();
			Value[2] = Value[1] + Value[3] - Value[2], Clac ();
		}
		
		Write (Answer);
	}
	
	Clac ();
	Write (Answer);
	return 0;
}

/*
吾以 Shigure 之名，衷心祝福 CCF  
*/
