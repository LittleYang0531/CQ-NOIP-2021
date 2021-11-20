#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=101,p=998244353;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

int n,m,k,ans,mx;
int a[N],v[N],vis[10100010];
void dfs(int num,int res,int sum) {
	if(num==n+1) {
		if(vis[res]==0) return ;
		ans=(ans+sum)%p;
		return ;
	}
	for(int i=0;i<=m;++i) {
		a[num]=i;
		if(res+(1ll<<a[num])>mx) continue;
		dfs(num+1,res+(1ll<<a[num]),(sum*v[a[num]])%p);
	}
}

signed main() {
	
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	//freopen("sequence2.in","r",stdin);
	//freopen("T2.out","w",stdout);
	
	//double st=clock();
	
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;++i) v[i]=read(); 
	for(int i=n;i<=n*(1ll<<m);++i) {
		int t=0,s=i,flag=1;
		while(s) {
			int h=s%2;
			if(h==1ll) ++t;
			if(t>k) {
				flag=0; break;
			}
			s>>=1;
		}
		if(flag==1) {
			vis[i]=1;
			mx=max(i,mx);
		}
	}
	dfs(1,0,1);
	printf("%lld\n",ans);
	
	//double en=clock();
	//printf("%.3lf",en-st);
	
	return 0;
}
