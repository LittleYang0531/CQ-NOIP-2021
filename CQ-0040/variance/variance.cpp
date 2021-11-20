#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using std::min;using std::max;
const int maxn = 1e4+5;
int n,a[maxn],maxc;
namespace Subtask_1{
	// n <= 400 & V <= 600
	const int maxn = 405,maxV = 605,maxV2 = 240005;
	int cf[maxn],cnt[maxV],sumc[maxV],sumv[maxV],sumli[maxn],sumsq[maxn];
	//sumc : cnt
	//sumv : allvals
	//sumli = 1+2+3...+i
	//sumsq = 1*1+2*2+3*3...+i*i
	ll dp[2][maxV2];
	void Solve(){
		for(int i=1;i<=n;++i)
			cf[i] = a[i]-a[i-1]+1;
		for(int i=2;i<=n;++i)
			++cnt[cf[i]],maxc = max(maxc,cf[i]);
		for(int i=1;i<=n;++i)sumli[i] = sumli[i-1] + i;
		for(int i=1;i<=n;++i)sumsq[i] = sumsq[i-1] + i*i;
		for(int i=1;i<=maxc;++i)sumc[i] = sumc[i-1] + cnt[i];
		for(int i=1;i<=maxc;++i)sumv[i] = sumv[i-1] + (i-1)*cnt[i];
		memset(dp,0x3f,sizeof(dp)),dp[0][0] = 0;
//		fprintf(stderr,"%d\n",maxc);
		for(int i=0;i<maxc;++i){
//			fprintf(stderr,"%d\n",i);
			if(cnt[i+1] == 0)
				memcpy(dp[i+1&1],dp[i&1],sizeof(dp[i&1]));
			else{
//				printf("Trans:%d %d\n",i+1,cnt[i+1]); 
				for(int j=0;j<=maxV2-5;++j){
//					if(i == 242 && j >= 100000)
//						fprintf(stderr,"%d %d %d\n",maxV2,j,cnt[i+1]);
					if(dp[i&1][j] > 1e18)continue;
//					printf("%d %d %d\n",i,j,dp[i&1][j]);
					for(int k=0;k<=cnt[i+1];++k){//put how many front
//						if(i == 242 && j == 101277)puts("Fdfg");
						int bk = cnt[i+1]-k;//put how many back
						int frv = k*i+sumv[i];//front+middle 的差分数组和 
						int j2 = 0;//new (sigma a[i])
						j2 += k*(k+1)/2*i;//front
						j2 += j+sumc[i]*k*i;//middle
						j2 += frv*bk+bk*(bk+1)/2*i;//back
						ll vals = 0;//new (sigma a[i]^2)
						vals += 1ll*sumsq[k]*i*i;//front;
						vals += dp[i&1][j]+2ll*k*i*j+1ll*sumc[i]*k*k*i*i;//middle
						vals += 1ll*bk*frv*frv+2ll*i*frv*sumli[bk]+1ll*i*i*sumsq[bk];//back
//						printf("j2:%d\n",j2);
//						if(i == 242 && j == 101277)fprintf(stderr,"%d %d\n",j2,vals);
						dp[i+1&1][j2] = min(dp[i+1&1][j2],vals);
					}
//					if(i == 242 && j >= 100000)fprintf(stderr,"Emd");
				}
//				if(i == 242)fprintf(stderr,"ASAASASASASSASA");
			}
			memset(dp[i&1],0x3f,sizeof(dp[i&1]));
		}
		//tips: 一会记得在最前面添加 cf[1] upd: 不用加了，怼掉了
//		fprintf(stderr,"asasas"); 
		ll ans = 1e18;
		for(int i=0;i<=maxV2-5;++i)
			if(dp[maxc&1][i] < 1e18)
				ans = min(ans,1ll*n*dp[maxc&1][i]-1ll*i*i);
		printf("%lld\n",ans);
	}
}
namespace Subtask_2{
	// n <= 10000 & V <= 50
	const int maxn = 10005,maxV = 55,maxV2 = 550005;
	int cf[maxn],cnt[maxV],sumc[maxV],sumv[maxV],sumli[maxn],sumsq[maxn];
	//sumc : cnt
	//sumv : allvals
	//sumli = 1+2+3...+i
	//sumsq = 1*1+2*2+3*3...+i*i
	ll dp[2][maxV2];//最多 600*600*400，炸不了 
	void Solve(){
		for(int i=1;i<=n;++i)
			cf[i] = a[i]-a[i-1]+1;
		for(int i=2;i<=n;++i)
			++cnt[cf[i]],maxc = max(maxc,cf[i]);
		for(int i=1;i<=n;++i)sumli[i] = sumli[i-1] + i;
		for(int i=1;i<=n;++i)sumsq[i] = sumsq[i-1] + i*i;
		for(int i=1;i<=maxc;++i)sumc[i] = sumc[i-1] + cnt[i];
		for(int i=1;i<=maxc;++i)sumv[i] = sumv[i-1] + (i-1)*cnt[i];
		memset(dp,0x3f,sizeof(dp)),dp[0][0] = 0;
		for(int i=0;i<maxc;++i){
			if(cnt[i+1] == 0)
				memcpy(dp[i+1&1],dp[i&1],sizeof(dp[i&1]));
			else{
				for(int j=0;j<=maxV2-5;++j){
					if(dp[i&1][j] > 1e18)continue;
					for(int k=0;k<=cnt[i+1];++k){//put how many front
						int bk = cnt[i+1]-k;//put how many back
						int frv = k*i+sumv[i];//front+middle 的差分数组和 
						int j2 = 0;//new (sigma a[i])
						j2 += k*(k+1)/2*i;//front
						j2 += j+sumc[i]*k*i;//middle
						j2 += frv*bk+bk*(bk+1)/2*i;//back
						ll vals = 0;//new (sigma a[i]^2)
						vals += 1ll*sumsq[k]*i*i;//front;
						vals += dp[i&1][j]+2ll*k*i*j+1ll*sumc[i]*k*k*i*i;//middle
						vals += 1ll*bk*frv*frv+2ll*i*frv*sumli[bk]+1ll*i*i*sumsq[bk];//back
						dp[i+1&1][j2] = min(dp[i+1&1][j2],vals);
					}
				}
			}
			memset(dp[i&1],0x3f,sizeof(dp[i&1]));
		}
		ll ans = 1e18;
		for(int i=0;i<=maxV2-5;++i)
			if(dp[maxc&1][i] < 1e18)
				ans = min(ans,1ll*n*dp[maxc&1][i]-1ll*i*i);
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(n <= 400)Subtask_1::Solve();
	else Subtask_2::Solve();
	return 0;
}
