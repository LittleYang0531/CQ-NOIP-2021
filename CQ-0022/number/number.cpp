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
using namespace std;
char buf[1<<19],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<19,stdin),(p1==p2))?EOF:*p1++)
int read(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	if(f)x=-x;return x;
}
const int N=1e7+10000;
int v[N],p[N],m,t;
bool solve(int x){
	while(x>0){
		if(x%10==7)return 0;
		x/=10;
	}return 1;
}
signed main(){
//	system("fc number4.out number4.ans");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(_R int i=1;i<N;++i)if(!v[i]){
		if(!solve(i)){for(_R int j=i+i;j<N;j+=i)v[j]=1;}
		else p[++m]=i;
	}
	t=read();
	while(t--){
		int x=read(),i;
		i=lower_bound(p+1,p+m+1,x)-p;
		if(p[i]!=x)puts("-1");
		else printf("%d\n",p[i+1]);
	}
	return 0;
}

