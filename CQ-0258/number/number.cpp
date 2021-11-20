#include<bits/stdc++.h>
using namespace std;
namespace helloioi{
#define LL long long
#define db double 
#define f(a,b,i) for(register int i=a;i<=b;i++)
#define f_(a,b,i) for(register int i=a;i>=b;i--)
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

#define N 10000006

bool p[N];
inline void pre(){
	int x,f; 
	
	f(1,N-2,i){
		if(p[i])continue;
		x=i;
		f=0;
		while(x){
			if(x%10==7){
				f=1;
				break;
			}
			x/=10;
		}
		if(f){
			for(register int j=1;i*j<=N-2;j++){
				p[i*j]=1;
			}
		}
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	pre();
//	f(1,N-2,i)cout<<p[i]<<" ";
	int T;
	read(T);
	int x;
	while(T--){
		read(x);
		if(p[x]){
			printf("-1\n");
			continue;
		}
		while(x++){
			if(!p[x]){
				printf("%d\n",x);
				break;
			}
		}
	}
	return 0;
}
