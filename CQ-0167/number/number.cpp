#include<bits/stdc++.h>
using namespace std;
const int N=10000005,Mod=7,Base=10;
int T,x,a[N],cnt;
bool vis[N];
void wr(int x) {
	if (!x) return;
	wr(x/10);
	putchar(x%Base+'0');
	return;
}
inline bool check(int p) {
	while (p) {
		if (p%Base==7) {
			return true;
		}
		p/=10;
	}
	return false;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=1;i<N;i++) {
		if (check(i)) {
			vis[i]=1;
			for (int j=2;j*i<N;j++) {
				vis[i*j]=1;
			}
		} else if (i%Mod==0) {
			vis[i]=1;
		} else if (!vis[i]) a[++cnt]=i;
	}
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&x);
		if (vis[x]) {
			putchar('-'),putchar('1'),putchar('\n');
			continue;
		}
		int d=lower_bound(a+1,a+cnt+1,x)-a;
		wr(a[d+1]),putchar('\n');
	}
	return 0;
}
