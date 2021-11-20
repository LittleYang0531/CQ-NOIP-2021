#include<bits/stdc++.h>
#define _R register
#define _I inline
#define ll long long
#define mod 998244353
#define eps 1e-4
#define INF 0x3f3f3f3f
#define memset(x,y) memset(x,y,sizeof(x))
#define memcpy(x,y) memcpy(x,y,sizeof(x))
#define lowbit(i) (i&(-i))
#define int ll
using namespace std;
//char buf[1<<19],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<19,stdin),(p1==p2))?EOF:*p1++)
int read(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	if(f)x=-x;return x;
}
const int N=105;
int n,m,K,ans,val[N],c[N][N];
int f[33][105][33][33];
void qmod(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int ct(int s){
	int ret=0;
	for(_R int i=0;i<=10;++i)ret+=((s>>i)&1);return ret;
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read()+1;K=read();
	for(_R int i=1;i<=m;++i)val[i]=read();
	for(_R int i=0;i<=100;++i)c[i][0]=c[i][i]=1;
	for(_R int i=1;i<=100;++i)for(_R int j=1;j<=i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	f[0][0][0][0]=1;
	for(_R int i=0;i<=n;++i)for(_R int j=0;j<=m;++j)
		for(_R int k=0;k<=i;++k)for(_R int s=0;s<=31;++s)if(f[i][j][k][s]){
			if(i==n){
				if(k+ct(s)<=K)qmod(ans,f[i][j][k][s]);
				continue;
			}
			int t=(s>>1),pw=f[i][j][k][s];
			for(_R int o=i;o<=n;++o){
				if(k+(s&1)<=K&&j+1<=m&&t<=31){
					qmod(f[o][j+1][k+(s&1)][t],1ll*pw*c[o][i]%mod);
				}
				++t;pw=1ll*pw*val[j+1]%mod;
			}
		}
	cout<<ans;
	return 0;
}
/*
5 3 1
25 1
*/
