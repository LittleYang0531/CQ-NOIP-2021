#include<bits/stdc++.h>
using namespace std;
template<typename F>inline void read(F &n){
	F w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch&15);ch=getchar();}
	n*=w;
}
typedef long long ll;
const int N=1e4+5;
int n,vis[N];ll a[N],ans=1e18;
void dfs(int i){
	if(i>n-2){
		ll x=0,y=0;
		for(int i=1;i<=n;++i){
			x+=a[i]*a[i];y+=a[i];
		}
		ans=min(ans,x*n-y*y);
		return;
	}
	dfs(i+1);
	for(int i=2;i<n;++i)
	if(vis[i]<=2){
		vis[i]++;a[i]=a[i+1]+a[i-1]-a[i];
		dfs(i+1);
		vis[i]--;a[i]=a[i+1]+a[i-1]-a[i];
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
