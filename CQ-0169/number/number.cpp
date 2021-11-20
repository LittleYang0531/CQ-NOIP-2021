#include <bits/stdc++.h>
using namespace std;
int T,x;
int poww[20],zui[10000020],prime[10000020],nextt[10000020],ind=0;
bool p[10000020],isp[10000020];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	poww[0]=1;
	for(int i=1;i<=8;i++) poww[i]=poww[i-1]*10;
	for(int i=1;i<=200100;i++) {
		for(int j=0;j<=6;j++) {
			if(i/poww[j]%10==7) {
				p[i]=true;break;
			}
		}
	}
	for(int i=1;i<=200100;i++) isp[i]=true;
	for(int i=2;i<=200100;i++) {
		if(isp[i]) {
			prime[++ind]=i;
			zui[i]=i;
		}
		for(int j=1;j<=ind&&prime[j]*i<=200100;j++) {
			zui[prime[j]*i]=prime[j];
			isp[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
	for(int i=2;i<=200100;i++) {
		for(int j=1;j<=ind&&prime[j]*prime[j]<=i;j++) {
			if(i%prime[j]==0&&(p[i/prime[j]]||p[prime[j]])) {
				p[i]=true;break;
			}
		}
	}
	nextt[200011]=200012;
	for(int i=200010;i>=2;i--) {
		if(!p[i+1]) nextt[i]=i+1;
		else nextt[i]=nextt[i+1];
	}
	for(int i=1;i<=T;i++) {
		scanf("%d",&x);
		if(p[x]) printf("-1\n");
		else printf("%d\n",nextt[x]);
	}
	return 0;
}
