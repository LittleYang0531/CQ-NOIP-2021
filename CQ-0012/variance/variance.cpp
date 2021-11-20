#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e4+5;
int n,a[N],b[N],id[N];
long long ans=1e18;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=in();
	for(int i=1;i<=n;i++)a[i]=in();
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	if(n<=10){
		for(int i=1;i<n;i++)id[i]=i;
		do{
			a[1]=0;
			for(int i=1;i<n;i++)a[i+1]=a[i]+b[id[i]];
			int sum1=0,sum2=0;
			for(int i=1;i<=n;i++)sum1+=a[i],sum2+=a[i]*a[i];
			ans=min(ans,1ll*n*sum2-1ll*sum1*sum1);
		}while(next_permutation(id+1,id+n));
	}else{
		do{
			a[1]=0;
			for(int i=1;i<n;i++)a[i+1]=a[i]+b[i];
			int sum1=0,sum2=0;
			for(int i=1;i<=n;i++)sum1+=a[i],sum2+=a[i]*a[i];
			ans=min(ans,1ll*n*sum2-1ll*sum1*sum1);
		}while(next_permutation(b+1,b+n));
	}
	cout<<ans;
	return 0;
}

