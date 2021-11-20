/*NE*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int readInt()
{
	bool neg = 0;
	int num = 0;
	
	char c = getchar();
	
	while(c==' ' || c=='\n')	c = getchar();
	while(c == '-')	neg = !neg,	c = getchar();
	while(c>='0' && c<='9')	num += (num<<1) + (num<<3) + c - '0',	c = getchar();
	
	return neg ? -num : num;
}

const int MOD = 998244353;
const int M = 104;
const int N = 32;

int n, m, k;
int v[M], a[N];
int sum = 0;
bool pow[112];

bool legal()
{
	memset(pow, 0, sizeof(pow));
	
	for(int i=1; i<=n; ++i){
		if(!pow[a[i]])
			pow[a[i]] = 1;
		else{
			pow[a[i]] = 0;
			int tmp = a[i] + 1;
			while(pow[tmp]){
				pow[tmp] = 0;
				++tmp;
			}
			pow[tmp] = 1;
		}
	}
	
	int lg = 0;
	
	int maxx = m + 6;
	
	for(int i=0; i<=maxx; ++i)
		lg += pow[i];
	
	return lg <= k;
}

int calc()
{
	int tmp = 1;
	
	for(int i=1; i<=n; ++i)
		tmp = (long long)tmp * v[a[i]] % MOD;
	
	return tmp;
}

void solve(int step)
{
	if(step == n+1){
		if(legal()){
			sum = (sum + calc() % MOD) % MOD;
		}
		return;
	}
	
	for(int i=0; i<=m; ++i){
		a[step] = i;
		solve(step + 1);
	}
	
	return;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	n = readInt();
	m = readInt();
	k = readInt();
	
	for(int i=0; i<=m; ++i){
		v[i] = readInt();
	}
	
	solve(1);
	
	printf("%d", sum);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
