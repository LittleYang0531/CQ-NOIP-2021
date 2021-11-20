#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
char nc() {
	if(p1==p2)p2=buf+fread(p1=buf,1,100000,stdin);
	if(p1==p2)return -1;
	return *p1++;
}
int read() {
	int x=0;
	char c=nc();
	while(c<'0'||c>'9')c=nc();
	for(; c>='0'&&c<='9'; c=nc())x=x*10+c-'0';
	return x;
}
int rd() {
	char c=nc();
	while(c<'0'||c>'9')c=nc();
	return c-'0';
}
const int MAXN=4e5+5;
#define w(x,y) ((x)*(m)+(y))
int d[MAXN],r[MAXN],cl[MAXN],v[MAXN],vst[MAXN],n,m,sign,ans;
//int ux,ul,ur,uy,uyl,uyr;
int xx,yy;
void work(int x,int y,int op,int col,int lv) {
	if(op==0||x<1||x>n||y<1||y>m)return;
	if(op==2)if(x!=xx&&y!=yy)return;
	vst[w(x,y)]=sign;
	if(v[w(x,y)]) {
		if(cl[w(x,y)]!=col&&v[w(x,y)]<=lv)ans++;
		return;
	}
	ans++;
	if(vst[w(x+1,y)]!=sign&&d[w(x,y)]==op)work(x+1,y,op,col,lv);
	if(vst[w(x-1,y)]!=sign&&d[w(x-1,y)]==op)work(x-1,y,op,col,lv);
	if(vst[w(x,y+1)]!=sign&&r[w(x,y)]==op)work(x,y+1,op,col,lv);
	if(vst[w(x,y-1)]!=sign&&r[w(x,y-1)]==op)work(x,y-1,op,col,lv);
}
//set<int>s1[200005],s2[200005];
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=read();
	for(int _t=1; _t<=t; _t++) {
		memset(cl,0,sizeof(cl));
		memset(v,0,sizeof(v));
		memset(vst,0,sizeof(vst));
		n=read();
		m=read();
//		for(int i=1; i<=n||i<=m; i++) {
//			s1[i].clear();
//			s2[i].clear();
//		}
		int q=read();
		for(int i=1; i<=n; i++)for(int j=1; j<m; j++)r[w(i,j)]=rd();
		for(int i=1; i<n; i++)for(int j=1; j<=m; j++)d[w(i,j)]=rd();
//		for(int i=1; i<=n; i++)for(int j=1; j<=m; j++) {
//				if(j==1||j==m||r[w(i,j)]!=2||r[w(i,j-1)]!=2)s2[i].insert(j);
//				if(i==1||i==n||d[w(i,j)]!=2||d[w(i-1,j)]!=2)s1[j].insert(i);
//			}
		for(int i=1; i<=q; i++) {
			int col=read(),lv=read(),x=read(),y=read();
			cl[w(x,y)]=col;
			v[w(x,y)]=lv;
			sign++;
			ans=0;
			xx=x;
			yy=y;
//			s1[y].insert(x);
//			set<int>::iterator a1=s1[y].find(x),a2;
//			if(x!=n&&d[w(x,y)]==2) {
//				a2=a1;
//				a2++;
//				int p=*a2;
//				if((cl[w(p,y)]!=col&&v[w(p,y)]<=lv)||v[w(p,y)]==0)ans++;
//				ans+=p-x-1;
//			}
//			if(x!=1&&d[w(x-1,y)]==2) {
//				a2=a1;
//				a2--;
//				int p=*a2;
//				if((cl[w(p,y)]!=col&&v[w(p,y)]<=lv)||v[w(p,y)]==0)ans++;
//				ans+=x-p-1;
//			}
//			s2[x].insert(y);
//			a1=s2[x].find(y);
//			if(y!=m&&r[w(x,y)]==2) {
//				a2=a1;
//				a2++;
//				int p=*a2;
//				if((cl[w(x,p)]!=col&&v[w(x,p)]<=lv)||v[w(x,p)]==0)ans++;
//				ans+=p-y-1;
//			}
//			if(y!=1&&r[w(x,y-1)]==2) {
//				a2=a1;
//				a2--;
//				int p=*a2;
//				if((cl[w(x,p)]!=col&&v[w(x,p)]<=lv)||v[w(x,p)]==0)ans++;
//				ans+=y-p-1;
//			}
			work(x+1,y,d[w(x,y)],col,lv);
			work(x-1,y,d[w(x-1,y)],col,lv);
			work(x,y+1,r[w(x,y)],col,lv);
			work(x,y-1,r[w(x,y-1)],col,lv);
			printf("%d\n",ans);
		}
	}
	return 0;
}
