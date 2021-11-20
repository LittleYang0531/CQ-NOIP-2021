#include <bits/stdc++.h>
using namespace std;
int n;
int f[10010],cha[10010],bian[10010],lin[10010];
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	for(int i=2;i<=n;i++) {
		cha[i-1]=f[i]-f[i-1];
	}
	sort(cha+1,cha+n);
	long long Ans=1e18;
	for(int i=1;i<n;i++) {
		int l=i,r=i+1,ind=1;
		while(ind<n) {
			if(l>=1) {
				bian[l]=ind;l--;ind++;
			} if(r<n) {
				bian[r]=ind;r++;ind++;
			}
		}
		lin[1]=f[1];
		for(int j=2;j<=n;j++) {
			lin[j]=lin[j-1]+cha[bian[j-1]];
		}
		long long ans=0,he=0;
		for(int j=1;j<=n;j++) he+=lin[j];
		for(int j=1;j<=n;j++) {
			ans+=n*lin[j]*lin[j]-2*lin[j]*he;
		}
		ans+=he*he;
		Ans=min(Ans,ans);
	}
	printf("%lld\n",Ans);
	return 0;
}
