#include<bits/stdc++.h>
#define purge AK
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;++i)
#define Rof(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int maxn=1e7;
int T,n,nxt[maxn+101];
bool v[maxn+101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	For(i,1,maxn+100)
		if(!v[i])
		{
			int t=i;
			bool f=0;
			while(t)
			{
				if(t%10==7)
				{
					f=1;
					break;
				}
				t/=10;
			}
			if(f)
				for(int j=i;j<=maxn+100;j+=i)
					v[j]=1;
		}
	Rof(i,maxn+99,1)
	{
		nxt[i]=nxt[i+1];
		if(!v[i+1])
			nxt[i]=i+1;
	}
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(v[n])
			cout<<"-1"<<'\n';
		else
			cout<<nxt[n]<<'\n';
	}
	return 0;
}
