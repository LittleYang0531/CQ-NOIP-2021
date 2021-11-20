#include<bits/stdc++.h>//JZM yyds!!
#define ll long long
#define MOD 
#define MAXN 20005
#define INF 1e17
#define uns unsigned
#define IF (it->first)
#define IS (it->second)
using namespace std;
inline ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
int pt[30],lp;
inline void print(ll x,char c='\n'){
	if(x<0)putchar('-'),x=-x;
	pt[lp=1]=x%10;
	while(x>9)x/=10,pt[++lp]=x%10;
	while(lp)putchar(pt[lp--]^48);
	putchar(c);
}
inline ll lowbit(ll x){return x&-x;}

int n;
ll a[MAXN],b[MAXN],c[605],ans;
int m,d[605];
inline void dfs(int x,ll pr,ll s,ll sum){
	if(x>n){
		ans=min(ans,sum-s*s);
		return;
	}
	if(sum-s*s>=ans)return;
	for(int i=1;i<=m;i++)if(d[i]>0){
		d[i]--,b[x]=c[i];
		pr+=b[x],sum+=pr*pr*n,s+=pr;
		dfs(x+1,pr,s,sum);
		s-=pr,sum-=pr*pr*n,pr-=b[x];
		d[i]++;
	}
}

inline ll getval(int l,int r){
	ll pr=a[1],s=a[1],sum=pr*pr*n;
	for(int i=l;i<=r;i++)
		pr+=b[i],sum+=pr*pr*n,s+=pr;
	return sum-s*s;
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),ans+=a[i];
	ans=-ans*ans;
	for(int i=1;i<=n;i++)ans+=a[i]*a[i]*n;
	for(int i=n;i>1;i--)a[i]-=a[i-1];
	sort(a+2,a+1+n);
	for(int i=2;i<=n;i++){
		if(i<3||a[i]!=a[i-1])c[++m]=a[i],d[m]=1;
		else d[m]++;
	}
	
	if(n<=20){
		b[1]=a[1],dfs(2,b[1],b[1],b[1]*b[1]*n);
		print(ans);
		return 0;
	}
	
	b[1]=a[1];
	for(int i=2;i<=n;i++)b[i]=a[i];
	ans=min(ans,getval(2,n));
	for(int i=2;i<=n;i++)b[i]=a[n-i+2];
	ans=min(ans,getval(2,n));
	print(ans);
	return 0;
}
/*
n*sum(a_i^2)-sum(a_i)^2
*/
