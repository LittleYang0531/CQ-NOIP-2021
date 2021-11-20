#include<bits/stdc++.h>
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXX 10000005
using namespace std;

namespace _MAIN{
	int n, lim = 10000000;
	inlint read(){
		register int nega = 1, num = 0, c = getchar();
		for(;~c&&!isdigit(c);c=getchar()) if(c=='-')nega=-1;
		for(;~c&& isdigit(c);c=getchar()) (num*=10)+=c-'0';
		return nega * num;
	}
} using namespace _MAIN;

namespace _SOLV{
	inbool has7(int x) {
		for(;x;x/=10) if(x % 10 == 7) return true;
		return false;
	}
	int m7f[MAXX], seq7[MAXX], cnt;
	inloid euler_7() {
		for(int i = 7; i <= lim; i++) {
			if(m7f[i]) continue;
			if(has7(i)) {
				m7f[i] = seq7[++cnt] = i;
				for(int j = 1; i * j <= lim; j++) {
					m7f[i * j] = i;
				}
			} else {
				for(int j = 1; j <= cnt && seq7[j] * i <= lim; j++) {
					m7f[i * seq7[j]] = seq7[j];
					if(i % seq7[j] == 0) break;
				}			
			}
		}
	}
	int l[MAXX], r[MAXX];
} using namespace _SOLV;

signed main(void){
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	for(int i = 1; i <= lim; i++) l[i] = i - 1, r[i] = i + 1;
	r[0] = 1, l[lim + 1] = lim;
	euler_7();
	for(int i = 1; i <= lim; i++) {
		if(m7f[i]) {
			l[r[i]] = l[i], r[l[i]] = r[i];
		}
	}
	for(int t = read(); t--; ){
		int a = read();
		if(m7f[a]) cout << "-1\n";
		else cout << r[a] << "\n";
	}
	return fclose(stdin), fclose(stdout), 0;
}

