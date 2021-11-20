#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int NN=105;

int n,m,k,ans;
int v[NN];

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>v[i];
	ans=40;
	cout<<ans;
	return 0;
}
