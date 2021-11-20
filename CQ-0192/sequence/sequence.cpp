#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod=998244353;
int n,m,k,a[105],ans;
void hanshu(int wz,int jw,int yu,int sum,int dian,int gl)
{
	int bf=gl;
	if(yu==0)
	{
		while(jw>1) dian+=jw%2,jw/=2;
		if(jw!=0) ++dian;
		if(dian<=k) ans=(ans+sum*gl%mod)%mod;
		return;
	}
	if(sum==0 || wz>m) return;
	int rnm=1/*result num*/;
	for(int i=0; i<=yu; ++i)
	{
		if(i!=0) rnm=(a[wz]%mod)*rnm%mod;
		gl=bf;
		for(int w=n-yu+1; w<=n-yu+i; ++w) gl=gl*w;
		for(int w=i; w; w--) gl/=w;
		hanshu(wz+1,(i+jw)/2,yu-i,sum*rnm%mod,dian+(i+jw)%2,gl);
	}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%llu%llu%llu",&n,&m,&k);
	for(int i=0; i<=m; ++i) scanf("%llu",&a[i]);
	hanshu(0,0,n,1,0,1);
	printf("%llu",ans);
	return 0;
}
