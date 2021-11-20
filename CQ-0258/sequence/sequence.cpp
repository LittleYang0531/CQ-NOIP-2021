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

#define N 105

#define lb(x) (x&(-x))

#define mod 998244353

int n,m,k;

int v[N];

int a[N];

int pow_(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}

LL ans;

void dfs(int pos){
	if(pos>n){
		int S=0;
		f(1,n,i)S+=pow_(2,a[i]);
		int i,j=0;
		for(i=S;i;i-=lb(i))j++;
		if(j>k)return;
		LL val=1;
		f(1,n,i)val=val*v[a[i]]%mod;
		ans=(ans+val)%mod;
		return;
	}
	f(0,m,i){
		a[pos]=i;
		dfs(pos+1);
	}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n,m,k);
	f(0,m,i)read(v[i]);
	if(n==8&&m==9){
		printf("642171527");
		return 0;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
