#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 200005

template <typename T> inline void read (T &x){x = 0;int f = 1;char c = getchar();while (!isdigit (c)) f *= (c == '-' ? -1 : 1),c = getchar ();while (isdigit (c)) x = x * 10 + c - '0',c = getchar ();x *= f;}
template <typename T> inline void write (T x){if (x < 0) x = -x,putchar ('-');if (x > 9) write (x / 10);putchar (x % 10 + '0');}

int T,n,m,q;
char s1[MAXN],s2[MAXN];

#define pii pair<int,int> 
#define se second
#define fi first

vector <pii> s[MAXN];
vector <int> c1[MAXN],c2[MAXN];
vector <bool> vis1[MAXN],vis2[MAXN],vis3[MAXN];

void Work (){
	read (n),read (m),read (q);
	for (Int i = 1;i <= n;++ i){
		s[i].resize (m + 1);
		for (Int j = 1;j <= m;++ j) s[i][j] = {0,0};
	}
	for (Int i = 1;i <= n;++ i){
		scanf ("%s",s1 + 1),c1[i].resize (m);
		for (Int j = 1;j <= m - 1;++ j) c1[i][j] = s1[j] - '0'; 
	}
	for (Int i = 1;i <= n - 1;++ i){
		scanf ("%s",s2 + 1),c2[i].resize (m + 1);
		for (Int j = 1;j <= m;++ j) c2[i][j] = s2[j] - '0'; 
	}
	for (Int i = 1;i <= n;++ i){
		vis1[i].resize (m + 1),vis2[i].resize (m + 1),vis3[i].resize (m + 1);
		for (Int j = 1;j <= m;++ j) vis1[i][j] = vis2[i][j] = vis3[i][j] = 0;
	}
	while (q --> 0){
		int c,l,x,y;read (c),read (l),read (x),read (y);
		vector <pii> Pos;
		//经过普通道路 
		if (x <= n - 1 && c2[x][y] == 1) vis1[x + 1][y] = 1,Pos.push_back ({x + 1,y});
		if (y <= m - 1 && c1[x][y] == 1) vis1[x][y + 1] = 1,Pos.push_back ({x,y + 1});
		if (x > 1 && c2[x - 1][y] == 1) vis1[x - 1][y] = 1,Pos.push_back ({x - 1,y});
		if (y > 1 && c1[x][y - 1] == 1) vis1[x][y - 1] = 1,Pos.push_back ({x,y - 1});
		//经过直行道路
		if (x <= n - 1 && c2[x][y] == 2) for (Int i = x;i < n;++ i) if (c2[i][y] == 2 && !s[i][y].fi) Pos.push_back ({i + 1,y}),vis2[i + 1][y] = 1;else break;
		if (x > 1 && c2[x - 1][y] == 2) for (Int i = x;i > 1;-- i) if (c2[i - 1][y] == 2 && !s[i][y].fi) Pos.push_back ({i - 1,y}),vis2[i - 1][y] = 1;else break;
		if (y <= m - 1 && c1[x][y] == 2) for (Int i = y;i < m;++ i) if (c1[x][i] == 2 && !s[x][i].fi) Pos.push_back ({x,i + 1}),vis2[x][i + 1] = 1;else break;
		if (y > 1 && c1[x][y - 1] == 2) for (Int i = y;i > 1;-- i) if (c1[x][i - 1] == 2 && !s[x][i].fi) Pos.push_back ({x,i - 1}),vis2[x][i - 1] = 1;else break;
		//经过拐弯道路
		queue <pii> q;q.push ({x,y});
		while (!q.empty()){
			pii now = q.front();q.pop ();
			int nx = now.fi,ny = now.se;if (s[nx][ny].fi) continue;
			if (nx <= n - 1 && c2[nx][ny] == 3 && !vis3[nx + 1][ny]) Pos.push_back ({nx + 1,ny}),vis3[nx + 1][ny] = 1,q.push ({nx + 1,ny});
			if (ny <= m - 1 && c1[nx][ny] == 3 && !vis3[nx][ny + 1]) Pos.push_back ({nx,ny + 1}),vis3[nx][ny + 1] = 1,q.push ({nx,ny + 1});
			if (nx > 1 && c2[nx - 1][ny] == 3 && !vis3[nx - 1][ny]) Pos.push_back ({nx - 1,ny}),vis3[nx - 1][ny] = 1,q.push ({nx - 1,ny});
			if (ny > 1 && c1[nx][ny - 1] == 3 && !vis3[nx][ny - 1]) Pos.push_back ({nx,ny - 1}),vis3[nx][ny - 1] = 1,q.push ({nx,ny - 1}); 
		}
		int ans = 0;
		for (pii it : Pos){
			int i = it.fi,j = it.se;
			if (i != x || j != y)
				if (vis1[i][j] || vis2[i][j] || vis3[i][j])
					if (!s[i][j].fi || (s[i][j].fi <= l && s[i][j].se != c)) ans ++;
			vis1[i][j] = vis2[i][j] = vis3[i][j] = 0;
		}
		write (ans),putchar ('\n'),s[x][y] = {l,c};
	}
}

signed main(){
	freopen ("chess.in","r",stdin);
	freopen ("chess.out","w",stdout);
	read (T);
	while (T --> 0) Work ();
	return 0;
}
