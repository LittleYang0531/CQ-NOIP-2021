#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e4+5;
vector<int> a;
map<vector<int>,bool> b;
int n,ssu,ss1,ans;
void dfs(){
	if(b[a]) return;
	b[a]=1;
	for(int i=1;i<n-1;i++) if(a[i]!=a[i-1]+a[i+1]-a[i]){
		ssu-=a[i];
		ss1-=a[i]*a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		ssu+=a[i];
		ss1+=a[i]*a[i];
		dfs();
		ssu-=a[i];
		ss1-=a[i]*a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		ssu+=a[i];
		ss1+=a[i]*a[i];
	}
	ans=min(ans,ss1*n-ssu*ssu);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int c;
		scanf("%d",&c);
		a.push_back(c);
		ssu+=c;
		ss1+=c*c;
	}
	ans=ss1*n-ssu*ssu;
	dfs();
	printf("%d",ans);
	return  0;
}
