#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define db double
using namespace std;
const int N=1e7+5;
int T,ans[N];
int cnt=654045;
bool vis[N],vis2[N];
void init(int n) {
	for(int i=1;i<=n;i++) {
		if(vis2[i/10]||i%10==7) {
			vis[i]=vis2[i]=1;
		}
		if(vis[i]&&vis2[i]) {
			for(int j=i+i;j<=n;j+=i) {
				vis[j]=1;
			}
		}
	}
	int now=1e7+1;
	for(int i=n;i>=1;i--) {
		if(vis[i]) {
			ans[i]=-1;
		}
		else {
			ans[i]=now;
			now=i;
		}
	}
}
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar(); 
	}
	return x*f;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init(1e7);
	int T=read();
	while(T--) {
		int n=read();
		printf("%d\n",ans[n]);
	}
}
