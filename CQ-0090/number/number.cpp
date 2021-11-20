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

const int maxn = 1e7+10;

short f[maxn];
int p[maxn/10],pc;
bool is[maxn];

bool ppp(int x) {
	while(x) {
		if(x%10==7)
			return 1;
		x/=10;
	}
	return 0;
}

int ok(int x) {
	if(f[x]!=0) return f[x];
	if(x%7==0) return f[x]=1;
	if(ppp(x)) return f[x]=1;
	for(int i=2;i*i<=x;++i)
		if(x%i==0 && (ppp(i) || ppp(x/i))) {
			return f[x]=1;
		}
	return f[x]=-1;
}

void sieve() {
	for(int i=2;i<=maxn-5;++i) {
		if(!is[i]) p[++pc]=i;
		for(int j=1; j<=pc && 1ll*i*p[j]<=maxn-5; ++j) {
			is[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}

void init() {
	int tmp;
	for(int x=1;x<=1e7;++x) {
		if(x%7==0) {
			f[x]=1; continue;
		}
		if(ppp(x)) {
			f[x]=1; continue;
		} 
		tmp=x;
		for(int i=1; i<=pc && 1ll*p[i]*p[i]<=tmp; ++i)
			if(x%p[i]==0) {
				while(tmp%p[i]==0)
					tmp/=p[i];
				if(f[x/p[i]]==1 || f[p[i]]==1) {
					f[x]=1; break;
				}
			}
		if(!f[x]) {
			if(f[x/tmp]==1 || f[tmp]==1)
				f[x]=1;
			else f[x]=-1;
		}
	}
}

int OK(int x) {
	if(f[x]!=0) return f[x];
	if(x%7==0) return f[x]=1;
	if(ppp(x)) return f[x]=1;
	int tmp=x;
	for(int i=1; i<=pc && 1ll*p[i]*p[i]<=x; ++i)
		if(x%p[i]==0) {
			while(tmp%p[i]==0)
				tmp/=p[i];
			if(OK(x/p[i])==1) {
				f[x]=1; break;
			}
		}
		print(x,'\n');
	if(!f[x]) {
		if(OK(x/tmp)==1)
			f[x]=1;
		else f[x]=-1;
	}
	return f[x];
}

void work(int T) {
	while(T--) {
		int x=read(9);
		if(ok(x)==1) {
			puts("-1"); continue;
		}
		for(int i=x+1;;++i) {
			if(ok(i)==-1) {
				print(i,'\n');
				break;
			}
		}
	}
}

void OMG(int T) {
	for(;T;--T) {
		int x=read(9);
		if(OK(x)==1) {
			puts("-1"); continue;
		}
		for(int i=x+1;;++i) {
			if(OK(i)==-1) {
				print(i,'\n');
				break;
			}
		}
	}
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=read(9); f[1]=-1;
//	OMG(T); return 0;
	if(T<=10000) {
		work(T);
		return 0;
	}
	sieve();
	init(); 
	for(;T;--T) {
		int x=read(9);
		if(ok(x)==1) {
			puts("-1"); continue;
		}
		for(int i=x+1;;++i) {
			if(ok(i)==-1) {
				print(i,'\n');
				break;
			}
		}
	}
	return 0;
}
