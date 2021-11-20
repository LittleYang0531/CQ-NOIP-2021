/*
Lucky_Yukakaze, Shigure, Shokaku and Hibiki will bring luck to me.
*/

#include <bitset>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int Maxn = 1e7 + 10, Maxm = 1e6 + 10;

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

int T, n, Pos;
bitset <Maxn> Tag;
int Number[Maxm], Count;

inline bool Check (int num) {
	while (num ) {
		if (num % 10 == 7 ) {
			return true;
		}
		
		num /= 10;
	}
	
	return false;
}

inline void Getnum (const int n) {
	for (int i = 1; i <= n; ++ i ) {
		if (Check (i) ) {
			Tag[i] = 1;
		}
		
		if (!Tag[i] ) {
			Number[++ Count] = i;
		}
		
		else {
			for (int j = i * 2; j <= n; j += i ) {
				Tag[j] = 1;
			}
		}
	}
	
	return ;
}

signed main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	
	T = Read (), Getnum (1e7 + 1);
	
	while (T -- ) {
		n = Read ();
		if (Tag[n] ) {
			Write (-1), putchar ('\n');
			continue ;
		}
		
		Pos = lower_bound (Number + 1, Number + Count + 1, n) - Number + 1;
		Write (Number[Pos]), putchar ('\n');
	}
	
	return 0;
}

/*
吾以 Shigure 之名，衷心祝福 CCF  
*/
