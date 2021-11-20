#include <cstdio>
#define print(x,y) write(x),putchar(y)

template <class T>
inline T read(const T sample) {
	T x=0; char s; bool f=0;
	while((s=getchar())>'9' || s<'0')
		f |= (s=='-');
	while(s>='0' && s<='9')
		x = (x<<1)+(x<<3)+(s^48),
		s = getchar();
	return f?-x:x;
}

template <class T>
inline void write(T x) {
	static int writ[40],w_tp=0;
	if(x<0) putchar('-'),x=-x;
	do writ[++w_tp]=x-x/10*10,x/=10; while(x);
	while(w_tp) putchar(writ[w_tp--]^48);
}

const int mod = 998244353;

int n,m,k,w[105];

inline int inc(int x,int y) {
	return x+y>=mod?x+y-mod:x+y;
}

namespace OVO {
	const int SIZE = 122885;
	
	int dp[2][SIZE];
	
	void work() {
		int lim = (1<<m)*n, bas;
		dp[0][0]=1;
		for(int i=0;i<n;++i) {
			bool d = (i&1);
			for(int s=0;s<lim;++s) {
				if(!dp[d][s]) continue;
				bas=1;
				for(int j=0;j<=m;++j) {
					dp[d^1][s+bas] = inc(dp[d^1][s+bas],1ll*dp[d][s]*w[j]%mod);
					bas <<= 1;
				}
				dp[d][s]=0;
			}
		}
		int ans=0;
		for(int i=0;i<=lim;++i)
			if(__builtin_popcount(i)<=k)
				ans = inc(ans,dp[n&1][i]);
		print(ans,'\n');
	}
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(8),m=read(9),k=read(9);
	for(int i=0;i<=m;++i)
		w[i]=read(9);
	OVO::work();
	return 0;
}

/*
1-4 直接枚举
好耶！状压有 50pts 
*/
