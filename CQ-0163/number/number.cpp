#include<cstdio>
#include<algorithm>
const int Q=10000005;
const int P=200005;
const int O=100002;
const int N=800005;
const int INF=(1<<30);
#define gc() getchar()
typedef long long ll;
#define rg register int
#define cint const register int
inline bool ig(char c){return c>='0'&&c<='9';}
inline void read(int&oi){int res=0,f=1;char c;while(c=gc(),c^'-'&&!ig(c));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(int oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+48);}
inline void write(int oi,char c){print(oi);putchar(c);}
inline int max(cint x,cint y){return x>y?x:y;}
int ans[N],tot,Mx;
bool vst[Q];
inline bool check(cint x){for(rg p=x;p;p/=10)if(p%10==7)return 1;return 0;}
inline void Sieve(cint V){
	for(rg i=1;i<=V;++i){
		if(vst[i])continue;
		bool chk=check(i);if(!chk)ans[++tot]=i;
		else{for(rg j=1;j*i<=V;++j)vst[i*j]=1;}
	}
}
int C,X[P];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(C);for(rg i=1;i<=C;++i)read(X[i]),Mx=max(Mx,X[i]);
	if(Mx<=200000){
		Sieve(Mx+O);for(rg i=1;i<=C;++i){
			cint x=X[i];if(vst[x])write(-1,'\n');
			else write(ans[std::upper_bound(ans+1,ans+1+tot,x)-ans],'\n');
		}return 0;
	}else{
		Sieve(10000001);for(rg i=1;i<=C;++i){
			cint x=X[i];if(vst[x])write(-1,'\n');
			else write(ans[std::upper_bound(ans+1,ans+1+tot,x)-ans],'\n');
		}return 0;
	}
	return 0;
}
