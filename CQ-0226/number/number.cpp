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
bool check(int x)
{
	while(x)
	{
		if(x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}
int t,x;
bool vis[10000005];
int sum[10000005],cnt;
int next[10000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i = 1 ; i <= 10000000 ; i++)
	{
		if(check(i))
		{
			sum[++cnt] = i;
			vis[i] = true;
		}
	}
	for(int i = 1 ; i <= 10000000 ; i++)
	{
		for(int j = 1 ; j <= cnt && i * sum[j] <= 10000000  ; j++)
		{
			vis[i * sum[j]] = true;
			if(i % sum[j] == 0) break;
		}
//		cout<<i<<':'<<vis[i]<<endl;
	}
	int last = 1;
	for(int i = 1 ; i <= 10000000 ; i++)
	{
		if(!vis[i])
		{
			next[last] = i;
			last = i;
		}
	}
	t = read();
	while(t--)
	{
		x = read();
		if(vis[x]) puts("-1");
		else
		{
			print(next[x]);
			puts("");	
		}
	}
	return 0;
}
/*
4
6
33
69
300

5
90
99
106
114
169
*/
