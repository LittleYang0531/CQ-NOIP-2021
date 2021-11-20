#include<bits/stdc++.h>
using namespace std;
int read()
{
	int num,f = 1;
	char ch;
	while((ch = getchar()) && (ch < '0' || ch > '9'))
	{
		if(ch == '-') f = -1;
	}
	num = ch - '0';
	while((ch = getchar()) && (ch >= '0' && ch <= '9')) num = num * 10 + ch - '0';
	return num * f;
}
void print(int x)
{
	if(x < 0) putchar('-'),x *= -1;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
int n,ll = INT_MAX;
long long ans = 0x3f3f3f3f3f3f3f3f;
int x[10005];
bool flag[10000005];
bool vis[10005];
int has()
{
	long long has = 0;
	for(int i = 1 ; i <= n ; i++) has = ((has * 137 % 10000000 + x[i]) % 10000000 + 10000000) % 10000000;
	return has;
}
bool check()
{
	int maxn = -INT_MAX,minn = INT_MAX;
	for(int i = 2 ; i < n ; i++) maxn = max(maxn,x[i]),minn = min(minn,x[i]);
	if(maxn - minn <= ll) 
	{
		ll = maxn - minn;
		return false;
	}
	else return true;
}
void dfs(int k,long long num,long long power)
{
//	if(power * n - num * num > ans) return;
//	cout<<k<<endl;
	ans = min(ans,power * n - num * num);
//	cout<<has(x)<<endl;
	if(flag[has()]) return; 
	flag[has()] = true;
//	if(check()) return;
//	cout<<power<<' '<<num<<':'<<power * n - num * num<<endl;
//	for(int i = 1 ; i <= n ; i++) cout<<x[i]<<' ';
//	cout<<endl;
	for(int i = 2 ; i < n ; i++)
	{
		if((x[i + 1] + x[i - 1] - x[i] != x[i]))
		{
			int f = x[i];
			long long a = power,b = num;
			num -= x[i];
			power -= x[i] * x[i];
			x[i] = x[i - 1] + x[i + 1] - x[i];
			power += x[i] * x[i];
			num += x[i];
			dfs(k + 1,num,power);
			power = a;
			num = b;
			x[i] = f;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i = 1 ; i <= n ; i++) x[i] = read();
	long long num = 0,power = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		num += x[i];
		power += x[i] * x[i];
	}
	dfs(0,num,power);
	cout<<ans;
	return 0;
}
