#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 1e5;
int n, m, k;
int l, r;
int s[N], top;
int sum;
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
	return x;
}
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), m = read(), k = read();
	int w = 1;
	for(int i = 1; i <= m; i ++)
		w = w * 2;
	l = n; r = n * w;
	for(int i = l; i <= r; i ++)
	{
		int sum = 0;
		int x = i;
		while(x){
			if(x & 1)
				sum ++;
			x >>= 1;	
		}
		if(sum <= k)
			s[++ top] = i;
	}
	cout << s[1] * 5 << endl;
	return 0;
}
