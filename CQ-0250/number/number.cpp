#include<bits/stdc++.h>
using namespace std;
int read() {
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
void put(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) put(x/10);
	putchar(x%10+'0');
}
int T,x,cnt,ans[763410];
bitset<10010001>vis;

bool check(int x) {
	int k;
	while(x) {
		k=x%10,x/=10;
		if(k==7) return 1;
	}return 0;
}
int find(int x) {
	int l=1,r=cnt,res;
	while(l<=r) {
		int mid=l+r>>1;
		if(ans[mid]>x) res=ans[mid],r=mid-1;
		else l=mid+1;
	} return res;
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(register int i=1;i<=10000010;++i) {
		if(vis[i]) continue;
		if(check(i)) for(register int j=i;j<=10000010;j+=i) vis[j]=1;
		else ans[++cnt]=i;
	}
	T=read();
	while(T--) {
		x=read();
		put(vis[x]?-1:find(x));
		putchar('\n');
	}
	return 0;
}
