#include<cstdio>
typedef long long ll;
const int M=105,mod=998244353;
int n,m,k,a[M];
inline int ppc(ll x){
	int sum(0);while(x)sum+=x&1,x>>=1;return sum;
}
namespace sub1{
	int ans,x[M];
	inline ll f(const int&len){
		ll sum(0);for(int i=1;i<=len;++i)sum+=1ll<<x[i];return sum;
	}
	inline int CAL(const int&len){
		int prod(1);for(int i=1;i<=len;++i)prod=1ll*prod*a[x[i]]%mod;return prod;
	}
	void DFS(const int&id,const int&len){
		if(id==len+1)return ppc(f(len))<=k&&(ans=(ans+CAL(len))%mod),void();
		for(int i=0;i<=m;++i)x[id]=i,DFS(id+1,len);
	}
	inline void main(){
		DFS(1,n);printf("%d",ans);
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int i;scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<=m;++i)scanf("%d",a+i);
	if(n<=10)return sub1::main(),0;
	else return printf("ÄãÊÇÒ»¸öÒ»¸öÒ»¸ö£¡Ò»¸öÒ»¸öÒ»¸öºßºß°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡£¡£¡£¡"),0;
}
