//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 10005;
const LL INF = 1ll<<60;
int n;
int a[MAXN],b[MAXN];
LL ans = INF;

LL Read()
{
	LL x = 0,f = 1;char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = (x*10) + (c^48);c = getchar();}
	return x * f;
}
TT void Put1(T x)
{
	if(x > 9) Put1(x/10);
	putchar(x%10^48);
}
TT void Put(T x,char c = -1)
{
	if(x < 0) putchar('-'),x = -x;
	Put1(x); if(c >= 0) putchar(c);
}
TT T Max(T x,T y){return x > y ? x : y;}
TT T Min(T x,T y){return x < y ? x : y;}
TT T Abs(T x){return x < 0 ? -x : x;}

void solve1()//wrong
{
	for(int i = 1;i < n;++ i)
	{
		for(int j = 1;j <= n;++ j) b[j] = a[j];
		for(int j = i;j > 1;-- j) b[j] = Max(b[j],b[j-1]+b[j+1]-b[j]);
		for(int j = i+1;j < n;++ j) b[j] = Min(b[j],b[j-1]+b[j+1]-b[j]);
		LL val = 0,S = 0;
		for(int j = 1;j <= n;++ j) val += 1ll * n * b[j] * b[j],S += b[j];
		val -= S*S; ans = Min(ans,val);
		
		for(int j = 1;j <= n;++ j) b[j] = a[j];
		for(int j = i+1;j < n;++ j) b[j] = Min(b[j],b[j-1]+b[j+1]-b[j]);
		for(int j = i;j > 1;-- j) b[j] = Max(b[j],b[j-1]+b[j+1]-b[j]);
		val = 0,S = 0;
		for(int j = 1;j <= n;++ j) val += 1ll * n * b[j] * b[j],S += b[j];
		val -= S*S; ans = Min(ans,val);
		
		for(int j = 1;j <= n;++ j) b[j] = a[j];
		for(int j = i+1;j < n;++ j) b[j] = Min(b[j],b[j-1]+b[j+1]-b[j]);
		for(int j = i-1;j > 1;-- j) b[j] = Max(b[j],b[j-1]+b[j+1]-b[j]);
		val = 0,S = 0;
		for(int j = 1;j <= n;++ j) val += 1ll * n * b[j] * b[j],S += b[j];
		val -= S*S; ans = Min(ans,val);
		
		for(int j = 1;j <= n;++ j) b[j] = a[j];
		for(int j = i-1;j > 1;-- j) b[j] = Max(b[j],b[j-1]+b[j+1]-b[j]);
		for(int j = i+1;j < n;++ j) b[j] = Min(b[j],b[j-1]+b[j+1]-b[j]);
		val = 0,S = 0;
		for(int j = 1;j <= n;++ j) val += 1ll * n * b[j] * b[j],S += b[j];
		val -= S*S; ans = Min(ans,val);
	}
}
LL dp[105][75][4005];//i,a[i],S
void solve2()
{
	int MAX = 0,MM = 0;
	for(int i = 1;i <= n;++ i) MAX = Max(MAX,a[i]);
	MM = MAX*n;
	for(int i = 1;i <= n;++ i)
		for(int j = 0;j <= MAX;++ j)
			for(int S = 0;S <= MM;++ S)
				dp[i][j][S] = INF;
	dp[1][a[1]][a[1]] = 1ll * n * a[1] * a[1] - a[1] * a[1];
	for(int i = 1;i < n;++ i)
		for(int j = 0;j <= MAX && j <= a[i+1];++ j) 
			for(int S = 0;S <= MM;++ S)
			{
				int now = a[i+1];
				dp[i+1][now][S+now] = Min(dp[i+1][now][S+now],dp[i][j][S]+1ll*n*now*now-2ll*now*S-now*now);
				if(i <= n-2)
				{
					now = j+a[i+2]-a[i+1];
					dp[i+1][now][S+now] = Min(dp[i+1][now][S+now],dp[i][j][S]+1ll*n*now*now-2ll*now*S-now*now);
				}
			}
	for(int j = 0;j <= MAX;++ j) 
		for(int S = 0;S <= MM;++ S)
			ans = Min(ans,dp[n][j][S]);
}

void solve3()
{
	int MAX = 0,MM = 0;
	for(int i = 1;i <= n;++ i) MAX = Max(MAX,a[i]);
	MM = MAX*n;
	for(int i = 1;i <= n;++ i)
		for(int j = 0;j <= MAX;++ j)
			for(int S = 0;S <= MM;++ S)
				dp[i][j][S] = INF;
	dp[n][a[n]][a[n]] = 1ll * n * a[n] * a[n] - a[n] * a[n];
	for(int i = n;i > 1;-- i)
		for(int j = 0;j <= MAX && j <= a[i-1];++ j) 
			for(int S = 0;S <= MM;++ S)
			{
				int now = a[i-1];
				dp[i+1][now][S+now] = Min(dp[i-1][now][S+now],dp[i][j][S]+1ll*n*now*now-2ll*now*S-now*now);
				if(i >= 3)
				{
					now = j+a[i-2]-a[i-1];
					dp[i-1][now][S+now] = Min(dp[i-1][now][S+now],dp[i][j][S]+1ll*n*now*now-2ll*now*S-now*now);
				}
			}
	for(int j = 0;j <= MAX;++ j) 
		for(int S = 0;S <= MM;++ S)
			ans = Min(ans,dp[1][j][S]);
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n = Read();
	for(int i = 1;i <= n;++ i) a[i] = Read();
	solve1();
	solve2();
	solve3();
	Put(ans,'\n');
	return 0;
}
/*
数学题杀我
要么会T3，要么把T4写出来
开T3，丢T4，不愧是你，哈哈 
ans = (\sum ai^2 / n) - (S^2 / n^2)
*/
