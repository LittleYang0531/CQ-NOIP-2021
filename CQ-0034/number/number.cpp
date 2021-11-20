#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long llong;
inline int readint(){
	int a = 0, c = getchar(), f = 1;
	for(; !isdigit(c); c=getchar())
		if(c == '-') f = -f;
	for(; isdigit(c); c=getchar())
		a = (a*10)+(c^48);
	return a*f;
}
void writeint(unsigned x){
	if(x > 9) writeint(x/10);
	putchar(char((x%10)^48));
}

const int MAXN = 10000003;
bool isSeven[MAXN], isPrime[MAXN], isBad[MAXN];
int primes[MAXN], primes_size = 0;
void sieve(int n = MAXN-1){
	static int least[MAXN], nxt[MAXN];
	memset(isPrime+2,true,n-1);
	rep(i,2,n){
		if(isPrime[i]){
			primes[++ primes_size] = i;
			least[i] = i, nxt[i] = 1;
		}
		isSeven[i] = (i%10 == 7) || isSeven[i/10];
		const int bound = n/i;
		for(int j=1; j<=primes_size&&primes[j]<=bound; ++j){
			isPrime[i*primes[j]] = false;
			least[i*primes[j]] = primes[j];
			if(i%primes[j] == 0){
				nxt[i*primes[j]] = nxt[i];
				break;
			}
			nxt[i*primes[j]] = i;
		}
	}
	memcpy(isBad+1,isSeven+1,n);
	rep(i,2,n) for(int t=i; !isBad[i]&&t!=1; t=nxt[t])
		isBad[i] = isBad[i/least[t]]; // from divisor
}

int nxt[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	sieve();
	drep(i,MAXN-2,1) // pre-compute
		if(isBad[i]) nxt[i] = nxt[i+1];
		else nxt[i] = i;
	for(int T=readint(); T; --T){
		int n = readint();
		if(isBad[n]) puts("-1");
		else writeint(nxt[n+1]), putchar('\n');
	}
	return 0;
}
