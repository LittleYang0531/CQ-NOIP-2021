#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int p[N];
bool st[N];
int t;
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
void prepare(int y){
	int m;
	if(y <= 10) m = 100;
	else if(y <= 100) m = 1000;
	else if(y <= 1000) m = 10000;
	else if(y <= 10000) m = 2 * 1e5;
	else if(y <= 2 * 100000) m = 1e7;
	for(int i = 1; i < m ; i ++){
		int x = i;
		while(x){
			if(x % 10 == 7){
				st[i] = true;
				break;
			}
			x /= 10;
		}
		if(st[i]){
			for(int j = 2; j * i <= m; j ++)
				st[i * j] = true;
		}
	}
}
void solve(){
	
	while(t --){
		int n = read();
//		cout << n << endl;
		if(st[n]){
			cout << "-1" << endl;
			continue;
		}
		n ++;
		while(st[n] == true)
			n ++;
		cout << n << endl;
	}
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	t = read();
	prepare(t);
	solve();
	return 0;
}
