 #include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod=998244353;
long long n,m,qwq,v[105],f[35][105][35],h[35][105][35],jc[35]={1},an,ny[35];
long long lb(long long x){return x&-x;}
long long js(long long x)
{
	long long ans=0;
	while(x){x^=lb(x);++ans;}
	return ans;
}
long long ksm(long long x,long long y)
{
	long long ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
long long C(long long x,long long y){if(!x||x==y)return 1;return jc[y]*ny[x]%mod*ny[y-x]%mod;}//x<y
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	long long i,j,l,k;
	scanf("%lld%lld%lld",&n,&m,&qwq);
	for(i=0;i<=m;++i)scanf("%lld",&v[i]);
	
	for(i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
	ny[n]=ksm(jc[n],mod-2);
	for(i=n-1;i>=1;--i)ny[i]=ny[i+1]*(i+1)%mod;
	
	for(j=0;j<=m;++j)h[0][j][0]=1;
	
	for(j=0;j<=m;++j)
	for(i=0;i<=n;++i)
	for(k=1;k<=n-i;++k)
	for(l=0;l<=n;++l)
	if(h[i][j][l])
	{
		f[i+k][j+1][(l+k)>>1]=f[i][j][l]-js(l)+js(l+k);
		
		h[i+k][j+1][(l+k)>>1]=(h[i+k][j+1][(l+k)>>1]+h[i][j][l]*ksm(v[j],k)%mod*C(k,i+k)%mod)%mod;
		
		if(i+k==n&&f[i+k][j+1][(l+k)>>1]<=qwq)an=(an+h[i][j][l]*ksm(v[j],k)%mod*C(k,i+k)%mod)%mod;
		
//		cout<<"QAQ"<<i<<" "<<j<<" "<<l<<" "<<k<<" "<<f[i][j][l]<<" "<<f[i+k][j+1][(l+k)>>1]<<" "<<h[i][j][l]*ksm(v[j],k)%mod*C(k,i+k)%mod<<endl;
//		cout<<"!!!"<<h[5][2][2]<<endl;
	}
	
	
//	for(j=0;j<=m;++j)
//	for(i=0;i<=n;++i)
//	for(l=0;l<=(n>>1);++l)
//	cout<<"QAQ"<<i<<" "<<j<<" "<<l<<" "<<f[i][j][l]<<" "<<h[i][j][l]<<endl;
	
	printf("%lld\n",an);
	return 0;
}
/*
5 1 1
2 1
*/
