#include<bits/stdc++.h>
#define _R register
#define _I inline
#define ll long long
#define mod 998244353
#define eps 1e-4
#define INF 0x3f3f3f3f3f3f3f3f
#define memset(x,y) memset(x,y,sizeof(x))
#define memcpy(x,y) memcpy(x,y,sizeof(x))
#define lowbit(i) (i&(-i))
#define int ll
#define ull unsigned long long
using namespace std;
//char buf[1<<19],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<19,stdin),(p1==p2))?EOF:*p1++)
int read(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	if(f)x=-x;return x;
}
const int N=10005;
int n,a[N],b[N];
vector<int>v[N];
int sq(int x){return x*x;}
int cal(){
	int a0=0,ret=0;
	for(_R int i=1;i<=n;++i)a0+=b[i];
	for(_R int i=1;i<=n;++i)ret=(ret+n*b[i]*b[i]);
	return ret-a0*a0;
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();for(_R int i=1;i<=n;++i)a[i]=b[i]=read();int ans=cal();
	if(n==4){
		b[1]=a[1];b[2]=a[1]+a[4]-a[3];b[3]=a[1]+a[4]-a[2];b[4]=a[4];ans=min(ans,cal());
		b[1]=a[1];b[2]=a[1]+a[3]-a[2];b[3]=a[2]+a[4]-a[3];b[4]=a[4];ans=min(ans,cal());
		b[1]=a[1];b[2]=a[1]+a[4]-a[3];b[3]=a[1]+a[4]-a[2];b[4]=a[4];ans=min(ans,cal());
		b[1]=a[1];b[2]=a[1]+a[3]-a[2];b[3]=a[2]+a[4]-a[3];b[4]=a[4];ans=min(ans,cal());
		cout<<ans<<"\n";return 0;
	}
	while(1){
		int mn=INF,id=0;
		for(_R int i=2;i<n;++i){
			int tmp=b[i],bj;b[i]=b[i-1]+b[i+1]-b[i];
			if(b[i]==tmp)continue;
			bj=cal();if(bj<=mn)mn=bj,id=i;
			b[i]=tmp;
		}
		if(mn>=ans)break;
		ans=mn;b[id]=b[id-1]+b[id+1]-b[id];
	}cout<<ans;
	return 0;
}
//5 1 11 111 1111 11111
