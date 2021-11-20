#include<bits/stdc++.h>

using namespace std;
int N;
int a[200];
int vis[10000];
double work(){
	int s=0;
	for(int i=1;i<=N;i++)
		s+=a[i];
	double p=s*1.0/N,res=0;
	for(int i=1;i<=N;i++){
		res+=(p-a[i])*(p-a[i]);
	}	
	
	return res;
}
double dfs(int a1,int a2,int a3,int a4){
	double bef=work();
		vis[a1*1000+a2*100+a3*10+a4]=1;
	double now=bef;
	a[2]=a[1]+a[3]-a[2];
	
	if(!vis[a1*1000+a[2]*100+a3*10+a4])
	now=dfs(a1,a1+a3-a2,a3,a4);
	a[2]=a2;
	a[3]=a[2]+a[4]-a[3];
	if(!vis[a1*1000+a2*100+a[3]*10+a4])
	now=min(now,dfs(a1,a2,a2+a4-a3,a4));
	a[3]=a3;
	if(bef<now) return bef;
	return now;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>a[i];
	int ans=dfs(a[1],a[2],a[3],a[4])*N;
	cout<<ans; 
	return 0;
}
