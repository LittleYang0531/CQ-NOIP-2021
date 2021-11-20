#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
const int N=1e7+10;
int t;
int p[N],cnt;
bool g[N];
void dfs(int ans,int d,bool f)
{
	if(d==6)
	{
		if(f)
		{
			for(int i=0;i<=9;i++)
			p[++cnt]=ans*10+i,g[ans*10+i]=1;
		}
		else
		p[++cnt]=ans*10+7,g[ans*10+7]=1;
		return;
	}
	for(int i=0;i<=9;i++)
	{
		if(f||i==7)
		dfs(ans*10+i,d+1,1);
		else
		dfs(ans*10+i,d+1,0);
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	dfs(0,0,0);
	for(int i=2;i<N/7;i++)
	{
		int j=1;
		while(i*p[j]<N)g[i*p[j++]]=1;
	}
//	int cnt2=0;
//	for(int i=9999991;i<N;i++)
//		if(g[i]==1)
//		cout<<i<<" ";
//		cnt2++;
//	cout<<cnt2<<" "<<N;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		if(g[x]==1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		x++;
		while(g[x]==1)x++;
		cout<<x<<endl;
	}
	return 0;
}
