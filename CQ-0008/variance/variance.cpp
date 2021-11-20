#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 412
#define U 6012
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3fll
int n,m,a[10012],nw=0,nl=0,nr=0,s[10012];LL F[N][U<<1],*f[N],ans=INF;
inline void cmin(LL &x,LL v){x=min(x,v);}
//LL g[N];
int main(){
//	g[0]=1;
//	for(int i=1;i<=40;i++)
//	for(int j=600;j>=0;j--)
//	for(int k=1;k*i<=600;k++)
//	g[j+k*i]=max(g[j+k*i],g[j]*(k+1));
//	cerr<<g[600]<<endl;
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	for(int i=0;i<N;i++)f[i]=F[i]+U;
	scanf("%d",&n);int i,j,k,x,u;LL v;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);m=a[n];u=min(m*m,5000);
	for(i=1;i<n;i++)a[i]=a[i+1]-a[i];--n;
	sort(a+1,a+n+1);for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	memset(F,0x3f,sizeof(F));f[0][0]=0;
	for(i=n;i>=1;i--)
	if(x=a[i])
	{
		for(j=nw;j>=0;j--)
		for(k=nl;k<=nr;k++)
		if((v=f[j][k])<INF)
		{
			cmin(f[j+1][k+(j+1)*x],v+2ll*x*(n-j)*k+1ll*(j+1)*(n-j)*x*x);
			cmin(f[j][k-(nw-j+1)*x],v+2ll*x*(nw-j+1)*k+1ll*(nw-j+1)*(n-nw+j)*x*x+2ll*(nw-j+1)*x*(n+1)*s[i-1]);f[j][k]=INF;
		}
		++nw;nl=max(nl-nw*x,-u);nr=min(nr+nw*x,u);
	}
	for(j=0;j<=nw;j++)
	for(k=nl;k<=nr;k++)cmin(ans,f[j][k]);printf("%lld",ans);return 0;
}
