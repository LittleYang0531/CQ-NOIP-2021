#include<bits/stdc++.h>
using namespace std;
#define re register int
#define LL long long
#define gc() getchar()
inline int rd()
{
	int x=0,f=1;
	char c=gc();
	for(; c<'0'||c>'9'; c=gc())if(c=='-')f=0;
	for(; '0'<=c&&c<='9'; c=gc())x=(x<<1)+(x<<3)+c-'0';
	return f?x:-x;
}
const int N=1e7+7;
int mk[N],a[N],cnt;
inline bool chk(int x)
{
	while(x)
	{
		int t=x%10;
		x/=10;
		if(t==7)return 1;
	}
	return 0;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=10000001;
	for(re i=1;i<=n;++i)
	{
		if(!mk[i] && chk(i))
			for(re j=1;i*j<=n;++j)
				mk[i*j]=1;
		
		if(!mk[i])a[++cnt]=i;
	}
	int T=rd(), x, t;
	while(T--)
	{
		x=rd();
		if(mk[x])puts("-1");
		else
		{
			t=upper_bound(a+1,a+1+cnt,x)-a;
			printf("%d\n", a[t]);
		}
	}
}
