#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
const int maxn=1e4+5,bas=1455211,mod=1e9+9,lim=1.8e7;
int a[maxn],n,cnt,b[maxn];
ll ans=1e18;
unordered_map<ll,bool> maps;
ll cal() {
	ll sum=0,res=0;
	for(int i=1; i<=n; i++)sum+=a[i],res+=a[i]*a[i];
	return n*res-sum*sum;
}
ll gethash() {
	ll v=0;
	for(int i=1; i<=n; i++)v=(v*bas+a[i])%mod;
	return v;
}
bool pd(ll now,ll lst) {
	int v=log(now-lst)+1;
	return rand()%v==0;
}
void dfs(ll lst) {
	ll h=gethash();
	if(maps[h])return;
	if((++cnt)*n>lim)printf("%lld",ans),exit(0);
	ll now=cal();
	if(now>lst&&!pd(now,lst))return;
	maps[h]=1,ans=min(ans,now);
//	for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
	for(int i=2; i<n; i++)b[i]=i;
	random_shuffle(b+2,b+n);
	for(int i=2; i<n; i++) {
		int u=b[i],x=a[u];
		if(x==a[u-1]+a[u+1]-x)continue;
		a[u]=a[u-1]+a[u+1]-x,dfs(now),a[u]=x;
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	n=read();
	for(int i=1; i<=n; i++)a[i]=read();
	dfs(ans);
	printf("%lld",ans);
	return 0;
}
//你是一个一个一个，一个一个一个哼哼啊啊啊啊啊啊啊啊啊啊啊啊！1145141919810

