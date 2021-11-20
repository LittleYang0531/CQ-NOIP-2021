#include<bits/stdc++.h>
using namespace std;
namespace ljh{
	#define ll long long
	template<typename T>
	void read(T&x){
		x=0;
		char ch;
		bool some=0;
		while((ch=getchar())<'0'||ch>'9')some|=ch=='-';
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
		if(some)x=-x;
	}
	template<typename T,typename...Args>
	void read(T&x,Args&...args){read(x),read(args...);}
	template<typename T>
	void write(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+48);
	}
	template<typename T,typename...Args>
	void write(T x,Args...args){write(x),putchar(' '),write(args...);}
}using namespace ljh;
const int inf=1e4+5;
ll a[inf],n,ans=1<<30;
void dfs(int x,int sum1,int sum2){
	if(ans<=sum2*n-sum1*sum1)return;
	if(x>n){
		ans=sum2*n-sum1*sum1;
		return;
	}dfs(x+1,sum1+a[x],sum2+a[x]*a[x]);
	int dd=a[x];
	a[x]=a[x-1]+a[x+1]-a[x];
	dfs(x+1,sum1+a[x],sum2+a[x]*a[x]);
	a[x]=a[x-1]+a[x+1]-a[x];
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	dfs(1,0,0);
	write(ans);
	return 0;
}

