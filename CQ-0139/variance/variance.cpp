#include<bits/stdc++.h>
using namespace std;
const int MAX_N=10001;
int N;
long long sum,num,tum,ans;
int a[MAX_N];
bool x[MAX_N][601];
int check()
{
	for(int i=2;i<N;i++)
	{
		int l=a[i-1],r=a[i+1],mid=a[i];
		if(x[i][r+l-mid]==0) return i; 
	}
	return -1;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i]*a[i];
		num+=a[i];
		if(i>1)
		x[i][a[i]]=1;
	}
	ans=sum*N-num*num; 
	while(1)
	{
		int c=check();
		if(c==-1) break;
		x[c][a[c+1]+a[c-1]-a[c]]=1;
		num-=a[c];
		sum-=a[c]*a[c];
		a[c]=a[c-1]+a[c+1]-a[c];
		num+=a[c];
		sum+=a[c]*a[c];
		ans=min(ans,sum*N-num*num);
 }
	printf("%lld",ans);
	return 0;
}
