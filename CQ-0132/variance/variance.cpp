#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;

ll n,a[10005],ans,X,Y,b[10005],c[10005],d[10005];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
//void dfs(int x)
//{
//	solve();
//	for(int i=2;i<n;i++){
//		ll c=a[i];
//		a[i]=a[i+1]+a[i-1]-a[i];
//		
//		dfs(x+1);
//	}
//}
int anss,ass,ss;
void check(int S)
{
	ll t=0;
	for(int i=2;i<=n;i++)
		if(S&(1<<(i-1)))t+=b[i];
	if(t>ss/2)t=ss/2-t;
	if(t>ass){
		ass=t;anss=S;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)ss+=b[i];
	sort(b+2,b+1+n);
if(n<=13)
{
	for(int i=1;i<=n;i++)d[i]=i;
	ans=1e17;
	do{
		if(d[1]>1)break;
		for(int i=1;i<=n;i++)c[i]=b[d[i]];
		X=0;Y=0;
		for(int i=1;i<=n;i++)a[i]=a[i-1]+c[i];
		for(int i=1;i<=n;i++){
			X+=a[i];Y+=a[i]*a[i];
		}
		ans=min(ans,n*Y-X*X);
//		if(n*Y-X*X==59865){
//			for(int i=1;i<=n;i++)cout<<c[i]<<" ";
//			cout<<"^\n";
//		}
	}while(next_permutation(d+1,d+1+n));
	cout<<ans;
	return 0;
}
if(n<=20){
	for(int i=(1<<n)-1;i>=0;i--){
		check(i);
	}
	int tot=1;c[1]=b[1];
//	cout<<ss/2<<"   "<<ass<<"%%\n";
	for(int i=n;i>1;i--){
		if(anss&(1<<(i-1)))c[++tot]=b[i];
	}
	for(int i=2;i<=n;i++){
		if((anss&(1<<(i-1)))==0)c[++tot]=b[i];
	}
//	for(int i=1;i<=tot;i++)cout<<c[i]<<"%\n";
	ans=1e16;
	X=0;Y=0;
	for(int i=1;i<=n;i++)a[i]=a[i-1]+c[i];
	for(int i=1;i<=n;i++){
		X+=a[i];Y+=a[i]*a[i];
	}
	ans=min(ans,n*Y-X*X);
	cout<<ans;
	return 0;
}
d[1]=1;
for(int i=2;i<=n;i++)d[i]=i;
//srand(time(0)+233);
for(int i=1;i<=n;i++)c[i]=b[d[i]];
		X=0;Y=0;
		for(int i=1;i<=n;i++)a[i]=a[i-1]+c[i];
		for(int i=1;i<=n;i++){
			X+=a[i];Y+=a[i]*a[i];
		}
		ans=n*Y-X*X;
	cout<<ans;return 0;
	for(int i=1;i<=n;i++){
		X+=a[i];Y+=a[i]*a[i];
	}
	ans=n*Y-X*X;
//	dfs(1);
	cout<<ans;
	for(int i=1;i<=n-2;i++){
		for(int j=2;j<n;j++){
			b[j]=(n-1)*(a[i+1]+a[i-1]-a[i])*(a[i+1]+a[i-1]-a[i])+
			2*(a[i+1]+a[i-1]-a[i])*(a[i]-X);
		}
		ll mn=0;int k=0;
		for(int j=2;j<n;j++)
			if(b[j]<mn){mn=b[j];k=j;}
		if(k){
			cout<<k<<"&\n";
			X=X-a[k]+(a[k+1]+a[k-1]-a[k]);
			Y=Y-a[k]*a[k]+(a[k+1]+a[k-1]-a[k])*(a[k+1]+a[k-1]-a[k]);
			a[k]=(a[k+1]+a[k-1]-a[k]);
		}
		ans=min(ans,n*Y-X*X);
	}
	cout<<ans;
	return 0;
}
