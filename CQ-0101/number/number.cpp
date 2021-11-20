#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10,N=1e7+1e5+10;
int vis[N],ans[N],a[M],b[M],m;
void gan(){
	int las=0;
	for(int i=1;i<=m+10000;i++){
		if(vis[i])continue;
		int p=i;
		while(p){
			if(p%10==7){vis[i]=1;break;}
			p/=10;
		}
		if(vis[i])
			for(int j=2;j*i<=m+10000;j++)vis[j*i]=1;
		else ans[las]=i,las=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)cin>>a[i],m=max(m,a[i]);
	gan();
	for(int i=1;i<=t;i++){
		if(vis[a[i]])puts("-1");
		else cout<<ans[a[i]]<<endl;
    }
	return 0;
}
