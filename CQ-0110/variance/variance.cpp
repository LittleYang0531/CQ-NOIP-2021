#include<bits/stdc++.h>
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXN 10005
#define DELTA 0.995
#define eps 1e-6
#define int long long
using namespace std;

namespace _MAIN{
	int n;
	inlint read(){
		register int nega = 1, num = 0, c = getchar();
		for(;~c&&!isdigit(c);c=getchar()) if(c=='-')nega=-1;
		for(;~c&& isdigit(c);c=getchar()) (num*=10)+=c-'0';
		return nega * num;
	}
} using namespace _MAIN;

namespace _SOLV{
	int pseq[MAXN], seq[MAXN];
	int sum, po2s;
	int ms = 0, mp2s = 0x3f3f3f3f;
	inloid sa() {
		sum = po2s = 0;
		for(int i = 1; i <= n; i++) seq[i] = pseq[i], sum += seq[i], po2s += seq[i] * seq[i];
		for(double t = 10000000; t > eps; t *= DELTA) {
			for(int i = 2; i < n; i++) {
				int afS = sum + seq[i-1]+seq[i+1]-seq[i] - seq[i];
				int afP = po2s + (seq[i-1]+seq[i+1]-seq[i])*(seq[i-1]+seq[i+1]-seq[i]) - seq[i]*seq[i];
				if(afP * n - afS*afS < po2s * n - sum * sum) {
					seq[i] = seq[i - 1] + seq[i + 1] - seq[i];
					sum = afS, po2s = afP;
				} else if((rand() & 1) && (10000 * log2(t) / log2(2.71828)> rand())) {
					seq[i] = seq[i - 1] + seq[i + 1] - seq[i];
					sum = afS, po2s = afP;
				}
			}
		}
		if(po2s * n - sum * sum < mp2s * n - ms * ms){
			mp2s = po2s, ms = sum;
//			for(int i = 1; i <= n; i++) cout << seq[i] << " ";
//			cout << "\n";
		}
	}
} using namespace _SOLV;

signed main(void){
	freopen("variance.in", "r", stdin), freopen("variance.out", "w", stdout);
	srand((unsigned)time(NULL));
	n = read();
	for(int i = 1; i <= n; i++) pseq[i] = read();
	sa(), sa(), sa(), sa(), sa();
	cout << mp2s * n - ms * ms << "\n";
	return fclose(stdin), fclose(stdout), 0;
}

