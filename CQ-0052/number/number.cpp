#include  <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10, lim = 1e7;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
struct node{
	int v, w; //分别表示数和位数 
};
int T;
int top, sck[N];
bool vis[N], tr[4*N];
queue<node> q;
inline void initial()
{
	q.push((node){7, 1});
	sck[++top] = 7;
	while(!q.empty()){
		node x = q.front(); q.pop();
		int y = 1;
		//在前面加
		for(register int i = 1; i <= x.w; i++) y *= 10;
		for(register int dw = 1, i = 1; ; i *= 10, dw++){
			if(i * y + x.v > lim) break;
			for(register int j = 1; j <= 9; j++){
				int to = j * i * y + x.v;
				if(to > lim) break;
				if(vis[to]) continue;
				sck[++top] = to, vis[to] = true, q.push((node){to, x.w + dw}); 
			}
		}
		for(register int i = 0; i <= 9; i++){
			int to = x.v * 10 + i;
			if(to > lim) break;
			if(vis[to]) continue;
			sck[++top] = to, vis[to] = true, q.push((node){to, x.w + 1});
		}
	}
	for(register int i = 1; i <= top; i++)
		for(register int j = 2; sck[i] * j <= lim; j++) vis[sck[i]*j] = true;
}
inline void build(int k, int l, int r)
{
	if(l == r){
		tr[k] = vis[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid), build(k << 1 | 1, mid + 1, r);
	if(tr[k<<1] && tr[k<<1|1]) tr[k] = true;
	else tr[k] = false; 
}
inline bool ask(int k, int l, int r, int x, int y)
{
	if(r < x || l > y) return true;
	if(l >= x && r <= y) return tr[k];
	int mid = (l + r) >> 1;
	bool a = ask(k << 1, l, mid, x, y), b = ask(k << 1 | 1, mid + 1, r, x, y);
	if(a && b) return true;
	else return false;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	initial();
	build(1, 1, lim);
	T = read();
	while(T--){
		int x = read();
		if(vis[x]) puts("-1");
		else{
			int l = x + 1, r = lim, res = lim + 1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(ask(1, 1, lim, x + 1, mid)) l = mid + 1;
				else res = mid, r = mid - 1;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
