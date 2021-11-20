#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn=105,mod=998244353;
int n,m,k,ans,cnt,lim,v[mxn],a[mxn],c[mxn],c1[mxn];
int _() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int add(int a,int b) {return (a+b)%mod;}
int mul(int a,int b) {return (ll)a*b%mod;}
int quick(int x,int p) {
	int s=1;
	while(p>0) {
		if(p&1) s=mul(s,x);
		p>>=1,x=mul(x,x);
	}
	return s;
}
int fact(int x) {
	int res=1;
	for(int i=2;i<=x;++i) res*=i;
	return res;
}
void work() {
	int ct=0;
	memcpy(c1,c,sizeof(c1));
	for(int i=0;i<=m+lim;++i) {
		c1[i+1]+=c1[i]/2;
		c1[i]%=2;
		if(c1[i]) ct++;
	}
//	printf("\n");
	if(ct>k) return ;
//	printf("<");
//	for(int i=0;i<=m;++i) 
//		printf("%d ",c[i]);
//	printf(">\n");
	int sum=1;
	for(int i=0;i<=m;++i) 
		sum=mul(sum,quick(v[i],c[i]));
	int num=fact(n);
	for(int i=0;i<=m;++i) {
		if(c[i]) num/=fact(c[i]);
	}
//	printf("%d\n",sum);
//	printf("%d %d\n",num,sum);
	ans=add(ans,mul(sum,num));
}
void dfs(int t) {
	if(t==m) {c[t]=n-cnt;work();return;}
	for(int i=0;cnt+i<=n;++i) {
		c[t]=i;
		cnt+=i;
		dfs(t+1);
		cnt-=i;
	}
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=_(),m=_(),k=_();
	int x=n*m;
	while(x>1) x>>=1,lim++;
	lim++;
	for(int i=0;i<=m;++i) v[i]=_(),c[i]=0;
	if(n<=8&&m<=9) {
		dfs(0);
		printf("%d ",ans);
	}
}
/*
5 1 1
2 1
*/
//9:45~12:15
