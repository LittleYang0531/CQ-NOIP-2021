#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int NN=55;
const int M=2e5+5;
int n;
long double ans;
ll tot,tot2;
ll a[N],b[N];
ll q[M][NN];
void bfs(){
	while(tot){
		tot2++;
		if(tot2>M)break;
		for(int i=1;i<=n;i++){
			b[i]=q[tot][i];
		}
		tot--;
		for(int i=2;i<n;i++){
			tot++;
			if(tot>M-5){
				tot--;
				break;
			}
			ll c=b[i];
			b[i]=b[i-1]+b[i+1]-b[i];
			long double x=0.0;
			for(int j=1;j<=n;j++){
				x+=(long double)b[j];
			}
			x/=(long double)n;
			long double y=0.0;
			for(int j=1;j<=n;j++){
				y+=((long double)b[j]-x)*((long double)b[j]-x);
			}
			y/=(long double)n;
			ans=min(ans,y*(long double)n*n);
			for(int j=1;j<=n;j++){
				q[tot][j]=b[j];
			}
			b[i]=c;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	tot++;
	for(int i=1;i<=n;i++){
		q[tot][i]=a[i];
	}
	long double x=0.0;
	for(int i=1;i<=n;i++){
		x+=(long double)a[i];
	}
	x/=(long double)n;
	long double y=0.0;
	for(int i=1;i<=n;i++){
		y+=((long double)a[i]-x)*((long double)a[i]-x);
	}
	y/=(long double)n;
	ans=y*(long double)n*n;
	bfs();
	ll ans2=(ll)ans;
	printf("%lld",ans2);
	return 0;
}
