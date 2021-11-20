#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int T, n, m, Q, a[N][N], b[N][N], co0, lv0, x0, y3;
char c[N];
bool flag[N][N];
struct qi
{
	int co, lv;
}x[N][N];
int dian()
{
	int x2 = x0, y2 = y3;
	int cnt = 0;
	memset(flag, 0, sizeof(flag));
	flag[x0][y3] = 1;
	//判断互交铁路 
	queue<pair<int, int> > q;
	q.push({x0, y3});
	while(q.size())
	{ 
		x0 = q.front().first, y3 = q.front().second;
		q.pop();
		if(a[x0][y3 - 1] == 3)
		{
			if(x[x0][y3 - 1].lv != 0)
			{
				if(x[x0][y3 - 1].lv <= x[x0][y3].lv && x[x0][y3 - 1].co != x[x0][y3].co)
					flag[x0][y3 - 1] = 1;
			}
			else
			{
				if(flag[x0][y3 - 1] == 0)
				{
					flag[x0][y3 - 1] = 1;
					q.push({x0, y3 - 1});
				}
			}
		}
		if(a[x0][y3] == 3)
		{
			if(x[x0][y3 + 1].lv != 0)
			{
				if(x[x0][y3 + 1].lv <= x[x0][y3].lv && x[x0][y3 + 1].co != x[x0][y3].co)
					flag[x0][y3 + 1] = 1;
			}
			else
			{
				if(flag[x0][y3 + 1] == 0)
				{
					flag[x0][y3 + 1] = 1;
					q.push({x0, y3 + 1});
				}
			}
		}
		if(b[x0][y3] == 3)
		{
			if(x[x0 + 1][y3].lv != 0)
			{
				if(x[x0 + 1][y3].lv <= x[x0][y3].lv && x[x0 + 1][y3].co != x[x0][y3].co)
					flag[x0 + 1][y3] = 1;
			}
			else
			{
				if(flag[x0 + 1][y3] == 0)
				{
					flag[x0 + 1][y3] = 1;
					q.push({x0 + 1, y3});
				}
			}
		}
		if(b[x0 - 1][y3] == 3)
		{
			if(x[x0 - 1][y3].lv != 0)
			{
				if(x[x0 - 1][y3].lv <= x[x0][y3].lv && x[x0 - 1][y3].co != x[x0][y3].co)
					flag[x0 - 1][y3] = 1;
			}
			else
			{
				if(flag[x0 - 1][y3] == 0)
				{
					flag[x0 - 1][y3] = 1;
					q.push({x0 - 1, y3});
				}
			}
		}
	}
	x0 = x2, y3 = y2;
	//判断普通铁路
	if(a[x0][y3 - 1] == 1)
	{
		if(x[x0][y3 - 1].lv != 0)
		{
			if(x[x0][y3 - 1].lv <= x[x0][y3].lv && x[x0][y3 - 1].co != x[x0][y3].co)
				flag[x0][y3 - 1] = 1;
		}
		else
			flag[x0][y3 - 1] = 1;
	}
	if(a[x0][y3] == 1)
	{
		if(x[x0][y3 + 1].lv != 0)
		{
			if(x[x0][y3 + 1].lv <= x[x0][y3].lv && x[x0][y3 + 1].co != x[x0][y3].co)
				flag[x0][y3 + 1] = 1;
		}
		else
			flag[x0][y3 + 1] = 1;
	}
	if(b[x0][y3] == 1)
	{
		if(x[x0 + 1][y3].lv != 0)
		{
			if(x[x0 + 1][y3].lv <= x[x0][y3].lv && x[x0 + 1][y3].co != x[x0][y3].co)
				flag[x0 + 1][y3] = 1;
		}
		else
			flag[x0 + 1][y3] = 1;
	}
	if(b[x0 - 1][y3] == 1)
	{
		if(x[x0 - 1][y3].lv != 0)
		{
			if(x[x0 - 1][y3].lv <= x[x0][y3].lv && x[x0 - 1][y3].co != x[x0][y3].co)
				flag[x0 - 1][y3] = 1;
		}
		else
			flag[x0 - 1][y3] = 1;
	}
	//判断直线铁路
	while(x2 >= 0 && y2 >= 0 && a[x2][y2 - 1] == 2)
	{
		if(x[x2][y2 - 1].lv != 0)
		{
			if(x[x2][y2 - 1].lv <= x[x2][y2].lv && x[x2][y2 - 1].co != x[x2][y2].co)
				flag[x2][y2 - 1] = 1;
			break; 
		}
		else
			flag[x2][y2 - 1] = 1;
		y2--;
	}
	x2 = x0, y2 = y3;
	while(x2 >= 0 && y2 >= 0 && a[x2][y2] == 2)
	{
		if(x[x2][y2 + 1].lv != 0)
		{
			if(x[x2][y2 + 1].lv <= x[x2][y2].lv && x[x2][y2 + 1].co != x[x2][y2].co)
				flag[x2][y2 + 1] = 1;
			break;
		}
		else
			flag[x2][y2 + 1] = 1;
	}
	x2 = x0, y2 = y3;
	while(x2 >= 0 && y2 >= 0 && b[x2][y2] == 2)
	{
		if(x[x2 + 1][y2].lv != 0)
		{
			if(x[x2 + 1][y2].lv <= x[x2][y2].lv && x[x2 + 1][y2].co != x[x2][y2].co)
				flag[x2 + 1][y2] = 1;
			break;
		}
		else
			flag[x2 + 1][y2] = 1;
	}
	x2 = x0, y2 = y3;
	while(x2 >= 0 && y2 >= 0 && b[x2 - 1][y2] == 2)
	{
		if(x[x2 - 1][y2].lv != 0)
		{
			if(x[x2 - 1][y2].lv <= x[x2][y2].lv && x[x2 - 1][y2].co != x[x2][y2].co)
				flag[x2 - 1][y2] = 1;
			break; 
		}
		else
			flag[x2 - 1][y2] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(flag[i][j])
				cnt++;
	return cnt - 1;
}
int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		memset(x, 0, sizeof(x));
		cin >> n >> m >> Q;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", c + 1);
			for(int j = 1; j < m; j++)
				a[i][j] = c[j] - '0';
		}
		for(int i = 1; i < n; i++)
		{
			scanf("%s", c + 1);
			for(int j = 1; j <= m; j++)
				b[i][j] = c[j] - '0';
		}
		for(int i = 1; i <= Q; i++)
		{
			scanf("%d%d%d%d", &co0, &lv0, &x0, &y3);
			x[x0][y3].co = co0;
			x[x0][y3].lv = lv0;
			cout << dian() << endl;
		}
	}
	return 0;
}
