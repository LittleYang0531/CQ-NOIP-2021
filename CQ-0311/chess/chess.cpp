#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e7;
int e[M], idx, ne[M], h[M], st[M];
int flag[M], flag3[M];
struct node{
	int cl, lv;
}chess[M];
int sum;
void add(int a, int b, int c){
	ne[idx] = h[a], e[idx] = b, st[idx] = c, h[a] = idx ++;
}
int read(){
	int x = 0, p = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')
			p = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x * p;
}
void dfs(int rt, int f, int f2, int root){
//	cout << "root : " << rt / 10 << " " << rt % 10 << endl;
	for(int i = h[rt]; ~i; i = ne[i])
	{
		int j = e[i];
		int f3 = abs(rt - j);
		int flag2 = 0;
//		cout << "roots : " << chess[rt].cl << " " << chess[rt].lv << endl;
//		cout << "nexts : " << chess[j].cl << " " << chess[j].lv << endl;
		if((chess[j].cl == chess[root].cl && chess[j].lv != 0) || chess[root].lv < chess[j].lv)
			continue;
//		cout << "next : " << j / 10 << " " << j % 10 << " st : " << st[i] << " flag2 : " << flag2 <<endl ;
		if(chess[j].lv != 0)
			flag2 = 1;
		if(st[i] == 1 && !flag[j] && f == 0)
		{
			if(!flag3[j])
				sum ++;
			flag3[j] = 1;
			flag[j] = 1;
			continue;
		}
		if(st[i] == 2 && (f == 0 || f == 2) && !flag[j] && (f3 == f2 || f2 == 0)){
			if(!flag3[j])
				sum ++;
			flag3[j] = 1;
			flag[j] = 1;
			if(!flag2)
				dfs(j, 2, f3, root);
			flag[j] = 0;
		}
		if(st[i] == 3 && (f == 0 || f == 3) && !flag[j]){
			if(!flag3[j])
				sum ++;
			flag3[j] = 1;
			flag[j] = 1;
			if(!flag2)
				dfs(j, 3, f3, root);
			flag[j] = 0;
		}
	}
}
int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int t;
	cin >> t;
	while(t --){
		int n, m, k;
		memset(h, -1, sizeof h);
		memset(flag, 0, sizeof flag);
		memset(chess, 0, sizeof chess);
		string a1[N], a2[N];
		n = read(), m = read(), k = read();
		for(int i = 1; i <= n; i ++)
		{
			cin >> a1[i];
			a1[i] = '0' + a1[i];
			for(int j = 1; j < a1[i].size(); j ++){
				int p = a1[i][j] - '0';
				int now = i * 10 + j, next = now + 1;
				if(p == 0)
					continue;
				add(now, next, p);
				add(next, now, p);
			}
		}	
		for(int i = 1; i < n; i ++)
		{
			cin >> a2[i];
			a2[i] = '0' + a2[i];
			for(int j = 1; j < a2[i].size(); j ++){
				int p = a2[i][j] - '0';
				int now = i * 10 + j, next = now + 10;
				if(p == 0)
					continue;
				add(now, next, p);
				add(next, now, p);
			}
		}	
		for(int i = 1; i <= k; i ++)
		{
			sum = 0;
			memset(flag, 0, sizeof flag);
			memset(flag3, 0, sizeof flag3);
			int cl, lv, x1, y1;
			cl = read(), lv = read(), x1 = read(), y1 = read();
			int root = x1 * 10 + y1;
			chess[root].cl = cl;
			chess[root].lv = lv;
//			cout << "begin :" << endl;
			flag[root] = 1;
			dfs(root, 0, 0, root);
//			cout << "end" << endl;
			cout << sum << endl;
		}
	}
	return 0;
}
