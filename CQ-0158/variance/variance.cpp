#include<bits/stdc++.h>
//#include<time.h>
#define R register
int n;
const int maxn=10005;
int a[maxn];
long long ans=1e16;
std::map<long long , int > Map;
std::priority_queue<long long > pq;
inline void dfs(int val,int sum, int lst, int dep) {
//	if(1.0*clock()/clock_per_sec()>0.933)return ;
//	if(cnt>position)return ;
	R long long flag=(long long)val*1000000000+sum;
	if(Map.count(flag))return ;
	Map[flag]=1;
//	printf("%d %d %d\n",val,sum,lst);
//	for(R int i=1; i<=n; ++i) {
//		printf("%d ",a[i]);
//	}
//	printf("\n");
	R long long now=(long long)val*n-(long long)sum*sum;
	if(n<=50) {
		if(pq.size()==n*n*3&&pq.top()<now&&dep>=5)return ;
		if(pq.size()==n*n*3)pq.pop();
		pq.push(now);
	}
	ans=std::min(ans,now);
	R int pos=rand()%(n-2)+2;
	for(R int i=pos; i>=2; --i) {
		if(i!=lst&&a[i+1]+a[i-1]-a[i]!=a[i]) {
			R long long val1=val-a[i]*a[i],sum1=sum-a[i];
			a[i]=a[i+1]+a[i-1]-a[i];
			dfs(val1+a[i]*a[i],sum1+a[i],i,dep+1);
			a[i]=a[i+1]+a[i-1]-a[i];
		}
	}
	for(R int i=pos+1; i<n; ++i) {
		if(i!=lst&&a[i+1]+a[i-1]-a[i]!=a[i]) {
			R long long val1=val-a[i]*a[i],sum1=sum-a[i];
			a[i]=a[i+1]+a[i-1]-a[i];
			dfs(val1+a[i]*a[i],sum1+a[i],i,dep+1);
			a[i]=a[i+1]+a[i-1]-a[i];
		}
	}
	return ;
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(NULL));
	scanf("%d",&n);
	R long long sum=0,sum1=0;
	for(R int i=1; i<=n; ++i) {
		scanf("%d",&a[i]);
		sum+=a[i];
		sum1+=a[i]*a[i];
	}
	dfs(sum1,sum,0,0);
//		if(ans1>=ans)
	printf("%lld\n",ans);
	return 0;
}
