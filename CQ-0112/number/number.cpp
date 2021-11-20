#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=10000003;
int num7[maxn],n,cnt;
bool vis[maxn];
void sieve(int n){
	for(int i=2;i<=n;++i){
		if(vis[i]) continue;
		int k=i;
		while(k){
			if(k%10==7) {vis[i]=1;break;}
			k/=10;
		}
		if(vis[i]) for(int j=i;j<=n;j+=i) vis[j]=1;
		else num7[++cnt]=i;
	}
}
int read(){
	char c=getchar();int x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	sieve(10000000);num7[++cnt]=10000001;
	int T=read();
	while(T--){
		int x=read();
		int pos=lower_bound(num7+1,num7+cnt+1,x)-num7;
		if(num7[pos]==x) cout<<num7[pos+1]<<'\n';
		else puts("-1");
	}
	return 0;
}
