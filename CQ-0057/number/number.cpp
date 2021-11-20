#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 10000005
 
template <typename T> inline void read (T &x){x = 0;int f = 1;char c = getchar();while (!isdigit (c)) f *= (c == '-' ? -1 : 1),c = getchar ();while (isdigit (c)) x = x * 10 + c - '0',c = getchar ();x *= f;}
template <typename T> inline void write (T x){if (x < 0) x = -x,putchar ('-');if (x > 9) write (x / 10);putchar (x % 10 + '0');} 

int nxt[MAXN];
bool vis[MAXN];
void Euler (int up){
	for (Int i = 1;i <= up;++ i){
		if (vis[i]) continue;
		bool flg = 1;
		for (Int j = 0,tmp = i;j <= 9;++ j,tmp /= 10) if (tmp % 10 == 7){flg = 0;break;}
		if (!flg) for (Int j = i;j <= up;j += i) vis[j] = 1;
	}
	for (Int i = up,lst = 0;i >= 1;-- i) if (vis[i]) nxt[i] = -1;else nxt[i] = lst,lst = i; 
} 

signed main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout); 
	Euler (1e7 + 1);
	int T;read (T);
	while (T --> 0){
		int x;read (x);
		write (nxt[x]),putchar ('\n'); 
	}
	return 0;
}
