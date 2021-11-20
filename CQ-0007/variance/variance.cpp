#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define pii pair <int , int>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(x<0) {putchar('-');x=-x;}
	if(!x) {putchar('0');putchar(s);return;}
	T tmp[25] , t = 0;
	while(x) tmp[t ++] = x % 10 , x /= 10;
	while(t -- > 0) putchar(tmp[t] + '0');
	putchar(s);
}

const int MAXN = 1e4 + 5;
const LL inf = 1e18;

map <ULL , LL> dp;
map <ULL , int> M;

int num[605] , n , a[MAXN];
vector <pii> tot;
vector <int> ori , sta[MAXN * 100];



int main() {
	freopen("variance.in" , "r" , stdin);
	freopen("variance.out" , "w" , stdout);
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 2; i <= n; ++i) num[a[i] - a[i - 1]] ++;
	for (int i = 0; i <= 600; ++i) if(num[i]) tot.push_back(mp(num[i] , i)) , ori.push_back(num[i]);
	ori.push_back(a[1]);
	sta[1] = ori;
	ULL cur = 0;for (int i = 0; i < (int)sta[1].size(); ++i) cur = (cur * 131ull + sta[1][i]);
	queue <ULL> q;
	dp[cur] = 1ll * a[1] * a[1] * n , M[cur] = 1;
	q.push(cur);
	LL ans = inf , ct = 1;
	while(!q.empty()) {
		ULL x = q.front();
		q.pop();
		int pos = M[x];
		LL las = dp[x];
		vector <int> now = sta[pos];
		if(ct > 1000000) {
			break;
		}
		LL A = a[1];for (int i = 0; i < (int)now.size() - 1; ++i) A += (tot[i].fs - now[i]) * tot[i].sc;
		int fl = 0;
		for (int i = 0; i < (int)now.size() - 1; ++i) if(now[i]) {
			fl = 1;
			now[i] -- , now[now.size() - 1] += A + tot[i].sc;
			ULL nxt = 0;
			for (int j = 0; j < (int)now.size(); ++j) nxt = nxt * 131ull + now[j];
			if(!dp.count(nxt)) dp[nxt] = las + (A + tot[i].sc) * (A + tot[i].sc) * n , q.push(nxt) , M[nxt] = ++ct , sta[ct] = now;
			else dp[nxt] = min(dp[nxt] , las + (A + tot[i].sc) * (A + tot[i].sc) * n);
			now[i] ++ , now[now.size() - 1] -= A + tot[i].sc;
		}
		if(!fl) ans = min(ans , las - (1ll * now[now.size() - 1] * now[now.size() - 1]));
	}
	write(ans);
	return 0;
}
