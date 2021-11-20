#include <bits/stdc++.h>
using namespace std;
bool ppp;
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int T=200005,X=10000005;
int t,n,ma,mma,ans[T<<1],b[T<<1],tot;
int cnt,hed[X],nxt[T<<1],id[T<<1];
bool unok[X];
struct node {
	int x,id;
//	bool operator < (const node &b) const {
//		return x<b.x;
//	}
}a[T];
bool cmp(node a,node b) {
	return a.x<b.x;
}
bool check1(int x) {
	while(x) {
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
bool pppp;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	cerr<<(&ppp-&pppp)/1024.0/1024.0<<endl;
	t=read();
	for(int i=1;i<=t;++i)
		a[i].x=read(),a[i].id=i,ma=max(a[i].x,ma);
	sort(a+1,a+1+t,cmp);
	if(ma<=200000) mma=200002;
	else mma=10000001;
	for(int i=7;i<=mma;++i)
		if(check1(i)) for(int j=i;j<=mma;j+=i) unok[j]=1;
	for(int i=1;i<=t;++i) nxt[++cnt]=hed[a[i].x],id[cnt]=a[i].id,hed[a[i].x]=cnt;
	for(int i=1;i<=mma;++i) {
		if(unok[i]) for(int j=hed[i];j;j=nxt[j]) ans[id[j]]=-1;
		else {
			for(int j=1;j<=tot;++j) ans[b[j]]=i;
			tot=0;
			for(int j=hed[i];j;j=nxt[j]) b[++tot]=id[j];
		}
	}
	for(int i=1;i<=t;++i) write(ans[i]),putchar('\n');
	return 0;
}
/*
4
6
33
69
300

8
36
80
-1

5
90
99
106
114
169

92
100
109
-1
180
*/
