#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
const int N=10005;
int n,a[N],S,ans,it=n,tim;
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int i;
	scanf("%lld",&n);int sq=0;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);S+=a[i];sq+=a[i]*a[i];
	}
	ans=sq*n-S*S;
	while(1){
		int tg=0,minn=1,dt=0;
		for(i=2;i<n;i++){
			int dlt=a[i+1]+a[i-1]-(a[i]*2);if(dlt==0)continue;
			int dlq=(2*a[i]*dlt*n+dlt*dlt*n-2*S*dlt-dlt*dlt);
			if(dlq<minn)minn=dlq,it=i,dt=dlt,tg=1;
		}
		if(minn==1)break;
		else if(minn==0){tim++;if(tim>=n*n)break;}
		else tim=0;
		//printf("%d\n",minn);
		//else{tim=0;}
		a[it]+=dt,S+=dt;int res=0;
		for(i=1;i<=n;i++)res+=a[i]*a[i];
		ans=min(ans,n*res-S*S);
	}
	printf("%lld",ans);
}
