#include<bits/stdc++.h>
using namespace std;
const int N=1e7+101,M=1e7;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

int p[N],is[N],pos[N],cnt;
signed main() {
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	//freopen("number4.in","r",stdin);
	//freopen("T1.out","w",stdout);
	
	//double st=clock();
	
	for(int i=1;i<=M;++i) {
		int k=i,flag=0;
		if(is[i]) continue;
		while(k) {
			int h=k%10;
			if(h==7) {
				flag=1; break;
			}
			k/=10;
		}
		if(!is[i]&&flag==0) {
			p[++cnt]=i;
			pos[i]=cnt;
		}
		if(flag==1) for(int j=1;j<=M;++j) {
			if(i*j>M) break;
			is[i*j]=1;
		}
	}
	p[++cnt]=10000001;
	p[10000001]=cnt;
	
//	cout<<cnt<<'\n';
//	for(int i=1;i<=cnt;++i) cout<<p[i]<<" ";
	
	int T=read();
	while(T--) {
		int x=read();
		if(is[x]==1) {
			printf("-1\n");
		}
		else {
			//int g=upper_bound(p+1,p+cnt+1,x)-p;
			int g=p[pos[x]+1];
			printf("%d\n",g);
		}
	}
	
	//double en=clock();
	//printf("%.3lf",en-st);
	return 0;
}
