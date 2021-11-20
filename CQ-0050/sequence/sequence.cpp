#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
bool st;
const int N=35,M=110,p=998244353;
int n,m,K,v[M],ans;
unordered_map<int,int> f[N];
bool ed;
signed main(){
//	printf("%.2lf MB\n",abs(&ed-&st)/1024.0/1024.0);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),K=read();For(i,0,m)v[i]=read(),f[1][1<<i]=v[i];
	For(i,1,n-1){
		for(auto val:f[i])For(j,0,m)(f[i+1][val.first+(1<<j)]+=1ll*val.second*v[j]%p)%=p;
	}
	for(auto v:f[n])if(__builtin_popcount(v.first)<=K)(ans+=v.second)%=p;
	cout<<ans<<endl;
	return 0;
}
