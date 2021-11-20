#include<bits/stdc++.h>
#define purge AK
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;++i)
#define Rof(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
int n,a[10001],ac;
ll sum,psum,ans=1e18;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	For(i,1,n)
	{
		cin>>a[i];
		sum+=a[i];
		psum+=a[i]*a[i];
	}
	if(n<=20)
	{
		For(i,1,1e6)
		{
			int x=rand()%(n-2)+2;
			a[x]=a[x-1]+a[x+1]-a[x];
			sum=psum=0;
			For(i,1,n)
			{
				sum+=a[i];
				psum+=a[i]*a[i];
			}
			ans=min(ans,psum*n-sum*sum);
		}
	}
	else
	{
		ac=(a[1]+a[n]+1)/2;
		int pos=lower_bound(a+1,a+n+1,ac)-a-1;
		For(i,2,n-1)
		{
			Rof(j,pos,2)
			{
				int t=a[j-1]+a[j+1]-a[j];
				if((psum+t*t-a[j]*a[j])*n-(sum+t-a[j])*(sum+t-a[j])<psum*n-sum*sum)
				{
					sum+=t-a[j];
					psum+=t*t-a[j]*a[j];
					a[j]=a[j-1]+a[j+1]-a[j];
				}
			}
			For(j,pos+1,n-1)
			{
				int t=a[j-1]+a[j+1]-a[j];
				if((psum+t*t-a[j]*a[j])*n-(sum+t-a[j])*(sum+t-a[j])<psum*n-sum*sum)
				{
					sum+=t-a[j];
					psum+=t*t-a[j]*a[j];
					a[j]=a[j-1]+a[j+1]-a[j];
				}
			}
			ans=min(ans,psum*n-sum*sum);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
