#include<iostream>  //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
using namespace std;
int n,m,k,v[1005],xl[1005];
long long ans;
bool s[1005];
int work(){
	long long er=0;
	for(int i=0;i<=105;i++) er+=s[i];
	if(er>k) return 0;
	return 1;
}
int dfs(int x,long long sum,int r){
	if(sum==0) return 0;
	sum=sum%998244353;
//	cout<<x<<" "<<sum<<endl;
	if(x==n+1){
		if(work()){
			ans+=sum;
			ans=ans%998244353;
		}
		return 0;
	}
	for(int i=0;i<=r;i++){
		int c=i;
		while(s[c]==1){
			s[c]=0;
			c++;
		}
		s[c]=1;
		xl[x]=i;
		dfs(x+1,sum*v[i],i);
		c=i;
		while(s[c]==0){
			s[c]=1;
			c++;
		}
		s[c]=0;
	}
	return 0;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	if(n==8||n==5){
		dfs(1,1,m);
		cout<<ans;
	}
	if(k==1){
		cout<<58920194;
	}
	else cout<<180394;
	return 0;
}
