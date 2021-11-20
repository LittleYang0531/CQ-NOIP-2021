#include<bits/stdc++.h>
#define re register
#define int long long 
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[10002],b[10002],ans,f[402][602],pre[402][602],c[10002],d[10002],m;
inline void gmn(re int &x,re int y){if(y<x)x=y;}
inline void Get(re int x,re int y){
	if(x==0)return;
	if(pre[x][y]==1)c[x]=1,Get(x-1,y);
	else c[x]=0,Get(x-1,y-b[x]);
}
inline void calc(re int x){
	memset(f,0x3f,sizeof(f));
	re int s=0,L=a[1]-x,R=a[n]-x;f[0][0]=L*L+R*R;
	for(re int i=0;i<m;++i){
		for(re int j=0;j<=s;++j){
			re int x=f[i][j]+(L+j+b[i+1])*(L+j+b[i+1]);
			if(x<f[i+1][j+b[i+1]])f[i+1][j+b[i+1]]=x,pre[i+1][j+b[i+1]]=0;
			x=f[i][j]+(R-(s-j)-b[i+1])*(R-(s-j)-b[i+1]);
			if(x<f[i+1][j])f[i+1][j]=x,pre[i+1][j]=1;
		}
		s+=b[i+1];
	}
	re int mn=1e18,pos=0;
	for(re int i=0;i<=s;++i)if(f[m][i]<mn)mn=f[m][i],pos=i;
	Get(m,pos);
	L=a[1],d[1]=L;re int nn=1;
	for(re int i=1;i<=m;++i)if(c[i]==0)++nn,d[nn]=d[nn-1]+b[i];
	for(re int i=0;i<n-m-1;++i)++nn,d[nn]=d[nn-1];
	for(re int i=m;i;--i)if(c[i])++nn,d[nn]=d[nn-1]+b[i];
	s=0;
	re int s1=0;
	for(re int i=1;i<=n;++i)s+=d[i]*d[i],s1+=d[i];
	ans=min(ans,s*n-s1*s1);
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read(),ans=1e18;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<n;++i)b[i]=a[i+1]-a[i];
	sort(b+1,b+n),reverse(b+1,b+n);
	m=n-1;
	while(m&&!b[m])--m;
	for(re int i=a[1];i<=a[n];++i)calc(i);
	printf("%lld",ans);
}

