#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int lim = 10000001;
int vis1[lim + 5], vis2[lim + 5], nex[lim + 5];
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 0; i <= lim; i++)
	{
		if (vis1[i])
		{
			for (int j = i * 10; j <= i * 10 + 9 && j <= lim; j++)
				vis1[j] = 1;
			for (int j = i; j <= lim; j += i)
				vis2[j] = 1;
		}
		else
			if (i * 10 + 7 <= lim)
				vis1[i * 10 + 7] = 1;
	}
	int lst = -1;
	for (int i = lim; i >= 0; i--)
	{
		if (vis2[i])
			nex[i] = -1;
		else
			nex[i] = lst, lst = i;
	}
	int T;
	Read(T);
	while (T--)
	{
		int x;
		Read(x);
		printf("%d\n", nex[x]);
	}
}
