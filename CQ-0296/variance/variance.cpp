#include<bits/stdc++.h>
#define maxn 10005
#define INF 0x7fffffff
using namespace std;
inline int read(){
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0' or c>'9') c=getchar();
	while(c>='0' and c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
int n;
int ans=INF;
int a[maxn];
int var(){
	int sum=0;
	double val;
	for(int i=1;i<=n;i++) sum+=a[i];
	val=double(sum)/double(n);
	double cnt=0.0;
	for(int i=1;i<=n;i++) cnt+=(val-a[i])*(val-a[i]);
	cnt*=n;
	return int(cnt);
}
int cnt=0;
int his[maxn][maxn];
bool same(int a[],int b[],int m){
	for(int i=1;i<=m;i++) if(a[i]!=b[i]) return false;
	return true;
}
void dfs(int a[]){
	for(int i=2;i<=n-1;i++){
		if(a[i-1]+a[i+1]-a[i]==a[i]) continue;
		int num=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		memcpy(a,his[++cnt],sizeof(a));
		for(int j=1;j<=cnt;j++) if(same(a,his[j],n)) return;
		ans=min(ans,var());
		dfs(a);
		a[i]=num;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	ans=min(ans,var());
	dfs(a);
	printf("%d",ans);
	return 0;
}
