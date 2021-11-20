/*
Lucky_Yukakaze, Shigure, Shokaku and Hibiki will bring luck to me.
*/

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int Maxn = 6e5 + 10;

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

int Head[Maxn], Total = 1;
int To[Maxn << 2], Next[Maxn << 2], Type[Maxn << 2];

inline void Addedge (const int u, const int v, const int Tp) {
	To[++ Total] = v, Type[Total] = Tp, Next[Total] = Head[u], Head[u] = Total;
	To[++ Total] = u, Type[Total] = Tp, Next[Total] = Head[v], Head[v] = Total;
	return ;
}

int Stack[Maxn], Instack[Maxn], Top;

char Str[Maxn];
int T, n, m, q, X, Y, col, lv;
int Used[Maxn][4], Color[Maxn], Level[Maxn];

inline int Encode (const int x, const int y) {
	return (x - 1) * m + y;
}

inline void Decode (const int Num, int &x, int &y) {
	x = (Num - 1) / m + 1, y = (Num - 1) % m + 1;
	return;
}

inline int Getdict (const int X1, const int Y1, const int X2, const int Y2) {
	return (X1 == X2) ? (Y1 < Y2 ? 1 : 2) : (X1 < X2 ? 3 : 4);
}

inline void Search (const int Node, const int Tp, const int tp) {
	int X1, X2, Y1, Y2;
	Decode (Node, X1, Y1);
	
	for (int i = Head[Node]; i; i = Next[i] ) {
		Decode (To[i], X2, Y2);
		
		if (Type[i] ^ Tp or Used[To[i]][Tp] ) {
			continue ;
		}
		
		if (Tp == 1 ) {
			if (~Color[To[i]] ) {
				if (Color[To[i]] ^ col and Level[To[i]] <= lv ) {
					Used[To[i]][Tp] = 1;
					
					if (!Instack[To[i]] ) {
						Stack[++ Top] = To[i], Instack[To[i]] = 1;
					}
				}
				
				continue ;
			}
			
			Used[To[i]][Tp] = 1;
		
			
			if (!Instack[To[i]] ) {
				Stack[++ Top] = To[i], Instack[To[i]] = 1;
			}
			
			continue ;
		}
		
		if (Tp == 3 ) {
			if (~Color[To[i]] ) {
				if (Color[To[i]] ^ col and Level[To[i]] <= lv ) {
					Used[To[i]][Tp] = 1;
					
					if (!Instack[To[i]] ) {
						Stack[++ Top] = To[i], Instack[To[i]] = 1;
					}
				}
				
				continue ;
			}
			
			if (Used[To[i]][Tp] ) {
				continue ;
			}
			
			Used[To[i]][Tp] = 1;
			
			if (!Instack[To[i]] ) {
				Stack[++ Top] = To[i], Instack[To[i]] = 1;
			}
			
			Search (To[i], Tp, tp);
			continue ;
		}
		
		if (tp == 0 ) {
			if (~Color[To[i]] ) {
				if (Color[To[i]] ^ col and Level[To[i]] <= lv ) {
					Used[To[i]][Tp] = 1;
					
					if (!Instack[To[i]] ) {
						Stack[++ Top] = To[i], Instack[To[i]] = 1;
					}
				}
				
				continue ;
			}
			
			if (Used[To[i]][Tp] ) {
				continue ;
			}
			
			Used[To[i]][Tp] = 1;
			
			if (!Instack[To[i]] ) {
				Stack[++ Top] = To[i], Instack[To[i]] = 1;
			}
			
			Search (To[i], Tp, Getdict (X1, Y1, X2, Y2));
		}
		
		else if (Getdict (X1, Y1, X2, Y2) == tp ) {
			if (~Color[To[i]] ) {
				if (Color[To[i]] ^ col and Level[To[i]] <= lv ) {
					Used[To[i]][Tp] = 1;
					
					if (!Instack[To[i]] ) {
						Stack[++ Top] = To[i], Instack[To[i]] = 1;
					}
				}
				
				continue ;
			}
			
			if (Used[To[i]][Tp] ) {
				continue ;
			}
			
			Used[To[i]][Tp] = 1;
			
			if (!Instack[To[i]] ) {
				Stack[++ Top] = To[i], Instack[To[i]] = 1;
			}
			
			Search (To[i], Tp, tp);
		}
	}
	
	return ;
}

signed main () {
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	T = Read ();
	
	while (T -- ) {
		n = Read (), m = Read (), q = Read (), Total = 1;
		
		for (int i = 1; i <= n * m; ++ i ) {
			Color[i] = Level[i] = -1, Head[i] = 0;
		}
		
		for (int i = 1; i <= n; ++ i ) {
			scanf ("%s", Str + 1);
			
			for (int j = 1; j < m; ++ j ) {
				if (Str[j] != '0' ) {
					Addedge (Encode (i, j), Encode (i, j + 1), Str[j] - '0');
				}
			}
		}
		
		for (int i = 1; i < n; ++ i ) {
			scanf ("%s", Str + 1);
			
			for (int j = 1; j <= m; ++ j ) {
				if (Str[j] != '0' ) {
					Addedge (Encode (i, j), Encode (i + 1, j), Str[j] - '0');
				}
			}
		}
		
		while (q -- ) {
			col = Read (), lv = Read (), X = Read (), Y = Read ();
			Instack[Encode (X, Y)] = Used[Encode (X, Y)][1] = 1;
			Used[Encode (X, Y)][2] = Used[Encode (X, Y)][3] = 1;
			
			for (int i = 1; i <= 3; ++ i ) {
				Search (Encode (X, Y), i, 0);
			}
			
			Write (Top), putchar ('\n');
			
			while (Top ) {
				Used[Stack[Top]][1] = Used[Stack[Top]][2] = 0;
				Used[Stack[Top]][3] = Instack[Stack[Top]] = 0;
				-- Top;
			}
			
			Color[Encode (X, Y)] = col, Level[Encode (X, Y)] = lv;
			Instack[Encode (X, Y)] = Used[Encode (X, Y)][1] = 0;
			Used[Encode (X, Y)][2] = Used[Encode (X, Y)][3] = 0;
		}
	}
	
	return 0;
}

/*
吾以 Shigure 之名，衷心祝福 CCF  
*/
