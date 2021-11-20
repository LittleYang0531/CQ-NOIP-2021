//_zzi_ orz jzm ppl xez xyx xjx dym zxy wxk llsw they are yyds!!!
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+5;
const int base = 23333;
const int mo = 998244353;
const LL INF = 0x3f3f3f3f3f3f3f3f;
#define int LL
int readint(){
	int x=0,f=1;char s=getchar();
	#define sc (s=getchar())
	while(s<'0'||s>'9'){
		if(s=='-')
			f=-1;
		sc;
	}
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		sc;
	}
	#undef sc
	return x*f;
}
map<LL,bool> vis;
int n,cnt;
LL ans;
int a[maxn];
LL gethash(){
	LL hash=0;
	for(int i=1;i<=n;i++)
		hash=(1ll*hash*base%mo+a[i])%mo;
	return (hash%mo+mo)%mo;
}
void check(){
	cnt++;
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	LL res=0;
	for(int i=1;i<=n;i++){
		res+=(1ll*(0ll+1ll*a[i]*n-sum)*(0ll+1ll*a[i]*n-sum));
	}
	ans=min(ans,res/n);
}
void dfs(){
	if(cnt*n>=2e8){
		check();
		printf("%lld\n",ans);
		exit(0);
	}
	if(vis[gethash()])
		return;
	vis[gethash()]=1;
	check();
//	cout<<cnt<<endl;
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
//	cout<<gethash()<<endl;
	for(int i=2;i<n;i++){
		int x=a[i];
		a[i]=a[i-1]+a[i+1]-x;
		if(vis[gethash()]){
			a[i]=x;
			continue;
		}
		dfs();
		a[i]=x;
	}
}
signed main (){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ans=INF;
	n=readint();
	for(int i=1;i<=n;i++){
		a[i]=readint();
	}
	check();
	if(ans==0){
		printf("%lld\n",ans);
		return 0;
	}
	dfs();
	printf("%lld",ans);
	return 0;
}
