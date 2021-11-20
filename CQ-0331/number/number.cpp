#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
ll a[N],book[N],bell[N*7];
bool sun(ll s)
{
	int sn,k=0;
	while(s>0)
	{
		sn=(int)s%10;
		s/=10;
		if(sn==7)
			return 1;
	}
	return 0;
}
void med()
{
	for(ll i=1,j=1;j<=N;i++,j++)
	{
		if(bell[j])
			i--;
		if(!bell[j])
		{
			a[i]=j;
			if(sun(a[i]))
			{
				i--;
				for(ll l=1;l<=N/j+1;l++)
				bell[j*l]=1;
			}
		}
	}
	for(ll i=1;i<=N;i++)
	book[a[i]]=i;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ll T;
	cin>>T;
	med();
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		ll samd=book[n];
		if(!samd)
		{
			puts("-1");
			continue;
		}
		else
		printf("%d\n",a[samd+1]);
	}
	return 0;
}
