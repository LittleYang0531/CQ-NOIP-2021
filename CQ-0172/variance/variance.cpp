#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<unordered_map>
using namespace std;
char buf[1<<23],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
int n;
int tp[100005];
long long fpow[20];
const int mod=41;
unordered_map<long long,bool>ha;
int minn=0x7fffffff;
void dfs(long long x)
{
	if(ha[x])return ;
	if(clock()*1.0/CLOCKS_PER_SEC>0.8)
	{
		cout<<minn;
		exit(0);
	}
	long long _=x;
	ha[x]=true;
	int sum=0;
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		tp[i]=x%mod;
		x/=mod;
		sum+=tp[i];
		cnt+=tp[i]*tp[i];
	}
	x=_;
	cnt=cnt*n-sum*sum;
	minn=min(minn,cnt);
	for(int i=2;i<n;++i)
	{
		int now=tp[i-1]+tp[i+1]-tp[i];
		dfs(x+(now-tp[i])*fpow[i-1]);
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	fpow[0]=1;
	for(int i=1;i<=11;++i)fpow[i]=fpow[i-1]*mod;
	rd(n);
	long long tp=0;
	for(int i=1;i<=n;++i)
	{
		int x;
		rd(x);
		tp=tp*mod+x;
	}
	dfs(tp);
	cout<<minn;
	return 0;
}
