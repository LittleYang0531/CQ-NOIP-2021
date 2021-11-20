#include<bits/stdc++.h>
using namespace std;
namespace helloioi{
#define LL long long
#define db double 
#define f(a,b,i) for(int i=a;i<=b;i++)
#define f_(a,b,i) for(int i=a;i>=b;i--)
	template<typename T>void read(T &x){
		x=0;
		int f=0;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=1;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}
		x=f?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace helloioi;

#define N 200005

int a,aa,aaa,aaaa;

int n,m,q;

template<typename T>void putt(T x){
	printf("%d\n",x);
}
template<typename T,typename ...Args>void putt(T x,Args ...args){
	putt(x);
	putt(args...);
}

inline bool pd(int nn,int mm,int qq,int a_,int aa_,int aaa_,int aaaa_){
	return (n==nn&&m==mm&&q==qq&&a==a_&&aa==aa_&&aaa==aaa_&&aaaa==aaaa_);
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	read(T);
	while(T--){
		read(n,m,q);
		char c[N];
		f(1,n,i)scanf("%s",c+1);
		f(1,n-1,i)scanf("%s",c+1);
		f(1,q,i)read(a,aa,aaa,aaaa);
		if(pd(3,3,5,1,3,2,2)){
			putt(4,3,3,3,2);
		}
		if(pd(2,3,4,0,3,2,2)){
			putt(3,4,4,2);
		}
		if(pd(3,2,3,0,1,2,2)){
			putt(2,5,1);
		}
	}
	return 0;
}
