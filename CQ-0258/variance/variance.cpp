#include<bits/stdc++.h>
using namespace std;
namespace helloioi{
#define LL long long
#define db double 
#define f(a,b,i) for(int i=a;i<=b;i++)
#define f_(a,b,i) for(int i=a;i>=b;i--)
	template<typename T>void read(T &x){
		x=0;
		int f=0;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=1;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}
		x=f?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace helloioi;

#define N 1005

int n;
int aa[N];

int ans=0x3fffffff;

typedef basic_string<int> inting;

map<inting,int> vis;

void dfs(inting a){
//	f(0,n-1,i)cout<<a[i]<<" ";
//	cout<<endl;
//	_sleep(100);
	if(vis[a])return;
	int anss=0,sum1=0,sum2=0;
	f(0,n-1,i)sum1+=a[i]*a[i],sum2+=a[i];
	anss=sum1*n-sum2*sum2;
	vis[a]=anss;
	ans=min(anss,ans);
	int t;
	f(1,n-2,i){
		t=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		dfs(a);
		a[i]=t;	
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	f(1,n,i)read(aa[i]);
	inting a;
	f(1,n,i)a+=aa[i];
	dfs(a);
	printf("%d\n",ans);
	return 0;
}
