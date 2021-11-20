#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define db double
using namespace std;
const int N=25;
int n,a[N],res=0x3f3f3f3f;
int calc(int x) {
	return x*x;
}
void chk() {
	int tot=0,tmp=0;
	for(int i=1;i<=n;i++) {
		tot+=a[i];
	}
	for(int i=1;i<=n;i++) {
		tmp+=calc(tot-a[i]*n);
	}
	res=min(res,tmp);
}
void dfs(int x) {
	chk();
	if(x>10) {
		return;
	}
	for(int i=2;i<n;i++) {
		int now=a[i-1]+a[i+1]-a[i];
		int tmp=a[i];
		if(now!=a[i]) {
			a[i]=now;
			dfs(x+1);
			a[i]=tmp;
		}
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",res/n);
}
