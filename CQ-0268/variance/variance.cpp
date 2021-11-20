#include<bits/stdc++.h>
using namespace std;

int n,a[10005],b[10005];

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=4){
		if(n==1)  puts("0");
		else if(n==2) printf("%d\n",2*(a[1]*a[1]+a[2]*a[2])-(a[1]+a[2])*(a[1]+a[2]));
		else if(n==3){
			int ans1=3*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]);
			a[2]=a[1]+a[3]-a[2];
			int ans2=3*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]);
			printf("%d\n",min(ans1,ans2));
		}
		else{
			int ans=1e9+5;
			int ans1=4*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3]+a[4]*a[4])-(a[1]+a[2]+a[3]+a[4])*(a[1]+a[2]+a[3]+a[4]);
			ans=min(ans,ans1);
			memcpy(b,a,sizeof a);
			b[2]=a[1]+a[3]-a[2];
			ans1=4*(b[1]*b[1]+b[2]*b[2]+b[3]*b[3]+b[4]*b[4])-(b[1]+b[2]+b[3]+b[4])*(b[1]+b[2]+b[3]+b[4]);
			ans=min(ans,ans1);
			memcpy(b,a,sizeof a);
			b[3]=a[2]+a[4]-a[3];
			ans1=4*(b[1]*b[1]+b[2]*b[2]+b[3]*b[3]+b[4]*b[4])-(b[1]+b[2]+b[3]+b[4])*(b[1]+b[2]+b[3]+b[4]);
			ans=min(ans,ans1);
			memcpy(b,a,sizeof a);
			b[2]=a[1]+a[3]-a[2];b[3]=a[1]+a[4]-a[2];
			ans1=4*(b[1]*b[1]+b[2]*b[2]+b[3]*b[3]+b[4]*b[4])-(b[1]+b[2]+b[3]+b[4])*(b[1]+b[2]+b[3]+b[4]);
			ans=min(ans,ans1);
			memcpy(b,a,sizeof a);
			b[2]=a[1]+a[4]-a[3];b[3]=a[2]+a[4]-a[3];
			ans1=4*(b[1]*b[1]+b[2]*b[2]+b[3]*b[3]+b[4]*b[4])-(b[1]+b[2]+b[3]+b[4])*(b[1]+b[2]+b[3]+b[4]);
			ans=min(ans,ans1);
			memcpy(b,a,sizeof a);
			b[2]=a[1]+a[4]-a[3];b[3]=a[1]+a[4]-a[2];
			ans1=4*(b[1]*b[1]+b[2]*b[2]+b[3]*b[3]+b[4]*b[4])-(b[1]+b[2]+b[3]+b[4])*(b[1]+b[2]+b[3]+b[4]);
			ans=min(ans,ans1);
			memcpy(b,a,sizeof a);
			b[2]=a[1]+a[3]-a[2];b[3]=a[1]+a[4]-a[2];
			ans1=4*(b[1]*b[1]+b[2]*b[2]+b[3]*b[3]+b[4]*b[4])-(b[1]+b[2]+b[3]+b[4])*(b[1]+b[2]+b[3]+b[4]);
			ans=min(ans,ans1);
			printf("%d\n",ans);
		}
	}  
	else{
		long long ans=0,res1=0,res2=0;
		for(int i=1;i<=n;i++){
			res1=res1+1LL*a[i]*a[i];
			res2=res2+a[i];
		}
		ans=1LL*n*res1-res2*res2;
		printf("%lld\n",ans);
	}
	return 0;
}
