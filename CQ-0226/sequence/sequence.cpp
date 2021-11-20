#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
long long v[105];
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
bool check(int num)
{
//	cout<<num<<':'<<endl;
	int sum = 0;
	while(num)
	{
		sum += (num & 1);
		num /= 2;
//		cout<<sum<<endl;
		if(sum > k) return true;
	}
	return false;
}
void dfs(int k,int sum,long long num)
{
//	cout<<k<<' '<<sum<<endl;
	num %= 998244353;
	if(k == n + 1)
	{
		if(!check(sum)) ans += num;
		ans %= 998244353;
		return;	
	}
	long long f = 1;
	for(int i = 0 ; i <= m ; i++)
	{
		dfs(k + 1,sum + f,num * v[i]);
		f *= 2;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 0 ; i <= m ; i++)
	{
		scanf("%d",&v[i]);
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
/*
5 1 1
2 1
*/
