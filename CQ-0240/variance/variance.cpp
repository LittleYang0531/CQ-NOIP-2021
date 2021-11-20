#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,a[N];
double f[N];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	double ave=0;
	for(int i=1;i<=n;i++)
		ave+=a[i];
	ave=1.0*ave/n;
	double res=0;
	
	for(int i=1;i<=n;i++)
		res+=1.0*(a[i]-ave)*(a[i]-ave);
	for(int i=1;i<=n;i++)
		f[i]=res;
	for(int i=2;i<n;i++)
	{
		f[i]=res;
		f[i]=min(f[i],f[i-1]+1.0*(a[i-1]+a[i+1]-2*a[i])/n-2*(a[i-1]+a[i+1]-2*a[i]));
	}
	double ans=1e9;
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]);
	cout<<ans*n<<endl;
	return 0;
}
