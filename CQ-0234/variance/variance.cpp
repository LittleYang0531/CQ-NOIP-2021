#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
typedef long long ll;
int n;
ll a[maxn],d[maxn],ans,sum1,sum2;
int c1[maxn],c2[maxn]; 
const ll inf=1e16;
bool cmp1(int a,int b){
	return d[a]>d[b];
}
bool cmp2(int a,int b){
	return d[a]<d[b];
}
int id[maxn];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		d[i]=a[i]-a[i-1]; 
		id[i]=i;
	} 
	ans=inf; 
	for(int S=0;S<(1<<(n-1));S++){
		int cnt1=0,cnt2=0;
		for(int j=0;j<n-1;j++){
			if(S&(1<<j)){
				c1[++cnt1]=j+2;
			}
			else{
				c2[++cnt2]=j+2;
			}
		} 
		sort(c1+1,c1+cnt1+1,cmp1);
		sort(c2+1,c2+cnt2+1,cmp2); 
		id[1]=1;
		for(int i=2;i<=cnt1+1;i++){
			id[i]=c1[i-1];
		}
		for(int i=cnt1+2;i<=cnt1+1+cnt2;i++){
			id[i]=c2[i-cnt1-1];
		}		
		sum1=sum2=0;
		ll now=0;
		for(int i=1;i<=n;i++){ 
			now+=d[id[i]];
			sum1+=now*now;
			sum2+=d[id[i]]*(ll)(n-i+1);
		} 
		ans=min(ans,sum1*n-sum2*sum2);	  
	}
	printf("%lld\n",ans);
	return 0;
}
