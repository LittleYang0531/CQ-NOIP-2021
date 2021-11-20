#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int n,a[maxn],d[maxn],mins=INT_MAX,ans[maxn];
bool vis[maxn];
int p();
void dfs(int x);
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2)d[i]=a[i]-a[i-1];
	}
	ans[1]=a[1];
	dfs(2);
	cout<<mins;
	return 0;
}
int p(){
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		x+=ans[i]*ans[i];
		y+=ans[i];
	}
	return x*n-y*y;
}
void dfs(int x){
	if(x>n){
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
		for(int i=2;i<=n;i++){
			ans[i]=a[i]+ans[i-1];
		}
		mins=min(mins,p());
		return;
	}
	for(int i=2;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			a[x]=d[i];
			dfs(x+1);
			vis[i]=0;
		}
	}
}
