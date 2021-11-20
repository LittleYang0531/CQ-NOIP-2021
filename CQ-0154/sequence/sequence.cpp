#include<bits/stdc++.h>
#define inl inline
typedef long long ll;
using namespace std;
const int maxn=35,maxm=105,mod=998244353;
int n,m,K,ans,a[maxm],er[maxm];
inl int Read()
{
	int s=0,f=1; char c;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s*f;
}
void DFS(int dep,int x,int val)
{
	if(dep>n)
	{
		int sum=0;
		for(;x;x>>=1) sum+=(x&1);
		if(sum<=K) ans=(ans+val)%mod;
		return;
	}
	for(int i=0;i<=m;++i) DFS(dep+1,x+er[i],(ll)val*a[i]%mod);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=Read(); m=Read(); K=Read();
	for(int i=0;i<=m;++i) a[i]=Read();
	er[0]=1; for(int i=1;i<=m;++i) er[i]=er[i-1]*2;
	DFS(1,0,1); printf("%d\n",ans);
	return 0;
}
