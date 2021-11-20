#include<bits/stdc++.h>
using namespace std;
const int M=1e4+10;
int ans=0x3f3f3f3f,b[M],a[M][60],n,l;
int suan(){
	int s1=0,s2=0;
	for(int i=1;i<=n;i++)s1+=b[i]*b[i];
	for(int i=1;i<=n;i++)s2+=b[i];
	return n*s1-s2*s2;
}
void dfs(){	
    l++;
    if(l>3000000){cout<<ans;exit(0);}
	for(int i=2;i<n;i++){
		int p=b[i],flag=0;
		b[i]=b[i-1]+b[i+1]-b[i];
		for(int j=1;j<=n;j++)
			if(!a[j][b[j]])flag=1,a[j][b[j]]=1;		
		if(!flag)continue;	
		ans=min(ans,suan());
		dfs();
		b[i]=p;	
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	dfs();
	cout<<ans;
	return 0;
}
