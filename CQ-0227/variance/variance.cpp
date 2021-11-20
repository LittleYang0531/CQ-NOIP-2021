#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=4;
const int Maxm=10;
int a[Maxn+5],mark[Maxm+5][Maxm+5][Maxm+5][Maxm+5],n,ans;
void dfs(int dep) {
	if(mark[a[1]][a[2]][a[3]][a[4]])return ;
	mark[a[1]][a[2]][a[3]][a[4]]=1;
	int now=0,sum=0;
	for(ri i=1;i<=n;i++)sum+=a[i];
	for(ri i=1;i<=n;i++)now+=(n*a[i]-sum)*(n*a[i]-sum);
	ans=min(ans,now/n);
	for(ri i=2;i<n;i++) {
		int t=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		dfs(dep+1);
		a[i]=t;
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(ri i=1;i<=n;i++)scanf("%d",&a[i]);
	ans=1e9;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}

