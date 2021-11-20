#include<bits/stdc++.h>
#define N 10005
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void write(int x){
	char f[50];int cnt=0;
	if(!x)
		putchar('0');
	while(x){
		f[cnt++]=x%10+'0';
		x/=10;
	}
	while(cnt)
		putchar(f[--cnt]);
}
int n,a[N],sum=0,res,ans=1e9,can=20;
void dfs(int k){
	if(k>can)
		return;
	res=0;
	for(int i=1;i<=n;++i)
		res+=pow(n*a[i]-sum,2);
	ans=min(ans,res/n);
	for(int i=2;i<n;++i){
		sum+=(a[i-1]+a[i+1]-a[i]-a[i]);
		int p=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		dfs(k+1);
		a[i]=p;
		sum-=(a[i-1]+a[i+1]-a[i]-a[i]);
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum+=a[i];
	}
	dfs(1);
	write(ans);
	return 0;
}
