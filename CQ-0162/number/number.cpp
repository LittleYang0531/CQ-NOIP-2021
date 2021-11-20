#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+5;
bool vis[MAXN];
int snum[MAXN],cnt,ans[MAXN],nxt[MAXN];
bool check(int x) {
	while(x) {
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
void ola() {
	for(int i=1;i<=1e7;++i) nxt[i]=i-1;
	for(int i=7;i<=1e7;++i) {
		if(!vis[i]&&check(i)) {
			snum[++cnt]=i;
			for(int j=1e7/i;j>=1;j=nxt[j]) {
				vis[i*j]=1;
				nxt[i*j+1]=i*j-1;
				if(vis[nxt[j]]) {
					nxt[j]=nxt[nxt[j]];
				}
			}
		}
	}
	for(int i=1e7;i>=1;--i) {
		if(!vis[i]) ans[i]=i;
		else ans[i]=ans[i+1];
	}
}
int t,n;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ola();
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if(vis[n]) puts("-1");
		else printf("%d\n",ans[n+1]);
	}
	return 0;
}
/*
勉强过大样例，错了几个，可以70吧 
upd on 11:02 A了 
*/
