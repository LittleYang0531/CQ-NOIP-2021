#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[500],sum=1;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	sum*=n*m*k;
	for(int i=0;i<=m;i++)
	{cin>>f[i];
	sum=sum*f[i]%998244353;}
	cout<<sum<<endl;//±©Á¦³öÆæ¼£!
	return 0;
}
