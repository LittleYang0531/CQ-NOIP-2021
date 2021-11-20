#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
const ll inf=1e18;
ll n,a[maxn];
ll seq[maxn],ans=inf;
unordered_map<string,int> vis;
void dfs(int step){
	string tmp;
	tmp.clear();
	for(int i=1;i<=n;++i){
		int now=seq[i],st[15],top=0;
		while(now) st[++top]=now%10,now/=10;
		while(top) tmp+=char(st[top--]+'0');
		tmp+=' ';
	}
	if(vis.count(tmp)) return;
	vis[tmp]=1;
	ll avg=0,res=0;
	for(int i=1;i<=n;++i) avg+=seq[i];
	for(int i=1;i<=n;++i) res+=(n*seq[i]-avg)*(n*seq[i]-avg);
	res/=n;
	ans=min(ans,res);
	for(int i=2;i<=n-1;++i){
		int S=seq[i];
		seq[i]=seq[i+1]+seq[i-1]-seq[i];
		if(seq[i]!=S) dfs(step+1);
		seq[i]=S;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		seq[i]=a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
