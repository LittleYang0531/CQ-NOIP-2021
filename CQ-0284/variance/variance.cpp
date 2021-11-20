#include<bits/stdc++.h>
using namespace std;
long long n,sum,k,js;
long long a[10001],b[100001][601];
int cz(int ans){
	k=0,js=0,sum=0;
	int pp=0;
	for(int i=1;i<=n;i++){
		if(a[i-1]+a[i+1]-a[i]!=a[i]&&a[i-1]+a[i+1]-a[i]>=0&&i!=1&&i!=n&&b[i][a[i]]==0&&pp==0){
			a[i]=a[i-1]+a[i+1]-a[i];
			b[i][a[i]]=1;
			pp=1;
			k=1;
		}
		sum+=a[i];
	}
	for(int i=1;i<=n;i++) js+=(pow(a[i],2)*n)-(2*sum*a[i])+(pow(sum,2)/n);
	if(js<ans) ans=js;
	if(k==0) return ans;
	else cz(ans);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++) js+=(pow(a[i],2)*n)-(2*sum*a[i])+(pow(sum,2)/n);
	cout<<cz(js);
}
