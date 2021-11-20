#include<bits/stdc++.h>
using namespace std;
namespace ljh{
	#define int long long
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
const int mod=998244353,inf=1<<17;
struct node{
	int num,k;
	bool operator<(const node&a)const{
		return num<a.num;
	}
}e[inf+5];
int wh,n,m,k,v[105],ans;
bool tong[inf+5];
int f(int l,int r,int x){
	if(l>=r)return l;
	int mid=l+r>>1;
	if(e[mid].num>x)return f(l,mid,x);
	return f(mid+1,r,x);
}void dfs(int x,int tot,int sum){
	if(x>n){
		if(tong[sum])ans=(tot+ans)%mod;
		return;
	}
	for(int i=0;i<=m;++i){
		dfs(x+1,(tot*v[i])%mod,sum+(1<<i));
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=1;i<=inf;++i){
		int u=i,sum=0;
		while(u)sum+=(u&1),u>>=1;
		e[i].k=i,e[i].num=sum;
	}sort(e+1,e+1+inf);
	read(n,m,k);
	wh=f(1,inf,k);
	for(int i=1;i<=wh;++i)tong[e[i].k]=1;
	for(int i=0;i<=m;++i)read(v[i]);
	dfs(1,1,0);
	write(ans);
	return 0;
}

