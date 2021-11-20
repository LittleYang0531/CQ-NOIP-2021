//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 200005;
int n,m,Q;
vector<char> r[MAXN],c[MAXN];

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

char gc()
{
	char c = getchar();
	while(c > '3' || c < '0') c = getchar();
	return c;
}

int pa[MAXN],vis[MAXN];
int ID(int x,int y){return (x-1)*m+y;}
struct pwn
{
	int col,lv,x,y;
}p[MAXN];
int dx[4] = {1,-1},dy[4] = {0,0,1,-1},ans;
struct node{int x,y;};
int gan(int x,int y)
{
	if(!y || y > x) return 2;//walk (no pawn)
	if(p[x].col == p[y].col || p[x].lv < p[y].lv) return 0;//stop
	return 1;//eat(terrible)
}
void bfs(int x)
{
	queue<node> q; q.push(node{p[x].x,p[x].y});
	vis[ID(p[x].x,p[x].y)] = x;
	while(!q.empty())
	{
		node t = q.front(); q.pop();
		int X = t.x,Y = t.y;
		for(int i = 0;i < 4;++ i)
		{
			int tox = X + dx[i],toy = Y + dy[i];
			if(tox < 1 || toy < 1 || tox > n || toy > m || vis[ID(tox,toy)] == x) continue;
			if(i == 0 && c[X][Y] == '3') 
			{
				vis[ID(tox,toy)] = x;
				if(gan(x,pa[ID(tox,toy)]) == 2) q.push(node{tox,toy}),++ans;
				else if(gan(x,pa[ID(tox,toy)]) == 1) ++ans;
			}
			if(i == 1 && c[tox][toy] == '3') 
			{
				vis[ID(tox,toy)] = x;
				if(gan(x,pa[ID(tox,toy)]) == 2) q.push(node{tox,toy}),++ans;
				else if(gan(x,pa[ID(tox,toy)]) == 1) ++ans;
			}
			if(i == 2 && r[X][Y] == '3') 
			{
				vis[ID(tox,toy)] = x;
				if(gan(x,pa[ID(tox,toy)]) == 2) q.push(node{tox,toy}),++ans;
				else if(gan(x,pa[ID(tox,toy)]) == 1) ++ans;
			}
			if(i == 3 && r[tox][toy] == '3') 
			{
				vis[ID(tox,toy)] = x;
				if(gan(x,pa[ID(tox,toy)]) == 2) q.push(node{tox,toy}),++ans;
				else if(gan(x,pa[ID(tox,toy)]) == 1) ++ans;
			}
		}
	}
	for(int i = p[x].y;i < m;++ i)
	{	
		if(r[p[x].x][i] != '2') break;
		if(vis[ID(p[x].x,i+1)] != x) 
		{
			if(gan(x,pa[ID(p[x].x,i+1)]) == 2) ++ans;
			else if(gan(x,pa[ID(p[x].x,i+1)]) == 1) {++ans;break;}
			else break;
		}
		if(gan(x,pa[ID(p[x].x,i+1)]) <= 1) break;
	}
	for(int i = p[x].y-1;i >= 1;-- i)
	{
		if(r[p[x].x][i] != '2') break;
		if(vis[ID(p[x].x,i)] != x) 
		{
			if(gan(x,pa[ID(p[x].x,i)]) == 2) ++ans;
			else if(gan(x,pa[ID(p[x].x,i)]) == 1) {++ans;break;}
			else break;
		}
		if(gan(x,pa[ID(p[x].x,i)]) <= 1) break;
	}
	for(int i = p[x].x;i < n;++ i)
	{
		if(c[i][p[x].y] != '2') break;
		if(vis[ID(i+1,p[x].y)] != x) 
		{
			if(gan(x,pa[ID(i+1,p[x].y)]) == 2) ++ans;
			else if(gan(x,pa[ID(i+1,p[x].y)]) == 1) {++ans;break;}
			else break;
		}
		if(gan(x,pa[ID(i+1,p[x].y)]) <= 1) break;
	}
	for(int i = p[x].x-1;i >= 1;-- i)
	{
		if(c[i][p[x].y] != '2') break;
		if(vis[ID(i,p[x].y)] != x) 
		{
			if(gan(x,pa[ID(i,p[x].y)]) == 2) ++ans;
			else if(gan(x,pa[ID(i,p[x].y)]) == 1) {++ans;break;}
			else break;
		}
		if(gan(x,pa[ID(i,p[x].y)]) <= 1) break;
	}
	int X = p[x].x,Y = p[x].y;
	for(int i = 0;i < 4;++ i)
	{
		int tox = X + dx[i],toy = Y + dy[i];
		if(tox < 1 || toy < 1 || tox > n || toy > m || vis[ID(tox,toy)] == x) continue;
		if(i == 0 && c[X][Y] == '1' && gan(x,pa[ID(tox,toy)])) ++ans;
		if(i == 1 && c[tox][toy] == '1' && gan(x,pa[ID(tox,toy)])) ++ans;
		if(i == 2 && r[X][Y] == '1' && gan(x,pa[ID(tox,toy)])) ++ans;
		if(i == 3 && r[tox][toy] == '1' && gan(x,pa[ID(tox,toy)])) ++ans;
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int T = Read(); T ;-- T)
	{
		n = Read(); m = Read(); Q = Read();
		for(int i = n*m;i >= 1;-- i) 
			pa[i] = vis[i] = 0,r[i].clear(),c[i].clear();
		for(int i = 1;i <= n;++ i) 
		{
			r[i].emplace_back(' ');
			for(int j = 1;j < m;++ j)
				r[i].emplace_back(gc());
		}
		for(int i = 1;i <= n-1;++ i)
		{
			c[i].emplace_back(' ');
			for(int j = 1;j <= m;++ j)
				c[i].emplace_back(gc());
		}
		for(int i = 1;i <= Q;++ i)
			p[i].col = Read(),p[i].lv = Read(),p[i].x = Read(),p[i].y = Read(),pa[ID(p[i].x,p[i].y)] = i;
		for(int i = 1;i <= Q;++ i)
		{
			ans = 0;
			bfs(i);
			Put(ans,'\n');
		}
	}
	return 0;
}
//There's no god but you.
/*
���ڼ������൱�ڶϿ�һЩ��ͨ�飬������֪��ͨ��Ҫ�ϲ��ź�ά�����������ǵ�����
���Ǻϲ���ͨ�飬���ڿո��ӣ�����ֱ��set����ʽ�ϲ�(�߶����ϲ�)
������ͨ���ڵ����ӣ��ֺڰ���ɫ��level�����߶����ϲ� 
Ȼ�����ֱ�ߡ���ͨ�ֱ�ά��
��ͨ·�����һ�¾ͺ��ˣ���������ֻ��4��
ʱ�临�Ӷȿ������� O(Tnlog_2n) 
������ûʱ���ˣ�����ֻ��һ�ݱ�����û�뵽��Ȼ�������ݽṹ�ϣ����� 
Bye~
*/
//There's no shit but you.
