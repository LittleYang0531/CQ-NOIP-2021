#include <bits/stdc++.h>
using namespace std;
int sum,n,a[10001],ans;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i]*a[i];
		sum+=a[i];
	}
	ans=n*ans-sum*sum;
	cout<<ans;
	return 0;
} 
