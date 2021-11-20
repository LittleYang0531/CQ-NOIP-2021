#include <ctime>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll Sum,QSum,Ans=1e18;
int n,arr[10005];
bool cho[10005];
void dfs(int t)
{
	if(QSum*n-Sum*Sum<Ans)
	{
		Ans=QSum*n-Sum*Sum;
//		for(int i=1;i<=n;i++) printf("%d ",arr[i]);
//		puts("");
	}
	if(t>=20) return;
	if(clock()>=950)
	{
		printf("%lld",Ans);
		exit(0);
	}
	for(int i=2;i<n;i++)
	{
		if(cho[i]) continue;
		ll Tmp=arr[i];
		ll TmpSum=Sum,TmpQSum=QSum;
		if(arr[i-1]+arr[i+1]-arr[i]==arr[i]) continue;
		ll NewSum=Sum-arr[i]-arr[i]+arr[i-1]+arr[i+1],NewQSum=QSum-arr[i]*arr[i]+(arr[i-1]+arr[i+1]-arr[i])*(arr[i-1]+arr[i+1]-arr[i]);
		if(NewQSum*n-NewSum*NewSum<=Ans+100000)
		{
			Sum=NewSum; QSum=NewQSum;
			arr[i]=arr[i-1]+arr[i+1]-arr[i];
			dfs(t+1);
			arr[i]=Tmp;
			Sum=TmpSum; QSum=TmpQSum;	
		}
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]),Sum+=arr[i],QSum+=arr[i]*arr[i];
	dfs(1);
	printf("%lld",Ans);
	return 0;
}
