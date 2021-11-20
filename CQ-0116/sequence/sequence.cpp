#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const ll mo = 998244353;
int n,m,K;
ll f[2][1<<18],v[31];
void work(){
	f[0][0]=1;int S=(1<<m)*n;
	ll ans=0;int now=1,pre=0;
	for(int i=0;i<n;i++,pre^=1,now^=1){
		memset(f[now],0,sizeof f[now]);
		for(int j=0;j<=S;j++)
		if(f[pre][j]){
			for(int k=0;k<=m;k++){
				int jj = j+(1<<k);
				f[now][jj]+=f[pre][j]*v[k]%mo;
				if(f[now][jj]>=mo)f[now][jj]%=mo;
			}
		}
	}for(int i=1;i<=S;i++){
		int cnt=0;
		for(int j=31;j>=0;j--)cnt+=((i>>j)&1);
		if(cnt<=K)ans+=f[pre][i];
		if(ans>=mo)ans%=mo;
	}printf("%lld\n",ans);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<=m;i++)scanf("%lld",v+i);
	if(m<=12)work();
	return 0;
}

