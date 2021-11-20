#include<bits/stdc++.h>
using namespace std;
unsigned long long  n,a[31],m,k,v[101],minn,cnt,ans;
void dfs();
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	cin>>v[i];
	for(int i=1;i<=n;i++)
	{
		ans*=v[i];
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
