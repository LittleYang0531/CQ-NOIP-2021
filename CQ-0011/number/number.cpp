#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
const int maxn = 1e7+1000;
char s[maxn],u[maxn];int ty[maxn];
void SHAI(int n) {
	for(int i=2;i<=n;i++) {
		u[i]=u[i/10]|(i%10==7);
		if(!s[i]&&u[i]) for(int j=i;j<=n;j+=i) s[j]=1;
	}
	int lst=0;
	for(int i=n;i;i--) {
		ty[i]=lst;
		if(!s[i]) lst=i;
	}
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	SHAI(10000600);
	int csa=read(),n;
	while(csa--) {
		n=read();
		if(s[n]) cout<<-1<<'\n';
		else cout<<ty[n]<<'\n';
	}
	return 0;
}
