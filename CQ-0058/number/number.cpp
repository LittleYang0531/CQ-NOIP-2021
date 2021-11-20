#include<bits/stdc++.h>
#define ll long long
#define getchar gc
using namespace std;
const int Mxdt=1e5;
inline char gc() {
	static char buf[Mxdt+5],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}

inline int Rd() {
	int s=0; char fl=0,c=getchar();
	while(c<'0'||c>'9') fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s; 
}

const int N=1e7+15;

int bj[N];
int num=0,a[N];

inline void Init(int n) {
	int lim=1e6;
	for(int i=0; i<=lim; ++i) {
		int v=(i<<3)+(i<<1);
		if(bj[i]) {
			for(int j=0; j<10; ++j) bj[v+j]=1;
		}
		else bj[v+7]=1;
//		for(int j=0; j<10; ++j) bj[v+j]=bj[i]|(j==7);
//		bj[i]|=bj[i/10]|(i%10==7);
	}
	for(int i=(int)sqrt(n); i>1; --i) {
		int now=bj[i];
		for(int j=i; 1ll*i*j<=n; ++j) bj[i*j]|=now|bj[j];
	}
	for(int i=1; i<=n; ++i) 
		if(!bj[i]) a[++num]=i,bj[i]=num;
		else bj[i]=0;
}

int tmpx[N];

int main() {
//	system("fc number.out number4.ans");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=Rd(); int lim=0;
	for(int i=1; i<=T; ++i) lim=max(lim,tmpx[i]=Rd());
	
	if(lim<=200000) Init(200005);
	else Init(1e7+2);
	
	for(int i=1; i<=T; ++i) {
		int x=tmpx[i];
		if(!bj[x]) puts("-1");
		else printf("%d\n",a[bj[x]+1]);
	}
	return 0;
}

