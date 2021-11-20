#include<bits/stdc++.h>
using namespace std;
long long n,a[10001],s1,s2,ans=19440000000000,f[10001];
void dfs(long long equal)
{
	bool f=0;
	for(int i=2;i<n;i++)
	{
		if(abs(a[i]*n-equal)>abs((a[i-1]+a[i+1]-a[i])*n-(equal-(2*a[i]-a[i-1]-a[i+1]))))
		{
			int xx=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			f=1;
			dfs(equal-(2*xx-a[i-1]-a[i+1]));
			a[i]=xx;
		}
	}
	if(!f)
	{
		long long xx;
		for(int i=1;i<=n;i++)
		{
			xx+=abs(equal-a[i]*n)*abs(equal-a[i]*n);
		}
		if(ans>xx/n)
		ans=xx/n;
		//cout<<equal<<endl;
		//for(int i=1;i<=n;i++)
		//cout<<a[i]<<" ";
		//cout<<endl;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s1+=a[i];
	}
	dfs(s1);
	cout<<ans;
	return 0;
}
