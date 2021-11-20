#include <bits/stdc++.h>
using namespace std;
const int mxn=3e6+5;
int T,cnt,tp,vis[mxn],p[mxn],ans[mxn];
int _() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x) {
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int check(int x) {
	while(x>0) {
		int a=x%10;
		if(a==7) return 1;
		x/=10;
	}
	return 0;
}
void init() {
	for(int i=2;i<mxn;++i) {
		if(vis[i]) p[++cnt]=i;
		else if(check(i)) p[++cnt]=i,vis[i]=1;
		if(p[cnt]==i) {
			for(int j=i+i;j<mxn;j+=i) {
				vis[j]=1;
			}
		}
//		for(int j=1;j<=cnt&&p[j]*i<mxn;++j) {
//			vis[i*p[j]]=1;
////			if(i%p[j]==0) break;
//		}
	}
	int lst=0;
	for(int i=1;i<mxn;++i) 
		if(vis[i]==0) ans[lst]=i,lst=i;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	T=_();
	while(T--) {
		int x=_();
		if(vis[x]) printf("-1\n");
		else printf("%d\n",ans[x]);
	}
}
//8:34~9:44
