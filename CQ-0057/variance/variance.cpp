#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define int long long
#define MAXN 10005

template <typename T> inline void read (T &x){x = 0;int f = 1;char c = getchar();while (!isdigit (c)) f *= (c == '-' ? -1 : 1),c = getchar ();while (isdigit (c)) x = x * 10 + c - '0',c = getchar ();x *= f;}
template <typename T> inline void write (T x){if (x < 0) x = -x,putchar ('-');if (x > 9) write (x / 10);putchar (x % 10 + '0');}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}

#define down 0.997

int n,ans,miv,a[MAXN];

int getv (){
	int sum1 = 0,sum2 = 0;
	for (Int i = 1;i <= n;++ i) sum1 += a[i] * a[i],sum2 += a[i];
	return sum1 * n - sum2 * sum2;
}

void Climb (){
	for (Int i = 1;i <= 10000;++ i){
		int pos = rand() % (n - 2) + 2;
		a[pos] = a[pos - 1] + a[pos + 1] - a[pos];
		int newv = getv ();chkmin (miv,newv);
		if (newv < ans) ans = newv;
		else a[pos] = a[pos - 1] + a[pos + 1] - a[pos];
	}
}

void SA (){
	double temp = 3000;
	while (temp > 1e-7){
		int pos = rand() % (n - 2) + 2;
		a[pos] = a[pos - 1] + a[pos + 1] - a[pos];
		int newv = getv (),diff = ans - newv;chkmin (miv,newv);
		if (newv < ans) ans = newv;
		else if (exp (-diff / temp) < rand() * 1.0 / RAND_MAX) ans = newv;
		else a[pos] = a[pos - 1] + a[pos + 1] - a[pos];
		temp *= down;
	}
}

void SA1 (){
	double temp = 3000;
	while (temp > 1e-7){
		int pos = rand() % (n - 2) + 2;
		a[pos] = a[pos - 1] + a[pos + 1] - a[pos];
		int newv = getv (),diff = ans - newv;chkmin (miv,newv);
		if (newv < ans) ans = newv;
		else if (exp (diff / temp) < rand() * 1.0 / RAND_MAX) ans = newv;
		else a[pos] = a[pos - 1] + a[pos + 1] - a[pos];
		temp *= down;
	}	
}

signed main(){
	freopen ("variance.in","r",stdin);
	freopen ("variance.out","w",stdout);
	srand (20050913),read (n);
	for (Int i = 1;i <= n;++ i) read (a[i]);
	ans = miv = getv ();Climb ();
	for (Int i = 1;i <= 100;++ i) SA ();
	for (Int i = 1;i <= 100;++ i) SA1 ();
	write (miv),putchar ('\n');
	return 0;
}
/*
分析：
复杂度一定是n*v的
然后答案的式子就是 n*(\sum a_i^2)-(\sum a_i)^2

现在思路：
我tm大不了模拟退火
爷试一下 
*/
