#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ll long long
using namespace std;
const int N=500;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;(ch>'9'||ch<'0');ch=getchar()) if(ch=='-') f=-1;
	for(;(ch>='0'&&ch<='9');ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int n;
ll ans,now,tep;
struct dc{
	int pw[N],v[N];
	ll psm,sum,ans;
}dp[N][N];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		for(int t=1;t<=n;++t)
			dp[i][t].ans=0x3fffffff;
	for(int i=1;i<=n;++i) dp[1][0].v[i]=read(),dp[1][0].sum+=dp[1][0].v[i],dp[1][0].pw[i]=dp[1][0].v[i]*dp[1][0].v[i],dp[1][0].psm+=dp[1][0].pw[i];
	dp[1][0].ans=n*dp[1][0].psm-dp[1][0].sum*dp[1][0].sum;
	for(int i=2;i<=n;++i) dp[i][0]=dp[i-1][0];
	ans=0x3fffffff;
	for(int i=1;i<=(n<<1);++i){
		for(int t=2;t<n;++t){
			dp[t][i]=dp[t][i-1];
			for(int j=2;j<n;++j){
				tep=n*(dp[j][i-1].psm-dp[j][i-1].pw[t]+(dp[j][i-1].v[t-1]+dp[j][i-1].v[t+1]-dp[j][i-1].v[t])*(dp[j][i-1].v[t-1]+dp[j][i-1].v[t+1]-dp[j][i-1].v[t]))-(dp[j][i-1].sum+dp[j][i-1].v[t-1]+dp[j][i-1].v[t+1]-2*dp[j][i-1].v[t])*(dp[j][i-1].sum+dp[j][i-1].v[t-1]+dp[j][i-1].v[t+1]-2*dp[j][i-1].v[t]);
				ans=min(tep,ans);
				if(dp[t][i].ans>tep){
					dp[t][i]=dp[j][i-1];
					dp[t][i].ans=tep;
					dp[t][i].psm=dp[t][i].psm-dp[t][i].pw[t]+(dp[t][i].v[t-1]+dp[t][i].v[t+1]-dp[t][i].v[t])*(dp[t][i].v[t-1]+dp[t][i].v[t+1]-dp[t][i].v[t]);
					dp[t][i].pw[t]=(dp[t][i].v[t-1]+dp[t][i].v[t+1]-dp[t][i].v[t])*(dp[t][i].v[t-1]+dp[t][i].v[t+1]-dp[t][i].v[t]);
					dp[t][i].sum=dp[t][i].sum+dp[t][i].v[t-1]+dp[t][i].v[t+1]-2*dp[t][i].v[t];
					dp[t][i].v[t]=dp[t][i].v[t-1]+dp[t][i].v[t+1]-dp[t][i].v[t];
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
