//CCF AK ME
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10005],na,nb,maxa=10005,maxb=1;
int fz[10005],fm[10005];
int ans=0x7fffffff/2;
bool flag[10005];
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int jia(int a,int b,int a1,int b1){
	int gfm=b*b1/gcd(b,b1);
	int ta,tb;
	tb=gfm;
	ta=a*(tb/b)+a1*(tb/b1);
	return ta;//返回分子 
}
int jian(int a,int b,int a1,int b1){
	int gfm=b*b1/gcd(b,b1);
	int ta,tb;
	tb=gfm;
	ta=a*(tb/b)-a1*(tb/b1);
	return ta;//返回分子 
}
bool cmp(int a,int b,int a1,int b1){
	int gfm=b*b1/gcd(b,b1);
	return a*(gfm/b)<a1*(gfm/b1);
}
void noip(){
	int sum1=0;
	for(int i=1;i<=n;i++){
		sum1+=a[i];
	}int kkk=gcd(sum1,n);
	sum1/=kkk;int g=n/kkk;
	for(int i=1;i<=n;i++){
		if(cmp(a[i],1,sum1,g)){
			fz[i]=pow(jian(sum1,g,a[i],1),2);
			fm[i]=g*g;
		}else{
			fz[i]=pow(jian(a[i],1,sum1,g),2);
			fm[i]=g*g;
		}
	}
	int up=0,down=1;
	for(int i=1;i<=n;i++){
		up=jia(up,down,fz[i],fm[i]);
		down=down*fm[i]/gcd(down,fm[i]);
	}
	int mod=gcd(up,down);
	up/=mod;
	down/=mod;
	na=up,nb=down*n;
}
void dfs(int x){
	noip();
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<na<<" "<<nb<<endl; 
	if(cmp(na,nb,maxa,maxb)) maxa=na,maxb=nb;
	if(x>=n){
		return;
	}
	
	for(int j=2;j<=n-1;j++){
		if(!flag[j]&&a[j-1]+a[j+1]!=2*a[j]){
			a[j]=a[j-1]+a[j+1]-a[j];
			flag[j]=1;
			dfs(j);
			flag[j]=0;
			a[j]=a[j-1]+a[j+1]-a[j];
		}
	}
	
}
signed main(){
  freopen("variance.in","r",stdin);
  freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	printf("%d",(maxa*n*n)/maxb);
	return 0;
}

