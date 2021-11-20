#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
int arr[10005];
map<string,bool> m;
ll ans;
ll get(){
	ll fz=0;
	for(int i=1;i<=n;i++){
		fz+=arr[i];
	}
	ll fz1=0;
	for(int i=1;i<=n;i++){
		fz1+=(n*arr[i]-fz)*(n*arr[i]-fz);
	}
	return fz1/n;
}
string change(){
	string k;
	for(int i=1;i<=n;i++){
		int m=arr[i];
		while(m>0){
		int c=m%10;
		if(c==1)k+="1";
		if(c==2)k+="2";
		if(c==3)k+="3";
		if(c==4)k+="4";
		if(c==5)k+="5";
		if(c==6)k+="6";
		if(c==7)k+="7";
		if(c==8)k+="8";
		if(c==9)k+="9";
		if(c==0)k+="0";
		m=m/10;
	}
		k+=" ";
	}
	return k;
}
int cnt;
int brr[10005];
void dfs(){
	cnt++;
	if(cnt>20000)return;
	string ml=change();
	ans=min(ans,get());
	m[ml]=1;
	for(int i=2;i<n;i++){
		brr[i]=arr[i];
		arr[i]=arr[i+1]+arr[i-1]-arr[i];
		if(!m[change()]){
		dfs();
		dfs();
	}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
	ans=get();
	dfs();
	printf("%lld",ans);
	return 0;
}
