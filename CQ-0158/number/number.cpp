#include<bits/stdc++.h>
#define R register
int T;
const int maxx=10000005;
int okey[maxx],Next[maxx];
const int n=10000001;
inline void init(void) {
	for(R int i=1; i<=n; ++i) {
		R int p=i,flag=0;
		while(p) {
			if(p%10==7) {
				flag=1;
				break;
			}
			p/=10;
		}
		if(flag&&!okey[i]) {
			for(R int j=i; j<=n; j+=i) {
				okey[j]=1;
			}
		}
	}
	R int Last=10000001;
	for(R int i=n; i>=1; --i) {
		Next[i]=Last;
		if(!okey[i]) {
			Last=i;
		}
	}
	return ;
}

const int maxbuf=1<<20;
char buf[maxbuf],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,maxbuf,stdin),p1==p2)?0:*p1++)
inline int read(void) {
	R int x=0,flag=0;
	char c=GC;
	while(c<'0'||c>'9') {
		if(c=='-')flag=1;
		c=GC;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0',c=GC;
	}
	return flag?-x:x;
}


int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	scanf("%d",&T);
	T=read();
	init();
	while(T--) {
		R int x;
//		scanf("%d",&x);
		x=read();
		if(okey[x]) {
			printf("-1\n");
		} else {
			printf("%d\n",Next[x]);
		}
	}
	return 0;
}
