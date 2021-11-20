#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[10003],b[10003];
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);int sum=0,num=0;
	int mn=0x7fffffff,mx=0;
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),b[i]=a[i],mn=min(a[i],mn),mx=max(a[i],mx);
	int ans=0x7fffffff;
	for(double tmp=mn;tmp<=mx;tmp+=0.1){
		for(int i=1;i<=n;++i) a[i]=b[i];
		int flag=1;
		while(flag){flag=0;
			for(int i=2;i<n;++i){
				int ttt=a[i-1]+a[i+1]-a[i];
				if(abs(tmp-ttt)<abs(tmp-a[i])) a[i]=a[i-1]+a[i+1]-a[i],flag=1;
			}
		}
		sum=0;for(int i=1;i<=n;++i) sum+=a[i];
		num=0;for(int i=1;i<=n;++i){
			num+=(n*a[i]-sum)*(n*a[i]-sum);
		}ans=min(ans,num/n);
	}cout<<ans<<endl;
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99


10
6 21 34 41 42 42 43 59 78 99


10
6 21 42 55 56 63 63 64 80 99
ans=61225
*/
